//
// Copyright (C) 2012 Naiara Garcia Royo, Felix Espina Antolin
// Copyright (C) 2012 Universidad Publica de Navarra
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
#include "testSource3.h"

Define_Module(testSource3);

void testSource3::initialize(){

	//Open the input file in read mode
	inputFile.open(par("inputFile").stringValue());
	if (!inputFile.is_open())
		omnetpp::cRuntimeError("Cannot open the input file for the test");

	//Read the first line and schedule the iniBCP, endBCP, iniBurst, endBurst
	processLine();
}

void testSource3::handleMessage(omnetpp::cMessage *msg){
	if (dynamic_cast <OBS_Burst *> (msg) != NULL){
		//Send the bursts from the defined output gate (data channel)
		SourceControlInfo *info = omnetpp::check_and_cast <SourceControlInfo *> (msg->removeControlInfo());
		send(msg,"out",info->getSendingIndex());
		delete info;
	}
	else if (dynamic_cast <OBS_BurstControlPacket *> (msg) != NULL){
		//Send the BCPs from the control channel
		SourceControlInfo *info = omnetpp::check_and_cast <SourceControlInfo *> (msg->removeControlInfo());
		send(msg,"out",info->getSendingIndex());
		delete info;
		//If it is a iniBCP read the following line and schedule the iniBCP, endBCP, iniBurst, endBurst
		if (msg->getKind() == 1){
			processLine();
		}
	}
	else{
	    omnetpp::cRuntimeError("Received an unknown packet");
	}
}

void testSource3::finish(){
	//Close the file
	inputFile.close();
}

void testSource3::processLine(){
	string line;
	int index, bcpIndex, val, burstifierId, numSeq, label, colour, senderId, numPackets;
	omnetpp::simtime_t sendTime, minOffset, maxOffset, BCPDelta, iniBurstDelta, endBurstDelta;
	char sendTimeChr[20], minOffsetChr[20], maxOffsetChr[20], BCPDeltaChr[20], iniBurstDeltaChr[20], endBurstDeltaChr[20], senderIdChr[20], BCPlengthChr[20], colourChr[20], burstifierIdChr[20], numSeqChr[20], labelChr[20], numPacketsChr[20], lengthChr[20];
	long long length, BCPlength;
	stringstream char2int;

	if (inputFile.good()){//If there is no problem and the end of file is not reached, get object's information
		getline(inputFile,line);
		lineNum++;
		val = sscanf(line.data(),"%s %s %s %s %d %d %s %s %s %s %s %s %s %s %s %s", sendTimeChr, BCPDeltaChr, iniBurstDeltaChr, endBurstDeltaChr, &bcpIndex, &index, BCPlengthChr, colourChr, burstifierIdChr, numSeqChr, labelChr, senderIdChr, minOffsetChr, maxOffsetChr, numPacketsChr, lengthChr);
		if (val != 16){
			string firstPos = line.substr(0,1);
			if (firstPos.compare("P") == 0){
			    omnetpp::cRuntimeError("Unexpected packet definition on line %d", lineNum);
			}
			else{
			    omnetpp::cRuntimeError("Wrong format on line %d", lineNum);
			}
		}

		sendTime = omnetpp::SimTime::parse(sendTimeChr);
		if(omnetpp::simTime()<=sendTime){//If the BCP is not scheduled to the past, schedule it

			//Create the BCP beginning
			OBS_BurstControlPacket *iniBCP = new OBS_BurstControlPacket("iniBCP");
			iniBCP->setKind(1);
			SourceControlInfo *infoBCP = new SourceControlInfo();
            omnetpp::cMsgPar *wrapper = new omnetpp::cMsgPar("SourceControlInfo");
            wrapper->setPointerValue(infoBCP);
			infoBCP->setSendingIndex(bcpIndex);
			iniBCP->setControlInfo(wrapper);

			//Create the BCP end
			OBS_BurstControlPacket *endBCP = new OBS_BurstControlPacket("endBCP");
			endBCP->setKind(2);
            SourceControlInfo *infoBCP2 = new SourceControlInfo();
            wrapper->setPointerValue(infoBCP2);
			endBCP->setControlInfo(wrapper);

			//Create the burst beginning
			OBS_Burst *iniBurst = new OBS_Burst("iniBurst");
			iniBurst->setKind(1);
			SourceControlInfo *info = new SourceControlInfo();
			info->setSendingIndex(index);
            wrapper->setPointerValue(info);
			iniBurst->setControlInfo(wrapper);

			//Create the burst end
			OBS_Burst *endBurst = new OBS_Burst("endBurst");
			endBurst->setKind(2);
            SourceControlInfo *info2 = new SourceControlInfo();
            wrapper->setPointerValue(info2);
			endBurst->setControlInfo(wrapper);

			iniBurstDelta = omnetpp::SimTime::parse(iniBurstDeltaChr);
			iniBCP->setBurstArrivalDelta(iniBurstDelta);

			if(strcmp(colourChr,"*") == 0){ //Optional parameter
				char2int.clear();
				char2int << colourChr;
				char2int >> colour;
				iniBCP->setBurstColour(colour);
			}

			if(strcmp(labelChr,"*") != 0){ //Optional parameter
				char2int.clear();
				char2int << labelChr;
				char2int >> label;
				iniBCP->setLabel(label);
			}

			if(strcmp(BCPlengthChr,"*") != 0){ //Optional parameter
				char2int.clear();
				char2int << BCPlengthChr;
				char2int >> BCPlength;
				iniBCP->setByteLength(BCPlength);
			}

			if(strcmp(lengthChr,"*") != 0){ //Optional parameter
				char2int.clear();
				char2int << lengthChr;
				char2int >> length;
				iniBCP->setBurstSize(length);
				iniBurst->setByteLength(length);
			}

			if(strcmp(minOffsetChr,"*") != 0){ //Optional parameter
			 	minOffset = omnetpp::SimTime::parse(minOffsetChr);
			 	iniBurst->setMinOffset(minOffset);
			}

			if(strcmp(maxOffsetChr,"*") != 0){ //Optional parameter
			 	maxOffset = omnetpp::SimTime::parse(maxOffsetChr);
			 	iniBurst->setMaxOffset(maxOffset);
			}

			if(strcmp(senderIdChr,"*") != 0){ //Optional parameter
			 	char2int.clear();
			 	char2int << senderIdChr;
			 	char2int >> senderId;
			 	iniBCP->setSenderId(senderId);
			 	iniBurst->setSenderId(senderId);
			}

			if(strcmp(numPacketsChr,"*") != 0){ //Optional parameter
				char2int.clear();
				char2int << numPacketsChr;
				char2int >> numPackets;
				iniBurst->setNumPackets(numPackets);

				//Create the datagrams, fill them and insert them in the queue
				int i=1;
				while ((i<=numPackets)&&(inputFile.good())){
					int protocol;
					char srcAddr[20], destAddr[20], protocolChr[20], srcPortChr[20], destPortChr[20], datagramLengthChr[20];
					unsigned short srcPort, destPort;
					long long datagramLength;

					getline(inputFile,line);
					lineNum++;
					val = sscanf(line.data(),"P %s %s %s %s %s %s", srcAddr, destAddr, protocolChr, srcPortChr, destPortChr, datagramLengthChr);
					if (val != 6){
						string firstPos = line.substr(0,1);
						if (firstPos.compare("P") != 0){
						    omnetpp::cRuntimeError("Packet definition missing on line %d", lineNum);
						}
						else{
						    omnetpp::cRuntimeError("Wrong format on line %d", lineNum);
						}
					}
					//Create the IP datagram and fill it
//					IPDatagram *datagram = new IPDatagram();
//                    IPv4Datagram *datagram = new IPv4Datagram();
					inet::Packet *packet = new inet::Packet("IPPacket");
					auto ipv4Header = inet::makeShared<inet::Ipv4Header>();
					if(strcmp(datagramLengthChr,"*") != 0){ //Optional parameter
						char2int.clear();
						char2int << datagramLengthChr;
						char2int >> datagramLength;
//						datagram->setByteLength(datagramLength);
						ipv4Header->setTotalLengthField(inet::B(length));

					}
					if(strcmp(srcAddr,"*") != 0){ //Optional parameter
//						datagram->setSrcAddress(srcAddr);
					    inet::Ipv4Address srcAddrP;
                        srcAddrP.set(srcAddr);
                        ipv4Header->setSrcAddress(srcAddrP);
					}
					if(strcmp(srcAddr,"*") != 0){ //Optional parameter
//						datagram->setDestAddress(destAddr);
					    inet::Ipv4Address destAddrP;
                        destAddrP.set(destAddr);
                        ipv4Header->setDestAddress(destAddrP);
					}
					if(strcmp(protocolChr,"*") != 0){ //Optional parameter
						char2int.clear();
						char2int << protocolChr;
						char2int >> protocol;
						//Create the encapsulate packet and encapsulate it
						if (protocol == inet::IP_PROT_TCP){
//							TCPSegment *packet = new TCPSegment()
                            auto tcpHeader = inet::makeShared<inet::tcp::TcpHeader>();
							if(strcmp(srcPortChr,"*") != 0){ //Optional parameter
								char2int.clear();
								char2int << srcPortChr;
								char2int >> srcPort;
                                tcpHeader->setSrcPort(srcPort);
							}
							if(strcmp(destPortChr,"*") != 0){ //Optional parameter
								char2int.clear();
								char2int << destPortChr;
								char2int >> destPort;
								tcpHeader->setDestPort(destPort);
							}
                            ipv4Header->setProtocolId(inet::IP_PROT_TCP);
                            packet->insertAtBack(tcpHeader);
						}
						else if (protocol == inet::IP_PROT_UDP){
                            auto udpHeader = inet::makeShared<inet::UdpHeader>();
							if(strcmp(srcPortChr,"*") != 0){ //Optional parameter
								char2int.clear();
								char2int << srcPortChr;
								char2int >> srcPort;
								udpHeader->setSourcePort(srcPort);
							}
							if(strcmp(destPortChr,"*") != 0){ //Optional parameter
								char2int.clear();
								char2int << destPortChr;
								char2int >> destPort;
								udpHeader->setDestinationPort(destPort);
							}
                            ipv4Header->setProtocolId(inet::IP_PROT_UDP);
                            packet->insertAtBack(udpHeader);
						}
						else{
							cout << "<testSource3><" << omnetpp::simTime() << "> WARNING: Attempted to attach a packet that is neither TCP nor UDP." << endl;
						}
					}
					iniBurst->insertMessage(packet);
					i++;
				}
			}

			if(strcmp(burstifierIdChr,"*") != 0){ //Optional parameter
				char2int.clear();
				char2int << burstifierIdChr;
				char2int >> burstifierId;
				iniBCP->setBurstifierId(burstifierId);
				endBCP->setBurstifierId(burstifierId);
				iniBurst->setBurstifierId(burstifierId);
				endBurst->setBurstifierId(burstifierId);
			}
			if(strcmp(numSeqChr,"*") != 0){ //Optional parameter
				char2int.clear();
				char2int << numSeqChr;
				char2int >> numSeq;
				iniBCP->setNumSeq(numSeq);
				endBCP->setNumSeq(numSeq);
				iniBurst->setNumSeq(numSeq);
				endBurst->setNumSeq(numSeq);
			}

			//Schedule the BCP beginning
			scheduleAt(sendTime, iniBCP);
			//Schedule the BCP end
			BCPDelta = omnetpp::SimTime::parse(BCPDeltaChr);
			scheduleAt(sendTime+BCPDelta, endBCP);
			//Schedule the burst beginning
			scheduleAt(sendTime+iniBurstDelta, iniBurst);
			//Schedule the burst end
			endBurstDelta = omnetpp::SimTime::parse(endBurstDeltaChr);
			scheduleAt(sendTime+endBurstDelta, endBurst);
		}
		else{
		    omnetpp::cRuntimeError("Cannot send a BCP+burst scheduled to the past");
		}
	}
}
