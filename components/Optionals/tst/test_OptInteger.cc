#include "gtest/gtest.h"
#include "test_helper.hh"

#include "OptInteger.hh"

TEST(OptionalInteger, EmptyContructor) {
    testEmptyContruction<opt::OptInteger>();
}

TEST(OptionalInteger, NonEmptyContructorValidity) {
    testNonEmptyContructorValidity<opt::OptInteger>(23);
}

TEST(OptionalInteger, NonEmptyContructorValue) {
    testNonEmptyContructorValue<opt::OptInteger>(1000);
}

TEST(OptionalInteger, SettingValueValidity) {
    testSettingValueValidity<opt::OptInteger>(-375);
}

TEST(OptionalInteger, SettingValue) {
    testSettingValue<opt::OptInteger>(-1521);
}

TEST(OptionalInteger, Invalidate) {
    testInvalidate<opt::OptInteger>(10);
}

