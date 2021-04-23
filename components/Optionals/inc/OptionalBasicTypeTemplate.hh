#pragma once

#include "Optional.hh"

namespace opt{

template <typename ValueType>
class OptionalBasicType : public Optional{
public:
    OptionalBasicType();
    OptionalBasicType(ValueType value);
    virtual bool isValid() const;
    virtual void invalidate();
    ValueType value() const;
    void setValue(ValueType value);
private:
    bool m_valid;
    ValueType m_value;
};

template <typename ValueType>
OptionalBasicType<ValueType>::OptionalBasicType():m_valid{false} {
}

template <typename ValueType>
OptionalBasicType<ValueType>::OptionalBasicType(ValueType value):m_valid{true},m_value{value} {
}

template <typename ValueType>
bool OptionalBasicType<ValueType>::isValid() const {
    return m_valid;
}

template <typename ValueType>
void OptionalBasicType<ValueType>::invalidate() {
    m_valid = false;
}

template <typename ValueType>
ValueType OptionalBasicType<ValueType>::value() const {
    return m_value;
}

template <typename ValueType>
void OptionalBasicType<ValueType>::setValue(ValueType value) {
    m_value = value;
    m_valid = true;
}

}