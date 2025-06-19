//
// Generated file, do not edit! Created by opp_msgtool 6.1 from ../../obs-20130114/src/messages/OBS_Burst.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "OBS_Burst_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

OBS_Burst_Base::OBS_Burst_Base(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

OBS_Burst_Base::OBS_Burst_Base(const OBS_Burst_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OBS_Burst_Base::~OBS_Burst_Base()
{
}

OBS_Burst_Base& OBS_Burst_Base::operator=(const OBS_Burst_Base& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OBS_Burst_Base::copy(const OBS_Burst_Base& other)
{
    this->messages = other.messages;
    this->numPackets = other.numPackets;
    this->minOffset = other.minOffset;
    this->maxOffset = other.maxOffset;
    this->burstifierId = other.burstifierId;
    this->numSeq = other.numSeq;
    this->senderId = other.senderId;
}

void OBS_Burst_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->messages);
    doParsimPacking(b,this->numPackets);
    doParsimPacking(b,this->minOffset);
    doParsimPacking(b,this->maxOffset);
    doParsimPacking(b,this->burstifierId);
    doParsimPacking(b,this->numSeq);
    doParsimPacking(b,this->senderId);
}

void OBS_Burst_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->messages);
    doParsimUnpacking(b,this->numPackets);
    doParsimUnpacking(b,this->minOffset);
    doParsimUnpacking(b,this->maxOffset);
    doParsimUnpacking(b,this->burstifierId);
    doParsimUnpacking(b,this->numSeq);
    doParsimUnpacking(b,this->senderId);
}

const omnetpp::cPacket * OBS_Burst_Base::getMessages() const
{
    return this->messages;
}

void OBS_Burst_Base::setMessages(omnetpp::cPacket * messages)
{
    this->messages = messages;
}

int OBS_Burst_Base::getNumPackets() const
{
    return this->numPackets;
}

void OBS_Burst_Base::setNumPackets(int numPackets)
{
    this->numPackets = numPackets;
}

omnetpp::simtime_t OBS_Burst_Base::getMinOffset() const
{
    return this->minOffset;
}

void OBS_Burst_Base::setMinOffset(omnetpp::simtime_t minOffset)
{
    this->minOffset = minOffset;
}

omnetpp::simtime_t OBS_Burst_Base::getMaxOffset() const
{
    return this->maxOffset;
}

void OBS_Burst_Base::setMaxOffset(omnetpp::simtime_t maxOffset)
{
    this->maxOffset = maxOffset;
}

int OBS_Burst_Base::getBurstifierId() const
{
    return this->burstifierId;
}

void OBS_Burst_Base::setBurstifierId(int burstifierId)
{
    this->burstifierId = burstifierId;
}

int OBS_Burst_Base::getNumSeq() const
{
    return this->numSeq;
}

void OBS_Burst_Base::setNumSeq(int numSeq)
{
    this->numSeq = numSeq;
}

int OBS_Burst_Base::getSenderId() const
{
    return this->senderId;
}

void OBS_Burst_Base::setSenderId(int senderId)
{
    this->senderId = senderId;
}

class OBS_BurstDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_messages,
        FIELD_numPackets,
        FIELD_minOffset,
        FIELD_maxOffset,
        FIELD_burstifierId,
        FIELD_numSeq,
        FIELD_senderId,
    };
  public:
    OBS_BurstDescriptor();
    virtual ~OBS_BurstDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(OBS_BurstDescriptor)

OBS_BurstDescriptor::OBS_BurstDescriptor() : omnetpp::cClassDescriptor("OBS_Burst", "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

OBS_BurstDescriptor::~OBS_BurstDescriptor()
{
    delete[] propertyNames;
}

bool OBS_BurstDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_Burst_Base *>(obj)!=nullptr;
}

const char **OBS_BurstDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OBS_BurstDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "customize")) return "true";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OBS_BurstDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int OBS_BurstDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT | FD_ISREPLACEABLE,    // FIELD_messages
        FD_ISEDITABLE,    // FIELD_numPackets
        FD_ISEDITABLE,    // FIELD_minOffset
        FD_ISEDITABLE,    // FIELD_maxOffset
        FD_ISEDITABLE,    // FIELD_burstifierId
        FD_ISEDITABLE,    // FIELD_numSeq
        FD_ISEDITABLE,    // FIELD_senderId
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *OBS_BurstDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messages",
        "numPackets",
        "minOffset",
        "maxOffset",
        "burstifierId",
        "numSeq",
        "senderId",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int OBS_BurstDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "messages") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numPackets") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "minOffset") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "maxOffset") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "burstifierId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "numSeq") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "senderId") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *OBS_BurstDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::cPacket",    // FIELD_messages
        "int",    // FIELD_numPackets
        "omnetpp::simtime_t",    // FIELD_minOffset
        "omnetpp::simtime_t",    // FIELD_maxOffset
        "int",    // FIELD_burstifierId
        "int",    // FIELD_numSeq
        "int",    // FIELD_senderId
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_BurstDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OBS_BurstDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OBS_BurstDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OBS_BurstDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OBS_Burst_Base'", field);
    }
}

const char *OBS_BurstDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_messages: { const omnetpp::cPacket * value = pp->getMessages(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string OBS_BurstDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_messages: { auto obj = pp->getMessages(); return obj == nullptr ? "" : obj->str(); }
        case FIELD_numPackets: return long2string(pp->getNumPackets());
        case FIELD_minOffset: return simtime2string(pp->getMinOffset());
        case FIELD_maxOffset: return simtime2string(pp->getMaxOffset());
        case FIELD_burstifierId: return long2string(pp->getBurstifierId());
        case FIELD_numSeq: return long2string(pp->getNumSeq());
        case FIELD_senderId: return long2string(pp->getSenderId());
        default: return "";
    }
}

void OBS_BurstDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_numPackets: pp->setNumPackets(string2long(value)); break;
        case FIELD_minOffset: pp->setMinOffset(string2simtime(value)); break;
        case FIELD_maxOffset: pp->setMaxOffset(string2simtime(value)); break;
        case FIELD_burstifierId: pp->setBurstifierId(string2long(value)); break;
        case FIELD_numSeq: pp->setNumSeq(string2long(value)); break;
        case FIELD_senderId: pp->setSenderId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_Burst_Base'", field);
    }
}

omnetpp::cValue OBS_BurstDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_messages: return omnetpp::toAnyPtr(pp->getMessages()); break;
        case FIELD_numPackets: return pp->getNumPackets();
        case FIELD_minOffset: return pp->getMinOffset().dbl();
        case FIELD_maxOffset: return pp->getMaxOffset().dbl();
        case FIELD_burstifierId: return pp->getBurstifierId();
        case FIELD_numSeq: return pp->getNumSeq();
        case FIELD_senderId: return pp->getSenderId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OBS_Burst_Base' as cValue -- field index out of range?", field);
    }
}

void OBS_BurstDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_messages: pp->setMessages(omnetpp::fromAnyPtr<omnetpp::cPacket>(value.pointerValue())); break;
        case FIELD_numPackets: pp->setNumPackets(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_minOffset: pp->setMinOffset(value.doubleValue()); break;
        case FIELD_maxOffset: pp->setMaxOffset(value.doubleValue()); break;
        case FIELD_burstifierId: pp->setBurstifierId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numSeq: pp->setNumSeq(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_senderId: pp->setSenderId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_Burst_Base'", field);
    }
}

const char *OBS_BurstDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_messages: return omnetpp::opp_typename(typeid(omnetpp::cPacket));
        default: return nullptr;
    };
}

omnetpp::any_ptr OBS_BurstDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_messages: return omnetpp::toAnyPtr(pp->getMessages()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OBS_BurstDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_Burst_Base *pp = omnetpp::fromAnyPtr<OBS_Burst_Base>(object); (void)pp;
    switch (field) {
        case FIELD_messages: pp->setMessages(omnetpp::fromAnyPtr<omnetpp::cPacket>(ptr)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_Burst_Base'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

