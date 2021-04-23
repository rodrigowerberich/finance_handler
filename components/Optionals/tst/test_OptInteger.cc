#include "gtest/gtest.h"
#include "test_helper.hh"

#include "OptInteger.hh"

TEST(OptionalInteger, EmptyContructor) {
    testEmptyContruction<Optional::OptInteger>();
}

TEST(OptionalInteger, NonEmptyContructorValidity) {
    testNonEmptyContructorValidity<Optional::OptInteger>(23);
}

TEST(OptionalInteger, NonEmptyContructorValue) {
    testNonEmptyContructorValue<Optional::OptInteger>(1000);
}

TEST(OptionalInteger, SettingValueValidity) {
    testSettingValueValidity<Optional::OptInteger>(-375);
}

TEST(OptionalInteger, SettingValue) {
    testSettingValue<Optional::OptInteger>(-1521);
}

TEST(OptionalInteger, Invalidate) {
    testInvalidate<Optional::OptInteger>(10);
}

