//
// Generated file, do not edit! Created by opp_msgtool 6.1 from src/EdgeNode/OBS_ScheduledBurstItem.msg.
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
#include "OBS_ScheduledBurstItem_m.h"

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

Register_Class(OBS_ScheduledBurstItem)

OBS_ScheduledBurstItem::OBS_ScheduledBurstItem(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

OBS_ScheduledBurstItem::OBS_ScheduledBurstItem(const OBS_ScheduledBurstItem& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OBS_ScheduledBurstItem::~OBS_ScheduledBurstItem()
{
}

OBS_ScheduledBurstItem& OBS_ScheduledBurstItem::operator=(const OBS_ScheduledBurstItem& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OBS_ScheduledBurstItem::copy(const OBS_ScheduledBurstItem& other)
{
    this->listIndex = other.listIndex;
    this->burstId = other.burstId;
    this->sendTime = other.sendTime;
    this->minOffset = other.minOffset;
    this->maxOffset = other.maxOffset;
}

void OBS_ScheduledBurstItem::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->listIndex);
    doParsimPacking(b,this->burstId);
    doParsimPacking(b,this->sendTime);
    doParsimPacking(b,this->minOffset);
    doParsimPacking(b,this->maxOffset);
}

void OBS_ScheduledBurstItem::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->listIndex);
    doParsimUnpacking(b,this->burstId);
    doParsimUnpacking(b,this->sendTime);
    doParsimUnpacking(b,this->minOffset);
    doParsimUnpacking(b,this->maxOffset);
}

int OBS_ScheduledBurstItem::getListIndex() const
{
    return this->listIndex;
}

void OBS_ScheduledBurstItem::setListIndex(int listIndex)
{
    this->listIndex = listIndex;
}

int OBS_ScheduledBurstItem::getBurstId() const
{
    return this->burstId;
}

void OBS_ScheduledBurstItem::setBurstId(int burstId)
{
    this->burstId = burstId;
}

omnetpp::simtime_t OBS_ScheduledBurstItem::getSendTime() const
{
    return this->sendTime;
}

void OBS_ScheduledBurstItem::setSendTime(omnetpp::simtime_t sendTime)
{
    this->sendTime = sendTime;
}

omnetpp::simtime_t OBS_ScheduledBurstItem::getMinOffset() const
{
    return this->minOffset;
}

void OBS_ScheduledBurstItem::setMinOffset(omnetpp::simtime_t minOffset)
{
    this->minOffset = minOffset;
}

omnetpp::simtime_t OBS_ScheduledBurstItem::getMaxOffset() const
{
    return this->maxOffset;
}

void OBS_ScheduledBurstItem::setMaxOffset(omnetpp::simtime_t maxOffset)
{
    this->maxOffset = maxOffset;
}

class OBS_ScheduledBurstItemDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_listIndex,
        FIELD_burstId,
        FIELD_sendTime,
        FIELD_minOffset,
        FIELD_maxOffset,
    };
  public:
    OBS_ScheduledBurstItemDescriptor();
    virtual ~OBS_ScheduledBurstItemDescriptor();

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

Register_ClassDescriptor(OBS_ScheduledBurstItemDescriptor)

OBS_ScheduledBurstItemDescriptor::OBS_ScheduledBurstItemDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(OBS_ScheduledBurstItem)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

OBS_ScheduledBurstItemDescriptor::~OBS_ScheduledBurstItemDescriptor()
{
    delete[] propertyNames;
}

bool OBS_ScheduledBurstItemDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_ScheduledBurstItem *>(obj)!=nullptr;
}

const char **OBS_ScheduledBurstItemDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OBS_ScheduledBurstItemDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OBS_ScheduledBurstItemDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int OBS_ScheduledBurstItemDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_listIndex
        FD_ISEDITABLE,    // FIELD_burstId
        FD_ISEDITABLE,    // FIELD_sendTime
        FD_ISEDITABLE,    // FIELD_minOffset
        FD_ISEDITABLE,    // FIELD_maxOffset
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "listIndex",
        "burstId",
        "sendTime",
        "minOffset",
        "maxOffset",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int OBS_ScheduledBurstItemDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "listIndex") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "burstId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sendTime") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "minOffset") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "maxOffset") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_listIndex
        "int",    // FIELD_burstId
        "omnetpp::simtime_t",    // FIELD_sendTime
        "omnetpp::simtime_t",    // FIELD_minOffset
        "omnetpp::simtime_t",    // FIELD_maxOffset
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_ScheduledBurstItemDescriptor::getFieldPropertyNames(int field) const
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

const char *OBS_ScheduledBurstItemDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int OBS_ScheduledBurstItemDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OBS_ScheduledBurstItemDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OBS_ScheduledBurstItem'", field);
    }
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OBS_ScheduledBurstItemDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        case FIELD_listIndex: return long2string(pp->getListIndex());
        case FIELD_burstId: return long2string(pp->getBurstId());
        case FIELD_sendTime: return simtime2string(pp->getSendTime());
        case FIELD_minOffset: return simtime2string(pp->getMinOffset());
        case FIELD_maxOffset: return simtime2string(pp->getMaxOffset());
        default: return "";
    }
}

void OBS_ScheduledBurstItemDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        case FIELD_listIndex: pp->setListIndex(string2long(value)); break;
        case FIELD_burstId: pp->setBurstId(string2long(value)); break;
        case FIELD_sendTime: pp->setSendTime(string2simtime(value)); break;
        case FIELD_minOffset: pp->setMinOffset(string2simtime(value)); break;
        case FIELD_maxOffset: pp->setMaxOffset(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_ScheduledBurstItem'", field);
    }
}

omnetpp::cValue OBS_ScheduledBurstItemDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        case FIELD_listIndex: return pp->getListIndex();
        case FIELD_burstId: return pp->getBurstId();
        case FIELD_sendTime: return pp->getSendTime().dbl();
        case FIELD_minOffset: return pp->getMinOffset().dbl();
        case FIELD_maxOffset: return pp->getMaxOffset().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OBS_ScheduledBurstItem' as cValue -- field index out of range?", field);
    }
}

void OBS_ScheduledBurstItemDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        case FIELD_listIndex: pp->setListIndex(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_burstId: pp->setBurstId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sendTime: pp->setSendTime(value.doubleValue()); break;
        case FIELD_minOffset: pp->setMinOffset(value.doubleValue()); break;
        case FIELD_maxOffset: pp->setMaxOffset(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_ScheduledBurstItem'", field);
    }
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr OBS_ScheduledBurstItemDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OBS_ScheduledBurstItemDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = omnetpp::fromAnyPtr<OBS_ScheduledBurstItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_ScheduledBurstItem'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

