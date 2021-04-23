#include "gtest/gtest.h"
#include "test_helper.hh"

#include "OptString.hh"

TEST(OptionalString, EmptyContructor) {
    testEmptyContruction<opt::OptString>();
}

TEST(OptionalString, NonEmptyContructorValidity) {
    testNonEmptyContructorValidity<opt::OptString>("Foo");
}

TEST(OptionalString, NonEmptyContructorValidityStdString) {
    std::string foo = "Foo";
    testNonEmptyContructorValidity<opt::OptString>(foo);
}

TEST(OptionalString, NonEmptyContructorValue) {
    testNonEmptyContructorValue<opt::OptString>("A big sentence");
}

TEST(OptionalString, NonEmptyContructorValueStdString) {
    std::string foo = "A big sentence";
    testNonEmptyContructorValue<opt::OptString>(foo);
}

TEST(OptionalString, SettingValueValidity) {
    testSettingValueValidity<opt::OptString>("Bar");
}

TEST(OptionalString, SettingValueValidityStdString) {
    std::string bar = "Bar";
    testSettingValueValidity<opt::OptString>(bar);
}

TEST(OptionalString, SettingValue) {
    testSettingValue<opt::OptString>("An ever bigger sentence");
}

TEST(OptionalString, SettingValueStdString) {
    std::string bar = "An ever bigger sentence";
    testSettingValue<opt::OptString>(bar);
}

TEST(OptionalString, Invalidate) {
    testInvalidate<opt::OptString>("1");
}
