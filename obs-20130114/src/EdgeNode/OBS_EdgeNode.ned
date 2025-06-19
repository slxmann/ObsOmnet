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

package obsmodules.src.EdgeNode;

import inet.networklayer.ipv4.Ipv4NetworkLayer;
import inet.networklayer.ipv4.Ipv4RoutingTable;
import inet.networklayer.common.InterfaceTable;
import inet.linklayer.ppp.PppInterface;
import inet.linklayer.ethernet.EthernetInterface;

import inet.linklayer.ethernet.basic.EthernetEncapsulation;
//
// Edge node for a OBS network. It's just a Router (from the INET Framework) including an OBS Interface.
//
module OBS_EdgeNode
{
    parameters:
        int numInLambdas; // Number of input data channels for the OBS interface.
        int numOutLambdas; // Number of output data channels for the OBS interface.
        //string inColours; // Colour array for input data channels.
        string outColours; // Colour array for output data channels.
        @display("i=block/classifier2;bgb=395,337");
    gates:
        inout pppIO[];	// PPP port
        inout ethIO[];	// Ethernet port
        input obsIn[];  // OBS input
        output obsOut[]; //OBS output
    submodules:
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=150,60;i=block/table");
        }
        routingTable: Ipv4RoutingTable {
            parameters:
                forwarding = true;
                routerId = "auto";
                @display("p=240,60;i=block/table");
        }
        networkLayer: Ipv4NetworkLayer {
            parameters:
                forwarding = true;
                ip.interfaceTableModule = "^.^.interfaceTable";
                ip.routingTableModule = "^.^.routingTable";
                configurator.networkConfiguratorModule = "^.^.ipv4configurator";
                @display("p=192,149;i=block/fork;q=queue");
        }
        ppp[sizeof(pppIO)]: PppInterface {
            parameters:
                @display("p=82,257,row,110;q=l2queue;i=block/ifcard");
        }
        eth[sizeof(ethIO)]: EthernetInterface {
            parameters:
                @display("p=185,257,row,110;q=l2queue;i=block/ifcard");
        }
        obs: OBS_EdgeInterface {
            parameters:
                numInLambdas = parent.numInLambdas;
                numOutLambdas = parent.numOutLambdas;
                //inColours = inColours; 
                outColours = parent.outColours;
                @display("p=283,257;q=l2queue;i=block/ifcard");
        }
		//needed to connect ethernetInterface tp the Ipv4NetworkLayer ( convertion from ethernet to ipv4 packets)
        ethEncap[sizeof(ethIO)]: EthernetEncapsulation {
            parameters:
                registerProtocol = true;
                @display("p=192,186,row,110");
        }
    connections allowunconnected:
        // connections to the outer world
        for i=0..sizeof(pppIO)-1 {
            pppIO[i] <--> ppp[i].phys;
            //            ppp[i].upperLayerOut --> networkLayer.ifIn[i];
            //            ppp[i].upperLayerIn <-- networkLayer.ifOut[i];
            ppp[i].upperLayerOut --> networkLayer.ifInV++;
            ppp[i].upperLayerIn <-- networkLayer.ifOutV++;
        }

        for i=0..sizeof(ethIO)-1 {
            ethIO[i] <--> eth[i].phys;
            //            eth[i].upperLayerOut --> networkLayer.ifIn[sizeof(pppIO)+i];
            //            eth[i].upperLayerIn <-- networkLayer.ifOut[sizeof(pppIO)+i];
            eth[i].upperLayerOut --> ethEncap[i].lowerLayerIn;
            eth[i].upperLayerIn <-- ethEncap[i].lowerLayerOut;

            ethEncap[i].upperLayerOut --> networkLayer.ifInV++;
            ethEncap[i].upperLayerIn <-- networkLayer.ifOutV++;
        }

        for i=0..sizeof(obsIn)-1 {
            //            obsIn[i] --> obs.physIn[i];
            obsIn[i] --> obs.physIn++;
        }

        for i=0..sizeof(obsOut)-1 {
            //            obs.physOut[i] --> obsOut[i];
            obs.physOut++ --> obsOut[i];
        }

        //Connection between OBS Interface and Network layer. Only one line, as mentioned before
        //        obs.netwOut --> networkLayer.ifIn[sizeof(pppIO)+sizeof(ethIO)];
        //        obs.netwIn <-- networkLayer.ifOut[sizeof(pppIO)+sizeof(ethIO)];
        obs.upperLayerOut --> networkLayer.ifInV++;
        obs.upperLayerIn <-- networkLayer.ifOutV++;
}
