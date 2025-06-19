//
// Generated file, do not edit! Created by opp_msgtool 6.1 from src/CoreNode/OBS_CoreRoutingTableEntry.msg.
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
#include "OBS_CoreRoutingTableEntry_m.h"

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

Register_Class(OBS_CoreRoutingTableEntry)

OBS_CoreRoutingTableEntry::OBS_CoreRoutingTableEntry() : ::omnetpp::cObject()
{
}

OBS_CoreRoutingTableEntry::OBS_CoreRoutingTableEntry(const OBS_CoreRoutingTableEntry& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OBS_CoreRoutingTableEntry::~OBS_CoreRoutingTableEntry()
{
}

OBS_CoreRoutingTableEntry& OBS_CoreRoutingTableEntry::operator=(const OBS_CoreRoutingTableEntry& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OBS_CoreRoutingTableEntry::copy(const OBS_CoreRoutingTableEntry& other)
{
    this->inPort = other.inPort;
    this->inColour = other.inColour;
    this->inLabel = other.inLabel;
    this->outPort = other.outPort;
    this->outColour = other.outColour;
    this->outLabel = other.outLabel;
}

void OBS_CoreRoutingTableEntry::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->inPort);
    doParsimPacking(b,this->inColour);
    doParsimPacking(b,this->inLabel);
    doParsimPacking(b,this->outPort);
    doParsimPacking(b,this->outColour);
    doParsimPacking(b,this->outLabel);
}

void OBS_CoreRoutingTableEntry::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->inPort);
    doParsimUnpacking(b,this->inColour);
    doParsimUnpacking(b,this->inLabel);
    doParsimUnpacking(b,this->outPort);
    doParsimUnpacking(b,this->outColour);
    doParsimUnpacking(b,this->outLabel);
}

int OBS_CoreRoutingTableEntry::getInPort() const
{
    return this->inPort;
}

void OBS_CoreRoutingTableEntry::setInPort(int inPort)
{
    this->inPort = inPort;
}

int OBS_CoreRoutingTableEntry::getInColour() const
{
    return this->inColour;
}

void OBS_CoreRoutingTableEntry::setInColour(int inColour)
{
    this->inColour = inColour;
}

int OBS_CoreRoutingTableEntry::getInLabel() const
{
    return this->inLabel;
}

void OBS_CoreRoutingTableEntry::setInLabel(int inLabel)
{
    this->inLabel = inLabel;
}

int OBS_CoreRoutingTableEntry::getOutPort() const
{
    return this->outPort;
}

void OBS_CoreRoutingTableEntry::setOutPort(int outPort)
{
    this->outPort = outPort;
}

int OBS_CoreRoutingTableEntry::getOutColour() const
{
    return this->outColour;
}

void OBS_CoreRoutingTableEntry::setOutColour(int outColour)
{
    this->outColour = outColour;
}

int OBS_CoreRoutingTableEntry::getOutLabel() const
{
    return this->outLabel;
}

void OBS_CoreRoutingTableEntry::setOutLabel(int outLabel)
{
    this->outLabel = outLabel;
}

class OBS_CoreRoutingTableEntryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inPort,
        FIELD_inColour,
        FIELD_inLabel,
        FIELD_outPort,
        FIELD_outColour,
        FIELD_outLabel,
    };
  public:
    OBS_CoreRoutingTableEntryDescriptor();
    virtual ~OBS_CoreRoutingTableEntryDescriptor();

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

Register_ClassDescriptor(OBS_CoreRoutingTableEntryDescriptor)

OBS_CoreRoutingTableEntryDescriptor::OBS_CoreRoutingTableEntryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(OBS_CoreRoutingTableEntry)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

OBS_CoreRoutingTableEntryDescriptor::~OBS_CoreRoutingTableEntryDescriptor()
{
    delete[] propertyNames;
}

bool OBS_CoreRoutingTableEntryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_CoreRoutingTableEntry *>(obj)!=nullptr;
}

const char **OBS_CoreRoutingTableEntryDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OBS_CoreRoutingTableEntryDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OBS_CoreRoutingTableEntryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int OBS_CoreRoutingTableEntryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inPort
        FD_ISEDITABLE,    // FIELD_inColour
        FD_ISEDITABLE,    // FIELD_inLabel
        FD_ISEDITABLE,    // FIELD_outPort
        FD_ISEDITABLE,    // FIELD_outColour
        FD_ISEDITABLE,    // FIELD_outLabel
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inPort",
        "inColour",
        "inLabel",
        "outPort",
        "outColour",
        "outLabel",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int OBS_CoreRoutingTableEntryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inPort") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "inColour") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "inLabel") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "outPort") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "outColour") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "outLabel") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inPort
        "int",    // FIELD_inColour
        "int",    // FIELD_inLabel
        "int",    // FIELD_outPort
        "int",    // FIELD_outColour
        "int",    // FIELD_outLabel
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_CoreRoutingTableEntryDescriptor::getFieldPropertyNames(int field) const
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

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int OBS_CoreRoutingTableEntryDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OBS_CoreRoutingTableEntryDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OBS_CoreRoutingTableEntry'", field);
    }
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OBS_CoreRoutingTableEntryDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        case FIELD_inPort: return long2string(pp->getInPort());
        case FIELD_inColour: return long2string(pp->getInColour());
        case FIELD_inLabel: return long2string(pp->getInLabel());
        case FIELD_outPort: return long2string(pp->getOutPort());
        case FIELD_outColour: return long2string(pp->getOutColour());
        case FIELD_outLabel: return long2string(pp->getOutLabel());
        default: return "";
    }
}

void OBS_CoreRoutingTableEntryDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        case FIELD_inPort: pp->setInPort(string2long(value)); break;
        case FIELD_inColour: pp->setInColour(string2long(value)); break;
        case FIELD_inLabel: pp->setInLabel(string2long(value)); break;
        case FIELD_outPort: pp->setOutPort(string2long(value)); break;
        case FIELD_outColour: pp->setOutColour(string2long(value)); break;
        case FIELD_outLabel: pp->setOutLabel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_CoreRoutingTableEntry'", field);
    }
}

omnetpp::cValue OBS_CoreRoutingTableEntryDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        case FIELD_inPort: return pp->getInPort();
        case FIELD_inColour: return pp->getInColour();
        case FIELD_inLabel: return pp->getInLabel();
        case FIELD_outPort: return pp->getOutPort();
        case FIELD_outColour: return pp->getOutColour();
        case FIELD_outLabel: return pp->getOutLabel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OBS_CoreRoutingTableEntry' as cValue -- field index out of range?", field);
    }
}

void OBS_CoreRoutingTableEntryDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        case FIELD_inPort: pp->setInPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_inColour: pp->setInColour(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_inLabel: pp->setInLabel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_outPort: pp->setOutPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_outColour: pp->setOutColour(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_outLabel: pp->setOutLabel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_CoreRoutingTableEntry'", field);
    }
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr OBS_CoreRoutingTableEntryDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OBS_CoreRoutingTableEntryDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = omnetpp::fromAnyPtr<OBS_CoreRoutingTableEntry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OBS_CoreRoutingTableEntry'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

