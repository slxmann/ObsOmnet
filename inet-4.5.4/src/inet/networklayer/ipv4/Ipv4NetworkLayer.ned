//
// Copyright (C) 2004 OpenSim Ltd.
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

package inet.networklayer.ipv4;

import inet.common.MessageDispatcher;
import inet.networklayer.configurator.contract.IIpv4NodeConfigurator;
import inet.networklayer.contract.IArp;
import inet.networklayer.contract.INetworkLayer;

//
// Network layer of an IPv4 node.
//
//
module Ipv4NetworkLayer like INetworkLayer
{
    parameters:
        bool forwarding = default(false);
        bool multicastForwarding = default(false);
        string interfaceTableModule;
        string displayStringTextFormat = default("%i");
        *.forwarding = this.forwarding;
        *.multicastForwarding = this.multicastForwarding;
        *.interfaceTableModule = default(absPath(this.interfaceTableModule));
        *.routingTableModule = default(absPath(".routingTable"));
        *.arpModule = default(absPath(".arp"));
        *.icmpModule = default(absPath(".icmp"));
        @class(::inet::Ipv4NetworkLayer);
        @display("i=block/fork");

    gates:
//        input ifIn @labels(INetworkHeader) @loose;
//        output ifOut @labels(INetworkHeader) @loose;
		input ifInV[] @labels(INetworkHeader) @loose; // use ifInV++ if no len=1 is needed (dont add a for loop)
        output ifOutV[] @labels(INetworkHeader) @loose;
        input transportIn @labels(Ipv4ControlInfo/down);
        output transportOut @labels(Ipv4ControlInfo/up);

    submodules:
        configurator: <default("Ipv4NodeConfigurator")> like IIpv4NodeConfigurator if typename != "" {
            parameters:
                @display("p=100,100;is=s");
        }
        routingTable: Ipv4RoutingTable {
            parameters:
                @display("p=100,200;is=s");
        }
        natTable: Ipv4NatTable {
            parameters:
                @display("p=100,300;is=s");
        }
        up: MessageDispatcher {
            parameters:
                @display("p=550,100;b=600,5");
        }
        igmp: <default("Igmpv2")> like IIgmp {
            parameters:
                @display("p=400,200");
        }
        icmp: Icmp {
            parameters:
                @display("p=700,200");
        }
        mp: MessageDispatcher {
            parameters:
                @display("p=550,300;b=600,5");
        }
        ip: <default("Ipv4")> like IIpv4 {
            parameters:
                @display("p=700,400;q=queue");
        }
        arp: <default("Arp")> like IArp {
            parameters:
                @display("p=400,400;q=pendingQueue");
        }
        lp: MessageDispatcher {
            parameters:
                @display("p=550,500;b=600,5");
        }
    connections allowunconnected:
        transportIn --> { @display("m=n"); } --> up.in++;
        transportOut <-- { @display("m=n"); } <-- up.out++;

        up.out++ --> igmp.routerIn;
        up.in++ <-- igmp.routerOut;

        up.out++ --> mp.in++;
        up.in++ <-- mp.out++;

        up.out++ --> icmp.transportIn;
        up.in++ <-- icmp.transportOut;

        igmp.ipOut --> mp.in++;
        igmp.ipIn <-- mp.out++;

        icmp.ipOut --> mp.in++;
        icmp.ipIn <-- mp.out++;

        mp.out++ --> ip.transportIn;
        mp.in++ <-- ip.transportOut;

        arp.ifOut --> lp.in++;
        arp.ifIn <-- lp.out++;

        ip.queueOut --> lp.in++;
        ip.queueIn <-- lp.out++;
		
		for i=0..sizeof(ifOutV)-1{
            lp.out++ --> { @display("m=s"); } --> ifOutV[i];
		}
		for i=0..sizeof(ifInV)-1{
            lp.in++ <-- { @display("m=s"); } <-- ifInV[i];
		}
}

