#include "gtest/gtest.h"
#include "test_helper.hh"

#include "OptDouble.hh"

TEST(OptDouble, EmptyContructor) {
    testEmptyContruction<opt::OptDouble>();
}

TEST(OptDouble, NonEmptyContructorValidity) {
    testNonEmptyContructorValidity<opt::OptDouble>(0.3);
}

TEST(OptDouble, NonEmptyContructorValue) {
    testNonEmptyContructorValue<opt::OptDouble>(1000.45);
}

TEST(OptDouble, SettingValueValidity) {
    testSettingValueValidity<opt::OptDouble>(-375.15);
}

TEST(OptDouble, SettingValue) {
    testSettingValue<opt::OptDouble>(-1521.001);
}

TEST(OptDouble, Invalidate) {
    testInvalidate<opt::OptDouble>(0.10);
}

