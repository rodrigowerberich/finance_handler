#include "gtest/gtest.h"
#include "test_helper.hh"

#include "OptString.hh"

TEST(OptionalString, EmptyContructor) {
    testEmptyContruction<Optional::OptString>();
}

TEST(OptionalString, NonEmptyContructorValidity) {
    testNonEmptyContructorValidity<Optional::OptString>("Foo");
}

TEST(OptionalString, NonEmptyContructorValidityStdString) {
    std::string foo = "Foo";
    testNonEmptyContructorValidity<Optional::OptString>(foo);
}

TEST(OptionalString, NonEmptyContructorValue) {
    testNonEmptyContructorValue<Optional::OptString>("A big sentence");
}

TEST(OptionalString, NonEmptyContructorValueStdString) {
    std::string foo = "A big sentence";
    testNonEmptyContructorValue<Optional::OptString>(foo);
}

TEST(OptionalString, SettingValueValidity) {
    testSettingValueValidity<Optional::OptString>("Bar");
}

TEST(OptionalString, SettingValueValidityStdString) {
    std::string bar = "Bar";
    testSettingValueValidity<Optional::OptString>(bar);
}

TEST(OptionalString, SettingValue) {
    testSettingValue<Optional::OptString>("An ever bigger sentence");
}

TEST(OptionalString, SettingValueStdString) {
    std::string bar = "An ever bigger sentence";
    testSettingValue<Optional::OptString>(bar);
}

TEST(OptionalString, Invalidate) {
    testInvalidate<Optional::OptString>("1");
}
