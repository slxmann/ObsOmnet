//
// Copyright (C) 2012 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package inet.networklayer.contract;

//
// This module interface provides an abstraction for different network layers.
//
moduleinterface INetworkLayerUpper
{
    parameters:
        @display("i=block/fork");
    gates:
        input transportIn @labels(ITransportPacket/down);
        output transportOut @labels(ITransportPacket/up);
}

moduleinterface INetworkLayerLower
{
    parameters:
        @display("i=block/fork");
    gates:
        input ifInV[] @labels(INetworkHeader/up) @loose;
        output ifOutV[] @labels(INetworkHeader/down) @loose;
}

moduleinterface INetworkLayer extends INetworkLayerUpper, INetworkLayerLower
{
    parameters:
        @display("i=block/fork");
}

