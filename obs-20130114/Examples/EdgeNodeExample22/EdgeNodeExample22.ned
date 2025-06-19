//
// Copyright (C) 2010-2013 Felix Espina
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

package obsmodules.Examples.EdgeNodeExample22;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.inet.WirelessHost;
import obsmodules.src.EdgeNode.OBS_EdgeNode;
import inet.node.inet.StandardHost;


network EdgeNodeExample22
{
    parameters:
        @networkNode;
        int lambdasEdge; //Number of data channels in the fiber connecting edges

        @display("bgb=627.7,411.6");
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
        edge1: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge;
                numOutLambdas = parent.lambdasEdge;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge1.irt";
                @display("p=159,112");
            gates:
                obsIn[parent.lambdasEdge+1];
                obsOut[parent.lambdasEdge+1];
        }
        edge2: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge;
                numOutLambdas = parent.lambdasEdge;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge2.irt";
                @display("p=158,272");
            gates:
                obsIn[parent.lambdasEdge+1];
                obsOut[parent.lambdasEdge+1];
        }
        edge3: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge;
                numOutLambdas = parent.lambdasEdge;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge1.irt";
                @display("p=278,111.2");
            gates:
                obsIn[parent.lambdasEdge+1];
                obsOut[parent.lambdasEdge+1];
        }
        host3: StandardHost {
            parameters:
                ipv4.routingTable.routingFile = "H1.irt";

                @display("p=434.9,111.2");
        }
        host4: StandardHost {
            parameters:
                ipv4.routingTable.routingFile = "H2.irt";
                @display("p=443,271.7");
        }
        edge4: OBS_EdgeNode {
            parameters:
                numInLambdas = parent.lambdasEdge;
                numOutLambdas = parent.lambdasEdge;
                obs.assembler.dispatcher.dispatcherRules = "DispatcherRules.dat";
                routingTable.routingFile = "Edge2.irt";
                @display("p=278,271.7");
            gates:
                obsIn[parent.lambdasEdge+1];
                obsOut[parent.lambdasEdge+1];
        }
        ipv4configurator: Ipv4NetworkConfigurator {
            parameters:
                @display("p=94.2,191.9");
        }
    connections allowunconnected:
        //Connections between hosts and Edge Nodes
        host1.ethg++ <--> {  datarate = 1Gbps; } <--> edge1.ethIO++;
        host2.ethg++ <--> {  datarate = 1Gbps; } <--> edge2.ethIO++;
        host3.ethg++ <--> {  datarate = 1Gbps; } <--> edge3.ethIO++;
        host4.ethg++ <--> {  datarate = 1Gbps; } <--> edge4.ethIO++;

        //Core 1 connections
        for i=0..lambdasEdge {
            edge1.obsOut[i] --> edge2.obsIn[i];
            edge2.obsOut[i] --> edge1.obsIn[i];

            edge3.obsOut[i] --> edge4.obsIn[i];
            edge4.obsOut[i] --> edge3.obsIn[i];
            
			edge3.obsOut[i] --> edge2.obsIn[i];
            edge2.obsOut[i] --> edge3.obsIn[i];
            
            edge1.obsOut[i] --> edge4.obsIn[i];
            edge4.obsOut[i] --> edge1.obsIn[i];
        }
}
