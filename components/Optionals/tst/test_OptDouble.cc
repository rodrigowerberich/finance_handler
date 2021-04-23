#include "gtest/gtest.h"
#include "test_helper.hh"

#include "OptDouble.hh"

TEST(OptDouble, EmptyContructor) {
    testEmptyContruction<Optional::OptDouble>();
}

TEST(OptDouble, NonEmptyContructorValidity) {
    testNonEmptyContructorValidity<Optional::OptDouble>(0.3);
}

TEST(OptDouble, NonEmptyContructorValue) {
    testNonEmptyContructorValue<Optional::OptDouble>(1000.45);
}

TEST(OptDouble, SettingValueValidity) {
    testSettingValueValidity<Optional::OptDouble>(-375.15);
}

TEST(OptDouble, SettingValue) {
    testSettingValue<Optional::OptDouble>(-1521.001);
}

TEST(OptDouble, Invalidate) {
    testInvalidate<Optional::OptDouble>(0.10);
}

