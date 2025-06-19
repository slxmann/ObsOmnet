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
#include "testSource1.h"

Define_Module(testSource1);

void testSource1::initialize(){

	//Open the input file in read mode
	inputFile.open(par("inputFile").stringValue());
	if (!inputFile.is_open())
	    omnetpp::cRuntimeError("Cannot open the input file for the test");

	//Read the first line and schedule the packet
	processLine();

}

void testSource1::handleMessage(omnetpp::cMessage *msg){
//	if (dynamic_cast <IPDatagram *> (msg) != NULL){
    if (dynamic_cast <inet::Ipv4Header *> (msg) != NULL){
		//Send the packet from the output gate (this module has only one)
		send(msg,"out");
		//Read the following line and schedule the packet
		processLine();
	}
	else
	    omnetpp::cRuntimeError("Received an unknown packet");
}

void testSource1::finish(){
	//Close the file
	inputFile.close();
}

void testSource1::processLine(){
	string line;
	int val, protocol;
	omnetpp::simtime_t sendTime;
	char sendTimeChr[20], srcAddr[20], destAddr[20], protocolChr[20], srcPortChr[20], destPortChr[20];
	unsigned short srcPort, destPort;
	long long length;
	stringstream char2int;

	if (inputFile.good()){//If there is no problem and the end of file is not reached, get packet's information
			//Read the line and get the values
			getline(inputFile,line);
			lineNum++;
			val = sscanf(line.data(),"%s %s %s %s %s %s %lld", sendTimeChr, srcAddr, destAddr, protocolChr, srcPortChr, destPortChr, &length);
			if (val != 7){
			    omnetpp::cRuntimeError("Wrong format on line %d", lineNum);
			}
			sendTime = omnetpp::SimTime::parse(sendTimeChr);
			if(omnetpp::simTime()<=sendTime){//If the datagram is not scheduled to the past, schedule it
				//Create the datagram and fill it
//				IPDatagram *datagram = new IPDatagram();
	           inet::Packet *packet = new inet::Packet("IPPacket");
	            auto ipv4Header = inet::makeShared<inet::Ipv4Header>();
//				datagram->setByteLength(length);
	            ipv4Header->setTotalLengthField(inet::B(length));
				if(strcmp(srcAddr,"*") != 0){ //Optional parameter
//					datagram->setSrcAddress(srcAddr);
                    inet::Ipv4Address srcAddrP;
                    srcAddrP.set(srcAddr);
                    ipv4Header->setSrcAddress(srcAddrP);
				}
				if(strcmp(destAddr,"*") != 0){ //Optional parameter
//					datagram->setDestAddress(destAddr);
				    inet::Ipv4Address destAddrP;
                    destAddrP.set(destAddr);
                    ipv4Header->setDestAddress(destAddrP);
				}
				//Create the packet and encapsulate it
				if(strcmp(protocolChr,"*") != 0){ //Optional parameter
//					char2int.clear();
					char2int << protocolChr;
					char2int >> protocol;
				    ipv4Header->setProtocolId(static_cast<inet::IpProtocolId>(protocol));
				    if (protocol == inet::IP_PROT_TCP){
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
						packet->insertAtBack(udpHeader);
					}
					else{
						cout << "<testSource1><" << omnetpp::simTime() << "> WARNING: Attempted to attach a packet that is neither TCP nor UDP." << endl;
					}
				}
	            // Insert headers and finalize packet
	            packet->insertAtFront(ipv4Header);
	            inet::B totalLength = inet::B(length);
	            inet::B currentLength = packet->getTotalLength();
	            if (totalLength > currentLength) {
	                auto payload = inet::makeShared<inet::ByteCountChunk>(totalLength - currentLength);
	                packet->insertAtBack(payload);
	            }


				//Schedule the first datagram
				scheduleAt(sendTime,packet);
			}
			else{
			    omnetpp::cRuntimeError("Cannot send a packet scheduled to the past");
			}
		}
}
