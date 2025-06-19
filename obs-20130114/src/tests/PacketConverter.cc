//
// Copyright (C) 2010-2012 Javier Armendariz Silva, Naiara Garcia Royo, Felix Espina Antolin
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

#include<omnetpp.h>
//#include "IPDatagram.h"
//#include <IPControlInfo.h>
#include  "inet/networklayer/ipv4/Ipv4Header_m.h" //"IPv4Datagram.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h" //#include <IPv4ControlInfo.h>
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/networklayer/common/L3Address.h"
#include "inet/common/Units.h"

using namespace std;

//
// Dummy class created for the use in simulations where packets are created using IPTrafGen (Dispatcher Test, for example)
//
class PacketConverter : public omnetpp::cSimpleModule
{
   protected:
      virtual void handleMessage(omnetpp::cMessage *msg);
   public:
      virtual ~PacketConverter();
};

Define_Module(PacketConverter);

PacketConverter::~PacketConverter(){}

//void PacketConverter::handleMessage(omnetpp::cMessage *msg){
//   //IPTrafGen generates a cMessage packet which contains a IPControlInfo object encapsulated
////   IPControlInfo *IPCtl = check_and_cast < IPControlInfo *> (msg->getControlInfo());
//   IPv4ControlInfo *IPCtl = omnetpp::check_and_cast < IPv4ControlInfo *> (msg->getControlInfo());
//
//   // Create a IPDatagram object
////   IPDatagram *IPSal = new IPDatagram();
//   inet::Ipv4Header *IPSal = new inet::Ipv4Header();
//
//   // Fill IP datagram with control info fields
//   IPSal->setSrcAddress(IPCtl->getSrcAddr());
//   IPSal->setDestAddress(IPCtl->getDestAddr());
//   // Also, add datagram length
//   omnetpp::cPacket *pkt = omnetpp::check_and_cast<omnetpp::cPacket *> (msg);
//   IPSal->setBitLength(pkt->getBitLength());
//   //Send the IPDatagram object
//   send(IPSal,"out");
//   //...and that's all!
//   delete msg;
//}

void PacketConverter::handleMessage(omnetpp::cMessage *msg)
{
    auto packet = omnetpp::check_and_cast<inet::Packet *>(msg);

    // Get address information from tags
    auto addrReq = packet->getTag<inet::L3AddressReq>();

    // Create and configure IPv4 header
    auto ipv4Header = inet::makeShared<inet::Ipv4Header>();
    ipv4Header->setSrcAddress(addrReq->getSrcAddress().toIpv4());
    ipv4Header->setDestAddress(addrReq->getDestAddress().toIpv4());

    auto bytes = packet->getBitLength() / 8;
    ipv4Header->setTotalLengthField(inet::B(bytes));
//    ipv4Header->setTotalLengthField(packet->getBitLength() / 8); // Same as original

    // Create new packet with just the header
    auto newPacket = new inet::Packet("IPPacket");
    newPacket->insertAtFront(ipv4Header);

    send(newPacket, "out");
    delete msg;
}
