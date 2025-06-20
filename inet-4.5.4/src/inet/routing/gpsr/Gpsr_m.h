//
// Generated file, do not edit! Created by opp_msgtool 6.1 from inet/routing/gpsr/Gpsr.msg.
//

#ifndef __INET_GPSR_M_H
#define __INET_GPSR_M_H

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

class GpsrBeacon;
class GpsrOption;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TlvOptions_m.h" // import inet.common.TlvOptions

#include "inet/common/geometry/Geometry_m.h" // import inet.common.geometry.Geometry

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/common/L3Address_m.h" // import inet.networklayer.common.L3Address

// cplusplus {{
#include "inet/routing/gpsr/GpsrDefs.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/routing/gpsr/Gpsr.msg:19</tt> by opp_msgtool.
 * <pre>
 * enum GpsrForwardingMode
 * {
 *     GPSR_GREEDY_ROUTING = 1;
 *     GPSR_PERIMETER_ROUTING = 2;
 * }
 * </pre>
 */
enum GpsrForwardingMode {
    GPSR_GREEDY_ROUTING = 1,
    GPSR_PERIMETER_ROUTING = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const GpsrForwardingMode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, GpsrForwardingMode& e) { int n; b->unpack(n); e = static_cast<GpsrForwardingMode>(n); }

/**
 * Enum generated from <tt>inet/routing/gpsr/Gpsr.msg:24</tt> by opp_msgtool.
 * <pre>
 * enum GpsrPlanarizationMode
 * {
 *     GPSR_NO_PLANARIZATION = 0;
 *     GPSR_GG_PLANARIZATION = 1;
 *     GPSR_RNG_PLANARIZATION = 2;
 * }
 * </pre>
 */
enum GpsrPlanarizationMode {
    GPSR_NO_PLANARIZATION = 0,
    GPSR_GG_PLANARIZATION = 1,
    GPSR_RNG_PLANARIZATION = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const GpsrPlanarizationMode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, GpsrPlanarizationMode& e) { int n; b->unpack(n); e = static_cast<GpsrPlanarizationMode>(n); }

/**
 * Class generated from <tt>inet/routing/gpsr/Gpsr.msg:35</tt> by opp_msgtool.
 * <pre>
 * //
 * // The GPSR beacon packet is sent periodically by all GPSR routers to notify
 * // the neighbors about the router's address and position.
 * //
 * class GpsrBeacon extends FieldsChunk
 * {
 *     L3Address address;
 *     Coord position;
 * }
 * </pre>
 */
class INET_API GpsrBeacon : public ::inet::FieldsChunk
{
  protected:
    L3Address address;
    Coord position;

  private:
    void copy(const GpsrBeacon& other);

  protected:
    bool operator==(const GpsrBeacon&) = delete;

  public:
    GpsrBeacon();
    GpsrBeacon(const GpsrBeacon& other);
    virtual ~GpsrBeacon();
    GpsrBeacon& operator=(const GpsrBeacon& other);
    virtual GpsrBeacon *dup() const override {return new GpsrBeacon(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const L3Address& getAddress() const;
    virtual L3Address& getAddressForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<GpsrBeacon*>(this)->getAddress());}
    virtual void setAddress(const L3Address& address);

    virtual const Coord& getPosition() const;
    virtual Coord& getPositionForUpdate() { handleChange();return const_cast<Coord&>(const_cast<GpsrBeacon*>(this)->getPosition());}
    virtual void setPosition(const Coord& position);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const GpsrBeacon& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, GpsrBeacon& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/gpsr/Gpsr.msg:46</tt> by opp_msgtool.
 * <pre>
 * //
 * // The GPSROption is used to add extra routing information for network datagrams.
 * //
 * // For more information, see the GPSR paper
 * // http://www.eecs.harvard.edu/~htk/publication/2000-mobi-karp-kung.pdf
 * //
 * class GpsrOption extends TlvOptionBase
 * {
 *     GpsrForwardingMode routingMode;
 *     Coord destinationPosition;               // D
 *     Coord perimeterRoutingStartPosition;     // Lp
 *     Coord perimeterRoutingForwardPosition;   // Lf
 *     L3Address currentFaceFirstSenderAddress;   // e0
 *     L3Address currentFaceFirstReceiverAddress; // e0
 *     L3Address senderAddress; // TODO this field is not strictly needed by GPSR (should be eliminated)
 * }
 * </pre>
 */
class INET_API GpsrOption : public ::inet::TlvOptionBase
{
  protected:
    GpsrForwardingMode routingMode = static_cast<inet::GpsrForwardingMode>(-1);
    Coord destinationPosition;
    Coord perimeterRoutingStartPosition;
    Coord perimeterRoutingForwardPosition;
    L3Address currentFaceFirstSenderAddress;
    L3Address currentFaceFirstReceiverAddress;
    L3Address senderAddress;

  private:
    void copy(const GpsrOption& other);

  protected:
    bool operator==(const GpsrOption&) = delete;

  public:
    GpsrOption();
    GpsrOption(const GpsrOption& other);
    virtual ~GpsrOption();
    GpsrOption& operator=(const GpsrOption& other);
    virtual GpsrOption *dup() const override {return new GpsrOption(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual GpsrForwardingMode getRoutingMode() const;
    virtual void setRoutingMode(GpsrForwardingMode routingMode);

    virtual const Coord& getDestinationPosition() const;
    virtual Coord& getDestinationPositionForUpdate() { return const_cast<Coord&>(const_cast<GpsrOption*>(this)->getDestinationPosition());}
    virtual void setDestinationPosition(const Coord& destinationPosition);

    virtual const Coord& getPerimeterRoutingStartPosition() const;
    virtual Coord& getPerimeterRoutingStartPositionForUpdate() { return const_cast<Coord&>(const_cast<GpsrOption*>(this)->getPerimeterRoutingStartPosition());}
    virtual void setPerimeterRoutingStartPosition(const Coord& perimeterRoutingStartPosition);

    virtual const Coord& getPerimeterRoutingForwardPosition() const;
    virtual Coord& getPerimeterRoutingForwardPositionForUpdate() { return const_cast<Coord&>(const_cast<GpsrOption*>(this)->getPerimeterRoutingForwardPosition());}
    virtual void setPerimeterRoutingForwardPosition(const Coord& perimeterRoutingForwardPosition);

    virtual const L3Address& getCurrentFaceFirstSenderAddress() const;
    virtual L3Address& getCurrentFaceFirstSenderAddressForUpdate() { return const_cast<L3Address&>(const_cast<GpsrOption*>(this)->getCurrentFaceFirstSenderAddress());}
    virtual void setCurrentFaceFirstSenderAddress(const L3Address& currentFaceFirstSenderAddress);

    virtual const L3Address& getCurrentFaceFirstReceiverAddress() const;
    virtual L3Address& getCurrentFaceFirstReceiverAddressForUpdate() { return const_cast<L3Address&>(const_cast<GpsrOption*>(this)->getCurrentFaceFirstReceiverAddress());}
    virtual void setCurrentFaceFirstReceiverAddress(const L3Address& currentFaceFirstReceiverAddress);

    virtual const L3Address& getSenderAddress() const;
    virtual L3Address& getSenderAddressForUpdate() { return const_cast<L3Address&>(const_cast<GpsrOption*>(this)->getSenderAddress());}
    virtual void setSenderAddress(const L3Address& senderAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const GpsrOption& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, GpsrOption& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::GpsrBeacon *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::GpsrBeacon*>(ptr.get<cObject>()); }
template<> inline inet::GpsrOption *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::GpsrOption*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_GPSR_M_H

