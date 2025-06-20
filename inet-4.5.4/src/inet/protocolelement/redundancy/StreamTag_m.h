//
// Generated file, do not edit! Created by opp_msgtool 6.1 from inet/protocolelement/redundancy/StreamTag.msg.
//

#ifndef __INET_STREAMTAG_M_H
#define __INET_STREAMTAG_M_H

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

class StreamTagBase;
class StreamReq;
class StreamInd;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/protocolelement/redundancy/StreamTag.msg:16</tt> by opp_msgtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class StreamTagBase extends TagBase
 * {
 *     string streamName;
 * }
 * </pre>
 */
class INET_API StreamTagBase : public ::inet::TagBase
{
  protected:
    ::omnetpp::opp_string streamName;

  private:
    void copy(const StreamTagBase& other);

  protected:
    bool operator==(const StreamTagBase&) = delete;

  public:
    StreamTagBase();
    StreamTagBase(const StreamTagBase& other);
    virtual ~StreamTagBase();
    StreamTagBase& operator=(const StreamTagBase& other);
    virtual StreamTagBase *dup() const override {return new StreamTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const char * getStreamName() const;
    virtual void setStreamName(const char * streamName);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const StreamTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, StreamTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/protocolelement/redundancy/StreamTag.msg:25</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the stream that should be used to send the packet.
 * // It may be present on a packet from the application to the mac protocol.
 * //
 * class StreamReq extends StreamTagBase
 * {
 * }
 * </pre>
 */
class INET_API StreamReq : public ::inet::StreamTagBase
{
  protected:

  private:
    void copy(const StreamReq& other);

  protected:
    bool operator==(const StreamReq&) = delete;

  public:
    StreamReq();
    StreamReq(const StreamReq& other);
    virtual ~StreamReq();
    StreamReq& operator=(const StreamReq& other);
    virtual StreamReq *dup() const override {return new StreamReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const StreamReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, StreamReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/protocolelement/redundancy/StreamTag.msg:33</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication specifies the stream that was used to receive the packet.
 * // It may be present on a packet from the mac protocol to the application.
 * //
 * class StreamInd extends StreamTagBase
 * {
 * }
 * </pre>
 */
class INET_API StreamInd : public ::inet::StreamTagBase
{
  protected:

  private:
    void copy(const StreamInd& other);

  protected:
    bool operator==(const StreamInd&) = delete;

  public:
    StreamInd();
    StreamInd(const StreamInd& other);
    virtual ~StreamInd();
    StreamInd& operator=(const StreamInd& other);
    virtual StreamInd *dup() const override {return new StreamInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const StreamInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, StreamInd& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::StreamTagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::StreamTagBase*>(ptr.get<cObject>()); }
template<> inline inet::StreamReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::StreamReq*>(ptr.get<cObject>()); }
template<> inline inet::StreamInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::StreamInd*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_STREAMTAG_M_H

