#pragma once

#include "gtest/gtest.h"

template <typename Optional>
void testEmptyContruction(){
    Optional opt;
    ASSERT_FALSE(opt.isValid());
}

template <typename Optional, typename ValueType>
void testNonEmptyContructorValidity(ValueType value){
    Optional opt{value};
    ASSERT_TRUE(opt.isValid());
}

template <typename Optional, typename ValueType>
void testNonEmptyContructorValue(ValueType value){
    Optional opt{value};
    ASSERT_EQ(value , opt.value()) << "Constructor not setting the value properly";
}

template <typename Optional, typename ValueType>
void testSettingValueValidity(ValueType value){
    Optional opt;
    opt.setValue(value);
    ASSERT_TRUE(opt.isValid()) << "Set value is not marking the value as valid";
}

template <typename Optional, typename ValueType>
void testSettingValue(ValueType value){
    Optional opt;
    opt.setValue(value);
    ASSERT_EQ(value , opt.value()) << "Set value is not really changing the value";
}

template <typename Optional, typename ValueType>
void testInvalidate(ValueType value){
    Optional opt{value};
    opt.invalidate();
    ASSERT_FALSE(opt.isValid()) << "Invalidate is not properly setting the optional to invalid";
}