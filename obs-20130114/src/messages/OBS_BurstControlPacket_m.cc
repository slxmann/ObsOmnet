//
// Generated file, do not edit! Created by opp_msgtool 6.1 from src/messages/OBS_BurstControlPacket.msg.
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
#include "OBS_BurstControlPacket_m.h"

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

Register_Class(OBS_BurstControlPacket)

OBS_BurstControlPacket::OBS_BurstControlPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

OBS_BurstControlPacket::OBS_BurstControlPacket(const OBS_BurstControlPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OBS_BurstControlPacket::~OBS_BurstControlPacket()
{
}

OBS_BurstControlPacket& OBS_BurstControlPacket::operator=(const OBS_BurstControlPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OBS_BurstControlPacket::copy(const OBS_BurstControlPacket& other)
{
    this->burstArrivalDelta = other.burstArrivalDelta;
    this->burstColour = other.burstColour;
    this->label = other.label;
    this->burstifierId = other.burstifierId;
    this->numSeq = other.numSeq;
    this->senderId = other.senderId;
    this->burstSize = other.burstSize;
}

void OBS_BurstControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->burstArrivalDelta);
    doParsimPacking(b,this->burstColour);
    doParsimPacking(b,this->label);
    doParsimPacking(b,this->burstifierId);
    doParsimPacking(b,this->numSeq);
    doParsimPacking(b,this->senderId);
    doParsimPacking(b,this->burstSize);
}

void OBS_BurstControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->burstArrivalDelta);
    doParsimUnpacking(b,this->burstColour);
    doParsimUnpacking(b,this->label);
    doParsimUnpacking(b,this->burstifierId);
    doParsimUnpacking(b,this->numSeq);
    doParsimUnpacking(b,this->senderId);
    doParsimUnpacking(b,this->burstSize);
}

omnetpp::simtime_t OBS_BurstControlPacket::getBurstArrivalDelta() const
{
    return this->burstArrivalDelta;
}

void OBS_BurstControlPacket::setBurstArrivalDelta(omnetpp::simtime_t burstArrivalDelta)
{
    this->burstArrivalDelta = burstArrivalDelta;
}

int OBS_BurstControlPacket::getBurstColour() const
{
    return this->burstColour;
}

void OBS_BurstControlPacket::setBurstColour(int burstColour)
{
    this->burstColour = burstColour;
}

int OBS_BurstControlPacket::getLabel() const
{
    return this->label;
}

void OBS_BurstControlPacket::setLabel(int label)
{
    this->label = label;
}

int OBS_BurstControlPacket::getBurstifierId() const
{
    return this->burstifierId;
}

void OBS_BurstControlPacket::setBurstifierId(int burstifierId)
{
    this->burstifierId = burstifierId;
}

int OBS_BurstControlPacket::getNumSeq() const
{
    return this->numSeq;
}

void OBS_BurstControlPacket::setNumSeq(int numSeq)
{
    this->numSeq = numSeq;
}

int OBS_BurstControlPacket::getSenderId() const
{
    return this->senderId;
}

void OBS_BurstControlPacket::setSenderId(int senderId)
{
    this->senderId = senderId;
}

int OBS_BurstControlPacket::getBurstSize() const
{
    return this->burstSize;
}

void OBS_BurstControlPacket::setBurstSize(int burstSize)
{
    this->burstSize = burstSize;
}

class OBS_BurstControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_burstArrivalDelta,
        FIELD_burstColour,
        FIELD_label,
        FIELD_burstifierId,
        FIELD_numSeq,
        FIELD_senderId,
        FIELD_burstSize,
    };
  public:
    OBS_BurstControlPacketDescriptor();
    virtual ~OBS_BurstControlPacketDescriptor();

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

Register_ClassDescriptor(OBS_BurstControlPacketDescriptor)

OBS_BurstControlPacketDescriptor::OBS_BurstControlPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(OBS_BurstControlPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

OBS_BurstControlPacketDescriptor::~OBS_BurstControlPacketDescriptor()
{
    delete[] propertyNames;
}

bool OBS_BurstControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_BurstControlPacket *>(obj)!=nullptr;
}

const char **OBS_BurstControlPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OBS_BurstControlPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OBS_BurstControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int OBS_BurstControlPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_burstArrivalDelta
        FD_ISEDITABLE,    // FIELD_burstColour
        FD_ISEDITABLE,    // FIELD_label
        FD_ISEDITABLE,    // FIELD_burstifierId
        FD_ISEDITABLE,    // FIELD_numSeq
        FD_ISEDITABLE,    // FIELD_senderId
        FD_ISEDITABLE,    // FIELD_burstSize
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *OBS_BurstControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "burstArrivalDelta",
        "burstColour",
        "label",
        "burstifierId",
        "numSeq",
        "senderId",
        "burstSize",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int OBS_BurstControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "burstArrivalDelta") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "burstColour") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "label") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "burstifierId") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "numSeq") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "senderId") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "burstSize") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *OBS_BurstControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_burstArrivalDelta
        "int",    // FIELD_burstColour
        "int",    // FIELD_label
        "int",    // FIELD_burstifierId
        "int",    // FIELD_numSeq
        "int",    // FIELD_senderId
        "int",    // FIELD_burstSize
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_BurstControlPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *OBS_BurstControlPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int OBS_BurstControlPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OBS_BurstControlPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OBS_BurstControlPacket'", field);
    }
}

const char *OBS_BurstControlPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OBS_BurstControlPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        case FIELD_burstArrivalDelta: return simtime2string(pp->getBurstArrivalDelta());
        case FIELD_burstColour: return long2string(pp->getBurstColour());
        case FIELD_label: return long2string(pp->getLabel());
        case FIELD_burstifierId: return long2string(pp->getBurstifierId());
        case FIELD_numSeq: return long2string(pp->getNumSeq());
        case FIELD_senderId: return long2string(pp->getSenderId());
        case FIELD_burstSize: return long2string(pp->getBurstSize());
        default: return "";
    }
}

void OBS_BurstControlPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        case FIELD_burstArrivalDelta: pp->setBurstArrivalDelta(string2simtime(value)); break;
        case FIELD_burstColour: pp->setBurstColour(string2long(value)); break;
        case FIELD_label: pp->setLabel(string2long(value)); break;
        case FIELD_burstifierId: pp->setBurstifierId(string2long(value)); break;
        case FIELD_numSeq: pp->setNumSeq(string2long(value)); break;
        case FIELD_senderId: pp->setSenderId(string2long(value)); break;
        case FIELD_burstSize: pp->setBurstSize(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_BurstControlPacket'", field);
    }
}

omnetpp::cValue OBS_BurstControlPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        case FIELD_burstArrivalDelta: return pp->getBurstArrivalDelta().dbl();
        case FIELD_burstColour: return pp->getBurstColour();
        case FIELD_label: return pp->getLabel();
        case FIELD_burstifierId: return pp->getBurstifierId();
        case FIELD_numSeq: return pp->getNumSeq();
        case FIELD_senderId: return pp->getSenderId();
        case FIELD_burstSize: return pp->getBurstSize();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OBS_BurstControlPacket' as cValue -- field index out of range?", field);
    }
}

void OBS_BurstControlPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        case FIELD_burstArrivalDelta: pp->setBurstArrivalDelta(value.doubleValue()); break;
        case FIELD_burstColour: pp->setBurstColour(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_label: pp->setLabel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_burstifierId: pp->setBurstifierId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numSeq: pp->setNumSeq(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_senderId: pp->setSenderId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_burstSize: pp->setBurstSize(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_BurstControlPacket'", field);
    }
}

const char *OBS_BurstControlPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr OBS_BurstControlPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OBS_BurstControlPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstControlPacket *pp = omnetpp::fromAnyPtr<OBS_BurstControlPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_BurstControlPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

