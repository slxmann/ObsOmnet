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

package obsmodules.src.CoreNode;

//
// Switching device in the OBS arquitecture.
//
module OBS_CoreNode
{
    parameters:
        int numPorts; //Number of fibers (connections)
        int gateSize; // gates size
        string lambdasPerInPort; //Number of input data channels for each fiber
        string lambdasPerOutPort; //Number of output data channels for each fiber 
        string inputColours; // Colour of each input data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        string outputColours; // Colour of each output data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        @display("bgb=434,264;i=block/switch");
    gates:
        input in[gateSize];
        output out[gateSize];
    submodules:
        Input: OBS_CoreInput {
            parameters:
                numPorts = parent.numPorts;
                colours = parent.inputColours;
                lambdasPerPort = parent.lambdasPerInPort;
                @display("i=block/arrival;p=81,127");
            gates:
                in[parent.gateSize];
                out[parent.gateSize];
        }
        Output: OBS_CoreOutput {
            parameters:
                numPorts = parent.numPorts;
                colours = parent.outputColours;
                lambdasPerPort = parent.lambdasPerOutPort;
                @display("i=block/departure;p=351,123");
            gates:
                in[parent.gateSize];
                out[parent.gateSize];
        }
        ControlUnit: OBS_CoreControlUnit {
            parameters:
                numPorts = parent.numPorts;
                lambdasPerOutPort = parent.lambdasPerOutPort;
                @display("i=block/cogwheel;p=218,67");
            gates:
                in[numPorts]; //A gate for BCP channel
                out[numPorts]; //A gate for Output module
        }
        OXC: OBS_OpticalCrossConnect {
            parameters:
                @display("i=block/switch;p=218,195");
            gates:
                in[parent.gateSize - parent.numPorts];
                out[parent.gateSize - parent.numPorts];
        }
    connections allowunconnected:
        //Connect input control channels
        for i=0..gateSize -1 {
            in++ --> Input.in++;
        }

        //Connect output control channels
        for i=0..gateSize-1 {
            Output.out++ --> out++;
        }

        //Connect the control channels with the control unit
        for i=0..numPorts-1 {
            Input.out[i] --> ControlUnit.in[i];
            ControlUnit.out[i] --> Output.in[i];
        }

        //Connect input data channels
        for i=numPorts..gateSize-1 {
            Input.out[i] --> OXC.in[i-numPorts];
        }

        //Connect output data channels
        for i=numPorts..gateSize -1{
            OXC.out[i-numPorts] --> Output.in[i];
        }
}