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
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h" //#include "IPv4Datagram.h"
#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/transportlayer/tcp_common/TcpHeader.h" //#include "TCPSegment.h"
#include "inet/transportlayer/tcp/Tcp.h"
#include "inet/common/Units.h"
#include "inet/transportlayer/udp/Udp.h" //#include "UDPPacket_m.h"

using namespace std;

//! Packet generator: generates IP datagrams which encapsulate TCP segments or UDP packets.
//! Input for OBS_PacketDispatcher and OBS_PacketBurstifier.
class testSource1 : public omnetpp::cSimpleModule{
   protected:
	  ifstream inputFile; //!> File with the information of the objects to be sent.
      virtual void initialize();
      virtual void finish();
      virtual void handleMessage(omnetpp::cMessage *msg);
   private:
	  int lineNum; //!> Processed line number.
      void processLine(); //!> Reads a line and schedules the packet to be sent.
};
