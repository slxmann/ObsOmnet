//
// Copyright (C) 2010-2013 Javier Armendariz Silva, Naiara Garcia Royo, Felix Espina Antolin
// Copyright (C) 2010-2013 Universidad Publica de Navarra
//
// This file is part of OBSModules.
//
// OBSModules is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OBSModules is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with OBSModules.  If not, see <http://www.gnu.org/licenses/>.
//

#include "OBS_BurstSender.h"
#include "inet/networklayer/common/InterfaceTable.h"
#include "inet/networklayer/common/NetworkInterface.h"

#include "inet/networklayer/ipv4/Ipv4InterfaceData.h"

using namespace inet;

namespace inet {  class NetworkInterface; }

Define_Module(OBS_BurstSender);


OBS_BurstSender::~OBS_BurstSender(){
    free(horizon);
    free(colour);
    //Clean horizon vector
    int i;
    for(i=0;i<numLambdas;i++){
      delete horizonVec[i];
    }
}

void OBS_BurstSender::initialize(int stage){
   int i;
   if(stage == inet::INITSTAGE_LOCAL)
   {
       //Pick up parameters from .ned
       numLambdas = par("numLambdas");
       dataRate = par("dataRate");

       BCPSize = par("BCPSize");
       guardTime = par("guardTime");

       maxSchedBurstSize = par("maxSchedBurstSize");

       int maxSchedBurstSizeInBits = maxSchedBurstSize*8;
       scheduledBurst.setMaxSize(maxSchedBurstSizeInBits);
       scheduledBurst.setMaxElems((int)par("maxSchedBurstElems"));

       testing = par("testing");

       control_is_busy = false;

       //Initialize colours map
       const char* colourString = par("colours");

       colour = (int*)calloc(numLambdas,sizeof(int));
       int j;

       if(strcmp(colourString,"") != 0){
          omnetpp::cStringTokenizer tokenizer(colourString);

          for(j=0;j<numLambdas;j++)
             colour[j] = atoi(tokenizer.nextToken());
       }else{
          for(j=0;j<numLambdas;j++)
             colour[j] = j;
       }
       /*
        * End of 'colour' section
        */

       //Initialize horizon array with all 0's
       horizon = (simtime_t*)calloc(numLambdas,sizeof(simtime_t));
       horizonVec.reserve(numLambdas);

       for(i=0;i<numLambdas;i++){
          horizon[i] = 0;
          char buf[32];
          sprintf(buf, "horizonVector{%d}", i);
          horizonVec.push_back(new cOutVector(buf));
          WATCH(horizon[i]);
       }

       waitingBCP.setName("waitingBCPs");

       burstSent = 0;
       burstDroppedByOffset = 0;
       burstDroppedByQueue = 0;
       burstRecv = 0;
       WATCH(burstRecv);
       WATCH(burstDroppedByOffset);
       WATCH(burstDroppedByQueue);

       burstSize.setName("burstSize");
   }
   // 'testing' flag allows this module to work as a standalone getModule(independent of BurstAssembler/EdgeNode)
   // If testing is false prevents this module to try to register its interface
//       if(!testing)
//           networkInterface = registerInterface(dataRate);
   if(stage == inet::INITSTAGE_NETWORK_INTERFACE_CONFIGURATION)
       netIftConfiguration(dataRate);

}
//void OBS_BurstSender::configureNetworkInterface()
//{
//    iftConfiguration(dataRate);
//
//
//}
void OBS_BurstSender::netIftConfiguration(double dataRate)
{
//    ASSERT(networkInterface == nullptr);
    networkInterface = getContainingNicModule(this);
    // MTU: typical values are 576 (Internet de facto), 1500 (Ethernet-friendly),
    // 4000 (on some point-to-point links), 4470 (Cisco routers default, FDDI compatible)
    networkInterface->setMtu(1500);
    networkInterface->setDatarate(dataRate);
    inet::InterfaceToken token(0, getSimulation()->getUniqueNumber(), 64);
    networkInterface->setInterfaceToken(token);
        // capabilities
    networkInterface->setMulticast(true);
    networkInterface->setPointToPoint(true);
}


// Code taken from INET Router module. Register the OBS interface into the interface table among other things
//inet::NetworkInterface* OBS_BurstSender::registerInterface(double datarate) {
//    auto interfaceTable = inet::getModuleFromPar<inet::InterfaceTable>(par("interfaceTableModule"), this);
//    if (!interfaceTable)
//        throw omnetpp::cRuntimeError("(OBS_BursrSender.cc): Warning: InterfaceTable not found");
//
//    inet::NetworkInterface  *e = new inet::NetworkInterface();
////    inet::NetworkInterface *e = omnetpp::check_and_cast<inet::NetworkInterface*>(getSubmodule("ppp[sizeof(pppIO)]"));
//
//    std::string name = getFullPath(); // this returns EdgeNodeExample.edge1.obs.assembler.sender
////    cModule *namez  getFullPath();
//
////    std::string name2 = omnetpp::check_and_cast()and_cast<cModule *>(name);
////    std::string name = inet::getContainingNode(this)->getFullName();
////    name.erase(std::remove_if(name.begin(), name.end(),
////              [](char c) { return !isalnum(c); }), name.end());
////    cModule* edgeNode = inet::getContainingNode(this);
////    std::string ifaceName = namez->getName(); // "edge1"
//
//    e->setInterfaceName("obs1");
//    e->setName(name.c_str());;
//
//    // data rate
//    e->setDatarate(datarate);
//
//    // generate a link-layer address to be used as interface token for IPv6
//    inet::InterfaceToken token(0, getSimulation()->getUniqueNumber(), 64);
//    e->setInterfaceToken(token);
//
//    // MTU: typical values are 576 (Internet de facto), 1500 (Ethernet-friendly),
//    // 4000 (on some point-to-point links), 4470 (Cisco routers default, FDDI compatible)
//    e->setMtu(1500);
//
//    // capabilities
//    e->setMulticast(true);
//    e->setPointToPoint(true);
//
//
//    // add
////    inet::IInterfaceTable *ift = InterfaceTableAccess().getIfExists();
////    ift->addInterface(e);
////    if (interfaceTable)
//
//    interfaceTable->addInterface(e);
//
//    cModule *asmblr = getParentModule();            // OBS_BurstAssembler
//    cModule *edgeIface = asmblr->getParentModule(); // OBS_EdgeInterface
//
//    int inG  = edgeIface->gate("upperLayerIn")->getId();
//    int outG = edgeIface->gate("upperLayerOut")->getId();
//    if (inG == -1 || outG == -1)
//        throw omnetpp::cRuntimeError(" (OBS_BurstSender): Missing upperLayerIn/out gate in OBS_EdgeInterface!");
//
//    e->setNodeInputGateId(inG);
//    e->setNodeOutputGateId(outG);
//
////    if (!node->hasGate("upperLayerIn") || !node->hasGate("upperLayerOut")) {
////        throw omnetpp::cRuntimeError("Node-level OBS gates missing!");
////    }
//    EV_INFO << "Registering network interface" << EV_FIELD(e) << EV_FIELD(inG) << EV_FIELD(outG) << EV_ENDL;
//
//    EV_INFO << "Registered OBS interface ‘" << e->getInterfaceName()
//                << "’ as id=" << e->getInterfaceId()
//                << " (inGateId=" << inG << ", outGateId=" << outG << ")\n";
//    return e;
//
//}

void OBS_BurstSender::handleMessage(omnetpp::cMessage *msg){
   //declaration of variables used on every condition
   OBS_BurstSenderInfo *info;

   if(!(msg->isSelfMessage())){ // Receive a burst from OBS_BurstAssembler

         //Cast the message to OBS_Burst
         OBS_Burst *burst = omnetpp::check_and_cast<OBS_Burst *> (msg);

         burstSize.record(burst->getByteLength()); // Record burst length and update burst counter
         burstRecv++;

         int wl,pos=0; //wl = selected channel, pos = position of the burst into scheduledBurst.

         wl = findNearestHorizon(); //returns the best horizon to send current burst

         //Now insert burst Id
         burst->setSenderId(getId());

         OBS_BurstSenderInfo *myinfo = new OBS_BurstSenderInfo();

//         omnetpp::cMsgPar *wrapper = new omnetpp::cMsgPar("BurstSenderInfo");
//         wrapper->setPointerValue(myinfo);  // Store myinfo as a void* in the wrapper


         // Fill myinfo (OBS_BurstSenderInfo) fields
         myinfo->setBurstifierId(burst->getBurstifierId());
         myinfo->setNumSeq(burst->getNumSeq());
         myinfo->setAssignedLambda(wl);
         OBS_BurstifierInfo *lInfo = (OBS_BurstifierInfo *) burst->removeControlInfo();
         myinfo->setLabel(lInfo->getLabel());
         delete lInfo;

         //create the automessage "schedule the bcp_ini send"
         omnetpp::cMessage *ctlMsg=new omnetpp::cMessage("Sched");


         //Enter here if the burst can be sent just when channel wl sets free. (there will be enough time to send the bcp and wait the max offset time)
         if(horizon[wl] - burst->getMaxOffset() >= omnetpp::simTime()){ // Note the =. It means we could schedule a burst at the same value than the horizon value
            //Store into ScheduledBurst
            pos = scheduledBurst.insertBurst(burst, horizon[wl]);
            if(pos == -1){ // scheduledBurst is full. Drop this burst!
               delete msg;
               delete ctlMsg;
               burstDroppedByQueue++;
               return;
            }
            //Insert Bust position on scheduledBurst queue
            myinfo->setBurstId(pos);

            // Attach the wrapper to the message instead of myinfo
            ctlMsg->setControlInfo(myinfo);  // Now compatible with cObject*
            // Fill ctlMsgs fields (this message will travel across all Sender's states)
//          ctlMsg->setControlInfo(myinfo);
            ctlMsg->setKind(OBS_SCHEDULE_BCP); //Set to step 1: Schedule BCP

        //Schedule BCP send
            scheduleAt(horizon[wl] - burst->getMaxOffset(), ctlMsg);

            //update horizon value
            horizon[wl] = horizon[wl] + (burst->getBitLength()/dataRate) + guardTime;

        //Register horizon value
        horizonVec[wl]->record(horizon[wl]);

         }
         else{ //You can send the BCP inmediately so that the Burst will be sent within maxOffset
            //Store into ScheduledBurst
            pos = scheduledBurst.insertBurst(burst, omnetpp::simTime() + burst->getMaxOffset());
            if(pos == -1){ // Scheduled burst queue is full. Drop it!
               delete msg;
               delete ctlMsg;
               burstDroppedByQueue++;
               return;
            }
            //Insert Bust position on scheduledBurst queue
            myinfo->setBurstId(pos);
            // Fill ctlMsgs fields (this message will pass across all Sender's states)

            ctlMsg->setControlInfo(myinfo);  // Now compatible with cObject*
//            ctlMsg->setControlInfo(myinfo);
            ctlMsg->setKind(OBS_SCHEDULE_BCP);
            //Schedule BCP send to now
            scheduleAt(omnetpp::simTime(), ctlMsg);

            //Update horizon value
            horizon[wl] = omnetpp::simTime() + burst->getMaxOffset() + (burst->getBitLength()/dataRate) + guardTime;

        //Register horizon value
        horizonVec[wl]->record(horizon[wl]);
          }
   }else{
      /*
       * Automessages section. msg's kind will determine which section to enter
       */

      if(msg->getKind() == OBS_SCHEDULE_BCP){ //First step: Send BCP beginning message and schedule the end message.

         //Extract control info from received control message
//         info = omnetpp::check_and_cast<OBS_BurstSenderInfo *>(msg->getControlInfo());
          OBS_BurstSenderInfo *info = omnetpp::check_and_cast<OBS_BurstSenderInfo *>(msg->getControlInfo());

//          omnetpp::cMsgPar *info = omnetpp::check_and_cast<omnetpp::cMsgPar *>(msg->getControlInfo());
//          info = static_cast<OBS_BurstSenderInfo*>(wrapper->pointerValue());

         //If burst cannot be sent above the minimum offset, drop it!
         if((omnetpp::simTime() + scheduledBurst.retrieveMinOffset(info->getBurstId())) >= scheduledBurst.retrieveSendTime(info->getBurstId())){
            scheduledBurst.removeBurst(info->getBurstId());
            delete msg;
            //Update the burst dropped counter
            burstDroppedByOffset++;
            // Now you can try to pick a queued BCP (if any available) in order to send it
            if(!waitingBCP.isEmpty()){
               //pick up a BCP and send it now
               omnetpp::cMessage *bcp_ini = (omnetpp::cMessage*)waitingBCP.pop();
               scheduleAt(omnetpp::simTime(),bcp_ini);
            }
            return;
         }

         // Is control channel busy transmitting another BCP?
         if(control_is_busy){
            //If so, put current BCP into a queue (waitingBCP)
            waitingBCP.insert(msg);
         }else{
            //If not, take the control channel
            control_is_busy = true;

            //Create BCP message
            OBS_BurstControlPacket *bcp = new OBS_BurstControlPacket("iniBCP");
            //Initialize all BCP message fields
            bcp->setKind(1); //kind 1 = initial BCP
            bcp->setBurstColour(colour[info->getAssignedLambda()]);
            //Include relative Burst arrival time: the difference between iniBCP and iniBurst arrival
            //Since iniBCP will be sent now, this time is: sendTime(burst) - current simTime
            bcp->setBurstArrivalDelta(scheduledBurst.retrieveSendTime(info->getBurstId()) - omnetpp::simTime());

            //Fill all BCP fields
            bcp->setBurstifierId(info->getBurstifierId());
            bcp->setNumSeq(info->getNumSeq());
            bcp->setSenderId(getId());
            bcp->setLabel(info->getLabel());
            bcp->setBurstSize(scheduledBurst.retrieveBurstSize(info->getBurstId()));
            bcp->setByteLength(BCPSize);

        //Send BCP to control channel (the last one)
            send(bcp,"out",numLambdas);
            EV << "Sending BCP at= "<< getFullPath() <<" label=" << info->getLabel() <<  endl;

            //Retransmit received message (ctlMsg = *msg here)
            msg->setKind(OBS_SCHEDULE_END_BCP);
            //Schedule endBCP sending
            int BCPSizeInBits = BCPSize*8;
            scheduleAt(omnetpp::simTime()+(BCPSizeInBits/dataRate),msg);
         }

      }
      else if(msg->getKind() == OBS_SCHEDULE_END_BCP){ //Second step: Send BCP end message and schedule burst send.

         info = omnetpp::check_and_cast<OBS_BurstSenderInfo *>(msg->getControlInfo());
//         omnetpp::cMsgPar *wrapper = omnetpp::check_and_cast<omnetpp::cMsgPar *>(msg->getControlInfo());
//         info = static_cast<OBS_BurstSenderInfo*>(wrapper->pointerValue());
//         OBS_BurstSenderInfo *info = omnetpp::check_and_cast<OBS_BurstSenderInfo *>(msg->getControlInfo());

         OBS_BurstControlPacket *bcp = new OBS_BurstControlPacket("endBCP"); //BCP message created
         //Fill BCP message with info
         bcp->setKind(2); //kind 2 = end BCP
         bcp->setBurstifierId(info->getBurstifierId());
         bcp->setNumSeq(info->getNumSeq());
         //Send endBCP to control channel
         send(bcp,"out",numLambdas);
         //Retransmit received message (ctlMsg = *msg here)
         msg->setKind(OBS_SCHEDULE_BURST);
         //Schedule BurstIni sending
         scheduleAt(scheduledBurst.retrieveSendTime(info->getBurstId()),msg);

         control_is_busy = false; //Control channel is free now...
         //So, pick a pending BCP if any available
         if(!waitingBCP.isEmpty()){
            //Put the BCP off the queue and schedule it
            omnetpp::cMessage *bcp_ini = (omnetpp::cMessage*)waitingBCP.pop();
            scheduleAt(omnetpp::simTime(),bcp_ini);
         }

      }
      else if(msg->getKind() == OBS_SCHEDULE_BURST){ //Third step: Send the beginning of the optical Burst

         info = omnetpp::check_and_cast<OBS_BurstSenderInfo *>(msg->getControlInfo());
//         omnetpp::cMsgPar *wrapper = omnetpp::check_and_cast<omnetpp::cMsgPar *>(msg->getControlInfo());
//         info = static_cast<OBS_BurstSenderInfo*>(wrapper->pointerValue());
         OBS_Burst *burst= scheduledBurst.retrieveBurst(info->getBurstId());

         //Fill burst fields
         burst->setName("iniBurst");
         burst->setKind(1); //kind 1= send burst
         send(burst,"out",info->getAssignedLambda());

         //Retransmit received message (ctlMsg = *msg here)
         msg->setKind(OBS_SCHEDULE_END_BURST);
         //Schedule endBurst sending
         scheduleAt(omnetpp::simTime()+(burst->getBitLength()/dataRate),msg);

      }
      else if(msg->getKind() == OBS_SCHEDULE_END_BURST){ //Fourth and last step: Send the ending Burst message

         info = omnetpp::check_and_cast<OBS_BurstSenderInfo *>(msg->removeControlInfo());
//         omnetpp::cMsgPar *wrapper = omnetpp::check_and_cast<omnetpp::cMsgPar *>(msg->getControlInfo());
//         info = static_cast<OBS_BurstSenderInfo*>(wrapper->pointerValue());
         OBS_Burst *burst = new OBS_Burst("endBurst");

         //Fill burst fields
         burst->setKind(2); //kind 2= end burst
         burst->setBurstifierId(info->getBurstifierId());
         burst->setNumSeq(info->getNumSeq());

         send(burst,"out",info->getAssignedLambda());
         //Delete burst from scheduled list
         scheduledBurst.removeBurst(info->getBurstId());

         //Remove control info and container message
//         msg->setControlInfo(nullptr);
         delete msg;
         delete info;
         //Update the successful sends counter
         burstSent++;
      }
   }
}

void OBS_BurstSender::finish(){
   recordScalar("burst sent",burstSent);
   recordScalar("burst dropped by reaching Minimum Offset",burstDroppedByOffset);
   recordScalar("burst dropped by queue",burstDroppedByQueue);

   recordScalar("BCPs pending to be sent (because the control channel is busy)", waitingBCP.getLength());
}

//This method returns the first of the smallest lambdas available. Just a plain minimum algorithm
int OBS_BurstSender::findNearestHorizon(){
   int min = 0;
   int i;
   for(i=0;i<numLambdas;i++){
      if(horizon[min] > horizon[i])
         min = i;
   }
   return min;
}
