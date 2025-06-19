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

package obsmodules.Examples.jitel09;

import obsmodules.src.EdgeNode.OBS_EdgeNode;
import obsmodules.src.CoreNode.OBS_CoreNode;
import inet.node.inet.StandardHost;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;

network jitel09Simulation
{
    parameters:
        @networkNode;
        int lambdasEdge1; //Number of data channels in the fiber connecting edge1 and core1
        int lambdasEdge2; //Number of data channels in the fiber connecting edge2 and core1
        int lambdasEdge3; //Number of data channels in the fiber connecting edge3 and core2
        int lambdasEdge4; //Number of data channels in the fiber connecting edge4 and core2
        int lambdasCore; //Number of data channels in the fiber connecting core1 and core2
    submodules:
        host1: StandardHost {
            parameters:
                ipv4.routingTable.routingFile = "H1.irt";
                @display("p=46,112");
        }
        host2: StandardHost {
            parameters:
                ipv4.routingTable.routingFile = "H2.irt";
                @display("p=48,272");
        }
        host3: StandardHost {
            parameters:
                ipv4.routingTable.routingFile = "H3.irt";
                @display("p=639,120");
        }
        host4: StandardHost {
            parameters:
                ipv4.routingTable.routingFile = "H4.irt";
                @display("p=636,264");
        }
        edge1: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge1;
                numOutLambdas = parent.lambdasEdge1;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge1.irt";
                @display("p=159,112");
            gates:
                obsIn[parent.lambdasEdge1+1];
                obsOut[parent.lambdasEdge1+1];
        }
        edge2: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge2;
                numOutLambdas = parent.lambdasEdge2;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge2.irt";
                @display("p=158,272");
            gates:
                obsIn[parent.lambdasEdge2+1];
                obsOut[parent.lambdasEdge2+1];
        }
        edge3: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge3;
                numOutLambdas = parent.lambdasEdge3;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge3.irt";
                @display("p=505,120");
            gates:
                obsIn[parent.lambdasEdge3+1];
                obsOut[parent.lambdasEdge3+1];
        }
        edge4: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge4;
                numOutLambdas = parent.lambdasEdge4;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge4.irt";
                @display("p=503,264");
            gates:
                obsIn[parent.lambdasEdge4+1];
                obsOut[parent.lambdasEdge4+1];
        }
        core1: OBS_CoreNode {
            parameters:
                ControlUnit.RoutingTable.routeTableFile = "core1Route.dat";
                numPorts = 3;
				gateSize = parent.lambdasCore + 1 + parent.lambdasEdge3 + 1 + parent.lambdasEdge4 + 1; // Core 1 <--> core2 + 1 // core1 <-->edge1 + 1 // core1 <--> edge2 +1 
                @display("p=267,192");
//        	gates:
//	    		in[parent.lambdasCore + 1];
//            	out[parent.lambdasCore + 1];
        }
        core2: OBS_CoreNode {
            parameters:
                ControlUnit.RoutingTable.routeTableFile = "core2Route.dat";
                numPorts = 3;
                gateSize = parent.lambdasCore + 1 + parent.lambdasEdge3 + 1 + parent.lambdasEdge4 + 1;
                @display("p=411,192");
//			gates:
//			    in[parent.lambdasCore + 1];
//            	out[parent.lambdasCore + 1];       
        }
        ipv4configurator: Ipv4NetworkConfigurator {
            parameters:
                @display("p=94.2,191.9");
        }
    connections:
        //Connections between hosts and Edge Nodes
        host1.ethg++ <--> { datarate=100Gbps; } <--> edge1.ethIO++;

        host2.ethg++ <--> { datarate=100Gbps; } <--> edge2.ethIO++;

        host3.ethg++ <--> { datarate=100Gbps; } <--> edge3.ethIO++;

        host4.ethg++ <--> { datarate=100Gbps; } <--> edge4.ethIO++;

        //Core 1 connections
        for i=0..lambdasEdge1 {
            edge1.obsOut[i] --> core1.in++;
            core1.out++ --> edge1.obsIn[i];
        }
        for i=0..lambdasEdge2 {
            edge2.obsOut[i] --> core1.in++;
            core1.out++ --> edge2.obsIn[i];
        }

        //Core 2 connections
        for i=0..lambdasEdge3 {
            edge3.obsOut[i] --> core2.in++;
            core2.out++ --> edge3.obsIn[i];
        }
        for i=0..lambdasEdge4 {
            edge4.obsOut[i] --> core2.in++;
            core2.out++ --> edge4.obsIn[i];
        }

        //Connections between core nodes
        for i=0..lambdasCore {
            core1.out++ --> core2.in++;
            core2.out++ --> core1.in++;
        }
}