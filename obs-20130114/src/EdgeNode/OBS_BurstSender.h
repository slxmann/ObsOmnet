//
// Copyright (C) 2010-2012 Javier Armendariz Silva, Naiara Garcia Royo
// Copyright (C) 2010-2012 Universidad Publica de Navarra
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


#include <omnetpp.h>
#include "BurstList.h"
#include <stdlib.h>
#include "../messages/OBS_BurstControlPacket_m.h"
#include "OBS_BurstSenderInfo_m.h"
#include "OBS_BurstifierInfo_m.h"
#include "inet/common/INETDefs.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/networklayer/common/NetworkInterface.h"

#include "inet/common/INETUtils.h"

#include "inet/linklayer/ethernet/base/EthernetMacBase.h"


// Forward declarations with namespace
namespace inet {  class NetworkInterface; }
#include "inet/common/ModuleAccess.h"
#include "inet/common/Simsignals.h"

//class InterfaceEntry;
//class NotificationBoard;

//! Responsible of burst sending through the OBS Network.
class INET_API OBS_BurstSender : public omnetpp::cSimpleModule{
    protected:
        //! @enum This enum contains all available values for msg's kind field into handleMessage().
        enum{
           OBS_SCHEDULE_BCP,
           OBS_SCHEDULE_END_BCP,
           OBS_SCHEDULE_BURST,
           OBS_SCHEDULE_END_BURST
        };

        int* colour; //!< Sender's colour implementation (See .cc file for details).

        int numLambdas; //!< Number of data channels.
        double dataRate; //!< Data rate of the optical channel.
        int BCPSize; //!< Size of the Burst Control Packet.
        simtime_t guardTime; //!< Offset placed between consecutive burst transmissions.
        int maxSchedBurstSize; //!< Maximum size of scheduled burst queue (0 = infinity).

        bool control_is_busy; //!< True if control channel is currently busy.
        simtime_t *horizon; //!< This array shows the simtime where each data channel is free.
        vector< cOutVector* > horizonVec; //!< Horizon value vector. One for each lambda.
        BurstList scheduledBurst; //!< List of scheduled bursts (waiting to be sent).
        cQueue waitingBCP; //!< Queue of BCPs pending to be sent (because they found BCP channel busy).

        // Counters set for statistic purposes
        int burstRecv; //!< Received bursts counter.
        int burstSent; //!< Burst sent counter.
        int burstDroppedByOffset; //!< Number of bursts dropped because they reached the minimum offset.
        int burstDroppedByQueue; //!< Number of bursts dropped because scheduledBurst is full.
        inet::NetworkInterface *networkInterface; //!< Points to InterfaceTable.

//        inet::NotificationBoard *nb; //!< Pointer to the Notification Board. // not used




        bool testing; //!< If true, module won't try to register itself (use to test this module outside the Edge Node).

        cOutVector burstSize; //!< This vector stores received burst's sizes.

//        inet::NetworkInterface* registerInterface(double datarate);
        //! Initialize the scheduled and BCP queues, set the control channel as free, create the horizon array which size is the value of the lambda parameter and initialize them to 0's.
//        virtual void initialize(int stage );
//        virtual int numInitStages() const  { return inet::NUM_INIT_STAGES; }
//        virtual void configureNetworkInterface() = 0;
        void netIftConfiguration(double dataRate);
        virtual void initialize(int stage) override;
        //! Write scalars and make all the cleanup.
        virtual void finish() override;
        //!Message handler of the module. It contains the protocol needed to send bursts to an assigned lightpath. See ned documentation for details.
        //! @param *msg Message received by the getModule(either messages from the outer-world or an auto-message).
	    virtual void handleMessage(omnetpp::cMessage *msg) override ;
	    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; } //to make initialize be called upon each stage

   public:
	virtual ~OBS_BurstSender();
   private:
	  //! Find the minimum value on the data channel's horizon table.
      //! It simply uses a simple minimum find algorithm, that can be optimized.
      //! @returns The index corresponding to the lambda with smaller horizon.
      int findNearestHorizon();
};
