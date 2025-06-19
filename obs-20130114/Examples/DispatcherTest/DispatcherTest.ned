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

package obsmodules.Examples.DispatcherTest;

import obsmodules.src.tests.PacketConverter;
import obsmodules.src.EdgeNode.OBS_PacketDispatcher;
import inet.applications.generic.IpvxTrafSink;
//import inet.applications.generic.IPTrafGen;
import inet.applications.generic.IpvxTrafGen;

// Module used to check that the dispatcher works properly.
// The generator creates IP Packets varying the destination IP field.
// This field is used by the dispatcher module to redirect them to one of the available sinks.
// See README file for more details.
//
network DispatcherTest
{
    parameters:
        int numQueues; // Number of queues of the dispatcher
        string rulesFile = default("DispatcherRules.dat"); // File with the dispatcher rules
    submodules:
//        generator: IPTrafGen {
        generator: IpvxTrafGen {
                parameters:
                startTime = 0s;
//                packetInterval = exponential(1s);
                sendInterval = exponential(1s);          
                numPackets = 100;
                protocol = 171;
                packetLength = 1000 B;
                destAddresses = "127.0.0.1 127.0.0.2 127.0.0.3";
                @display("i=block/source");
        }
        converter: PacketConverter {
            parameters:
                @display("i=block/cogwheel");
        }
        dispatcher: OBS_PacketDispatcher {
            parameters:
                numQueues = parent.numQueues;
                dispatcherRules = parent.rulesFile;
                @display("i=block/classifier");
            gates:
                out[3];
        }
        sink[3]: IpvxTrafSink {
            parameters:
                @display("i=block/sink");

        }
    connections allowunconnected:
        generator.ipOut --> converter.in;
        converter.out --> dispatcher.in;
        dispatcher.out[0] --> sink[0].ipIn;
        dispatcher.out[1] --> sink[1].ipIn;
        dispatcher.out[2] --> sink[2].ipIn;
}

