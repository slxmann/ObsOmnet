//
// Generated file, do not edit! Created by opp_msgtool 6.1 from inet/networklayer/wiseroute/WiseRouteHeader.msg.
//

#ifndef __INET_WISEROUTEHEADER_M_H
#define __INET_WISEROUTEHEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0601
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class WiseRouteHeader;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/networklayer/common/IpProtocolId_m.h" // import inet.networklayer.common.IpProtocolId

#include "inet/networklayer/contract/NetworkHeaderBase_m.h" // import inet.networklayer.contract.NetworkHeaderBase

// cplusplus {{
#include "inet/common/ProtocolGroup.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/networklayer/wiseroute/WiseRouteHeader.msg:17</tt> by opp_msgtool.
 * <pre>
 * enum WiseRouteMsgType
 * {
 *     DATA = 1;
 *     ROUTE_FLOOD = 2;
 * }
 * </pre>
 */
enum WiseRouteMsgType {
    DATA = 1,
    ROUTE_FLOOD = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const WiseRouteMsgType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, WiseRouteMsgType& e) { int n; b->unpack(n); e = static_cast<WiseRouteMsgType>(n); }

/**
 * Class generated from <tt>inet/networklayer/wiseroute/WiseRouteHeader.msg:23</tt> by opp_msgtool.
 * <pre>
 * class WiseRouteHeader extends NetworkHeaderBase
 * {
 *     L3Address srcAddr;
 *     L3Address destAddr;
 *     unsigned long seqNum = 0;
 *     int isFlood;
 *     int nbHops;
 *     WiseRouteMsgType headerKind = static_cast<WiseRouteMsgType>(-1);
 *     IpProtocolId protocolId;
 *     L3Address finalDestAddr;
 *     L3Address initialSrcAddr;
 *     B payloadLengthField;
 * }
 * </pre>
 */
class INET_API WiseRouteHeader : public ::inet::NetworkHeaderBase
{
  protected:
    L3Address srcAddr;
    L3Address destAddr;
    unsigned long seqNum = 0;
    int isFlood = 0;
    int nbHops = 0;
    WiseRouteMsgType headerKind = static_cast<WiseRouteMsgType>(-1);
    IpProtocolId protocolId = static_cast<inet::IpProtocolId>(-1);
    L3Address finalDestAddr;
    L3Address initialSrcAddr;
    B payloadLengthField = B(-1);

  private:
    void copy(const WiseRouteHeader& other);

  protected:
    bool operator==(const WiseRouteHeader&) = delete;

  public:
    WiseRouteHeader();
    WiseRouteHeader(const WiseRouteHeader& other);
    virtual ~WiseRouteHeader();
    WiseRouteHeader& operator=(const WiseRouteHeader& other);
    virtual WiseRouteHeader *dup() const override {return new WiseRouteHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const L3Address& getSrcAddr() const;
    virtual L3Address& getSrcAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<WiseRouteHeader*>(this)->getSrcAddr());}
    virtual void setSrcAddr(const L3Address& srcAddr);

    virtual const L3Address& getDestAddr() const;
    virtual L3Address& getDestAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<WiseRouteHeader*>(this)->getDestAddr());}
    virtual void setDestAddr(const L3Address& destAddr);

    virtual unsigned long getSeqNum() const;
    virtual void setSeqNum(unsigned long seqNum);

    virtual int getIsFlood() const;
    virtual void setIsFlood(int isFlood);

    virtual int getNbHops() const;
    virtual void setNbHops(int nbHops);

    virtual WiseRouteMsgType getHeaderKind() const;
    virtual void setHeaderKind(WiseRouteMsgType headerKind);

    virtual IpProtocolId getProtocolId() const;
    virtual void setProtocolId(IpProtocolId protocolId);

    virtual const L3Address& getFinalDestAddr() const;
    virtual L3Address& getFinalDestAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<WiseRouteHeader*>(this)->getFinalDestAddr());}
    virtual void setFinalDestAddr(const L3Address& finalDestAddr);

    virtual const L3Address& getInitialSrcAddr() const;
    virtual L3Address& getInitialSrcAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<WiseRouteHeader*>(this)->getInitialSrcAddr());}
    virtual void setInitialSrcAddr(const L3Address& initialSrcAddr);

    virtual B getPayloadLengthField() const;
    virtual void setPayloadLengthField(B payloadLengthField);


  public:
    virtual L3Address getSourceAddress() const override { return L3Address(getSrcAddr()); }
    virtual void setSourceAddress(const L3Address& address) override { setSrcAddr(address); }
    virtual L3Address getDestinationAddress() const override { return L3Address(getDestAddr()); }
    virtual void setDestinationAddress(const L3Address& address) override { setDestAddr(address); }
    virtual const Protocol *getProtocol() const override { return ProtocolGroup::getIpProtocolGroup()->findProtocol(getProtocolId()); }
    virtual void setProtocol(const Protocol *protocol) override { setProtocolId(static_cast<IpProtocolId>(ProtocolGroup::getIpProtocolGroup()->getProtocolNumber(protocol))); }
    virtual bool isFragment() const override { return false; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const WiseRouteHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, WiseRouteHeader& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::WiseRouteHeader *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::WiseRouteHeader*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_WISEROUTEHEADER_M_H

