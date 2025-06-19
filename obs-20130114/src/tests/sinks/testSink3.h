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
#include <fstream>
#include <omnetpp.h>
//#include "IPDatagram_m.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h" //#include "IPv4Datagram.h"
#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/transportlayer/tcp_common/TcpHeader.h" //#include "TCPSegment.h"
#include "inet/transportlayer/tcp/Tcp.h"

#include "inet/transportlayer/udp/Udp.h" //#include "UDPPacket_m.h"
#include "../../CoreNode/OBS_CoreControlLogic.h"
#include "../../misc/OBS_OpticalMonitor.h"
#include "../../messages/OBS_BurstControlPacket_m.h"

using namespace std;

//! BCP and burst receiver: receives iniBCP, endBCP, iniBurst (with or without packets inside of it) and endBurst packets.
//! Output for OBS_BurstSender, OBS_CoreInput, OBS_CoreOutput, OBS_OpticalMonitor and OBS_DropBurst.
class testSink3 : public omnetpp::cSimpleModule{
   protected:
      virtual void initialize();
      virtual void finish();
      virtual void handleMessage(omnetpp::cMessage *msg);
   private:
      void openFiles();
      bool compareFiles();
      void deleteFiles();
      ifstream currentFile, patternFile;
      ofstream outputFile;
      string errorPhrase;
};
