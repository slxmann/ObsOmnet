//
// Copyright (C) 2012 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package inet.networklayer.nexthop;

import inet.common.MessageDispatcher;
import inet.networklayer.arp.ipv4.GlobalArp;
import inet.networklayer.common.EchoProtocol;
import inet.networklayer.contract.INetworkLayer;

//
// This module provides a network layer for the next hop forwarding.
//
module NextHopNetworkLayer like INetworkLayer
{
    parameters:
        bool forwarding = default(false);
        bool multicastForwarding = default(false);
        string interfaceTableModule;
        *.forwarding = this.forwarding;
        *.multicastForwarding = this.multicastForwarding;
        *.interfaceTableModule = default(absPath(this.interfaceTableModule));
        *.routingTableModule = default(absPath(".routingTable"));
        *.arpModule = default(absPath(".arp"));
        @display("i=block/fork");
    gates:
        input ifInV[] @labels(INetworkHeader);
        output ifOutV[] @labels(INetworkHeader);
        input transportIn @labels(Ipv4ControlInfo/down);
        output transportOut @labels(Ipv4ControlInfo/up);

    submodules:
        routingTable: NextHopRoutingTable {
            parameters:
                @display("p=100,100;is=s");
        }
        echo: EchoProtocol {
            parameters:
                @display("p=600,100");
        }
        up: MessageDispatcher {
            parameters:
                @display("p=450,200;b=480,5");
        }
        arp: GlobalArp {
            parameters:
                @display("p=300,300;q=pendingQueue");
        }
        nextHop: NextHopForwarding {
            parameters:
                @display("p=600,300;q=queue");
        }
        lp: MessageDispatcher {
            parameters:
                @display("p=450,400;b=480,5");
        }

    connections allowunconnected:
        up.out++ --> { @display("m=n"); } --> transportOut;
        up.in++ <-- { @display("m=n"); } <-- transportIn;

        nextHop.transportOut --> up.in++;
        nextHop.transportIn <-- up.out++;

        up.out++ --> echo.ipIn;
        up.in++ <-- echo.ipOut;

        lp.out++ --> arp.ifIn;
        lp.in++ <-- arp.ifOut;

        lp.out++ --> nextHop.queueIn;
        lp.in++ <-- nextHop.queueOut;

        lp.in++ <-- { @display("m=s"); } <-- ifInV++;
        lp.out++ --> { @display("m=s"); } --> ifOutV++;
}

