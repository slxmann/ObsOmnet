//
// Generated file, do not edit! Created by opp_msgtool 6.1 from src/EdgeNode/OBS_BurstSenderInfo.msg.
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
#include "OBS_BurstSenderInfo_m.h"

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

Register_Class(OBS_BurstSenderInfo)

OBS_BurstSenderInfo::OBS_BurstSenderInfo() : ::omnetpp::cObject()
{
}

OBS_BurstSenderInfo::OBS_BurstSenderInfo(const OBS_BurstSenderInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OBS_BurstSenderInfo::~OBS_BurstSenderInfo()
{
}

OBS_BurstSenderInfo& OBS_BurstSenderInfo::operator=(const OBS_BurstSenderInfo& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OBS_BurstSenderInfo::copy(const OBS_BurstSenderInfo& other)
{
    this->burstId = other.burstId;
    this->burstifierId = other.burstifierId;
    this->numSeq = other.numSeq;
    this->assignedLambda = other.assignedLambda;
    this->label = other.label;
}

void OBS_BurstSenderInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->burstId);
    doParsimPacking(b,this->burstifierId);
    doParsimPacking(b,this->numSeq);
    doParsimPacking(b,this->assignedLambda);
    doParsimPacking(b,this->label);
}

void OBS_BurstSenderInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->burstId);
    doParsimUnpacking(b,this->burstifierId);
    doParsimUnpacking(b,this->numSeq);
    doParsimUnpacking(b,this->assignedLambda);
    doParsimUnpacking(b,this->label);
}

int OBS_BurstSenderInfo::getBurstId() const
{
    return this->burstId;
}

void OBS_BurstSenderInfo::setBurstId(int burstId)
{
    this->burstId = burstId;
}

int OBS_BurstSenderInfo::getBurstifierId() const
{
    return this->burstifierId;
}

void OBS_BurstSenderInfo::setBurstifierId(int burstifierId)
{
    this->burstifierId = burstifierId;
}

int OBS_BurstSenderInfo::getNumSeq() const
{
    return this->numSeq;
}

void OBS_BurstSenderInfo::setNumSeq(int numSeq)
{
    this->numSeq = numSeq;
}

int OBS_BurstSenderInfo::getAssignedLambda() const
{
    return this->assignedLambda;
}

void OBS_BurstSenderInfo::setAssignedLambda(int assignedLambda)
{
    this->assignedLambda = assignedLambda;
}

int OBS_BurstSenderInfo::getLabel() const
{
    return this->label;
}

void OBS_BurstSenderInfo::setLabel(int label)
{
    this->label = label;
}

class OBS_BurstSenderInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_burstId,
        FIELD_burstifierId,
        FIELD_numSeq,
        FIELD_assignedLambda,
        FIELD_label,
    };
  public:
    OBS_BurstSenderInfoDescriptor();
    virtual ~OBS_BurstSenderInfoDescriptor();

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

Register_ClassDescriptor(OBS_BurstSenderInfoDescriptor)

OBS_BurstSenderInfoDescriptor::OBS_BurstSenderInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(OBS_BurstSenderInfo)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

OBS_BurstSenderInfoDescriptor::~OBS_BurstSenderInfoDescriptor()
{
    delete[] propertyNames;
}

bool OBS_BurstSenderInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_BurstSenderInfo *>(obj)!=nullptr;
}

const char **OBS_BurstSenderInfoDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OBS_BurstSenderInfoDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OBS_BurstSenderInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int OBS_BurstSenderInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_burstId
        FD_ISEDITABLE,    // FIELD_burstifierId
        FD_ISEDITABLE,    // FIELD_numSeq
        FD_ISEDITABLE,    // FIELD_assignedLambda
        FD_ISEDITABLE,    // FIELD_label
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *OBS_BurstSenderInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "burstId",
        "burstifierId",
        "numSeq",
        "assignedLambda",
        "label",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int OBS_BurstSenderInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "burstId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "burstifierId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "numSeq") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "assignedLambda") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "label") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *OBS_BurstSenderInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_burstId
        "int",    // FIELD_burstifierId
        "int",    // FIELD_numSeq
        "int",    // FIELD_assignedLambda
        "int",    // FIELD_label
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_BurstSenderInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *OBS_BurstSenderInfoDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int OBS_BurstSenderInfoDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OBS_BurstSenderInfoDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OBS_BurstSenderInfo'", field);
    }
}

const char *OBS_BurstSenderInfoDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OBS_BurstSenderInfoDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        case FIELD_burstId: return long2string(pp->getBurstId());
        case FIELD_burstifierId: return long2string(pp->getBurstifierId());
        case FIELD_numSeq: return long2string(pp->getNumSeq());
        case FIELD_assignedLambda: return long2string(pp->getAssignedLambda());
        case FIELD_label: return long2string(pp->getLabel());
        default: return "";
    }
}

void OBS_BurstSenderInfoDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        case FIELD_burstId: pp->setBurstId(string2long(value)); break;
        case FIELD_burstifierId: pp->setBurstifierId(string2long(value)); break;
        case FIELD_numSeq: pp->setNumSeq(string2long(value)); break;
        case FIELD_assignedLambda: pp->setAssignedLambda(string2long(value)); break;
        case FIELD_label: pp->setLabel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_BurstSenderInfo'", field);
    }
}

omnetpp::cValue OBS_BurstSenderInfoDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        case FIELD_burstId: return pp->getBurstId();
        case FIELD_burstifierId: return pp->getBurstifierId();
        case FIELD_numSeq: return pp->getNumSeq();
        case FIELD_assignedLambda: return pp->getAssignedLambda();
        case FIELD_label: return pp->getLabel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OBS_BurstSenderInfo' as cValue -- field index out of range?", field);
    }
}

void OBS_BurstSenderInfoDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        case FIELD_burstId: pp->setBurstId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_burstifierId: pp->setBurstifierId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numSeq: pp->setNumSeq(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_assignedLambda: pp->setAssignedLambda(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_label: pp->setLabel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_BurstSenderInfo'", field);
    }
}

const char *OBS_BurstSenderInfoDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr OBS_BurstSenderInfoDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OBS_BurstSenderInfoDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_BurstSenderInfo *pp = omnetpp::fromAnyPtr<OBS_BurstSenderInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_BurstSenderInfo'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

