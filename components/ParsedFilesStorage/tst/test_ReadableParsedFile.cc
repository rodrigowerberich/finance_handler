#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ReadableParsedFile.hh"

class MockReadableParsedFile: pfs::ReadableParsedFile{
public:
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
    MOCK_METHOD(opt::OptInteger, getInteger, (msd::Key key), (const override));
    MOCK_METHOD(opt::OptDouble, getDouble, (msd::Key key), (const override));
    MOCK_METHOD(opt::OptString, getString, (msd::Key key), (const override));
};

using ::testing::Return;

TEST(ReadableParsedFile, getInputType) {
    MockReadableParsedFile readableParsedFile;
    
    ipfi::InputType originalInputType = 2;

    ON_CALL(readableParsedFile, getInputType).WillByDefault(Return(originalInputType));
    
    auto inputType = readableParsedFile.getInputType();
    
    ASSERT_EQ(originalInputType, inputType);
}

TEST(ReadableParsedFile, getInteger) {
    MockReadableParsedFile readableParsedFile;
    
    auto originalOptInteger = opt::OptInteger{2};

    ON_CALL(readableParsedFile, getInteger(5)).WillByDefault(Return(originalOptInteger));
    
    auto optInteger = readableParsedFile.getInteger(5);

    ASSERT_TRUE(optInteger.isValid());
    
    ASSERT_EQ(originalOptInteger.value(), optInteger.value());
}

TEST(ReadableParsedFile, getIntegerFailed) {
    MockReadableParsedFile readableParsedFile;
    
    auto invalidOptInteger = opt::OptInteger{};

    ON_CALL(readableParsedFile, getInteger(6)).WillByDefault(Return(invalidOptInteger));
    
    auto optInteger = readableParsedFile.getInteger(6);

    ASSERT_FALSE(optInteger.isValid());
}

TEST(ReadableParsedFile, getDouble) {
    MockReadableParsedFile readableParsedFile;
    
    auto originalOptDouble = opt::OptDouble{2.0};

    ON_CALL(readableParsedFile, getDouble(5)).WillByDefault(Return(originalOptDouble));
    
    auto optDouble = readableParsedFile.getDouble(5);

    ASSERT_TRUE(optDouble.isValid());
    
    ASSERT_EQ(originalOptDouble.value(), optDouble.value());
}

TEST(ReadableParsedFile, getDoubleFailed) {
    MockReadableParsedFile readableParsedFile;
    
    auto invalidOptDouble = opt::OptDouble{};

    ON_CALL(readableParsedFile, getDouble(6)).WillByDefault(Return(invalidOptDouble));
    
    auto optDouble = readableParsedFile.getDouble(6);

    ASSERT_FALSE(optDouble.isValid());
}

TEST(ReadableParsedFile, getString) {
    MockReadableParsedFile readableParsedFile;
    
    auto originalOptString = opt::OptString{"Hi!"};

    ON_CALL(readableParsedFile, getString(5)).WillByDefault(Return(originalOptString));
    
    auto optString = readableParsedFile.getString(5);

    ASSERT_TRUE(optString.isValid());
    
    ASSERT_EQ(originalOptString.value(), optString.value());
}

TEST(ReadableParsedFile, getStringFailed) {
    MockReadableParsedFile readableParsedFile;
    
    auto invalidOptString = opt::OptString{};

    ON_CALL(readableParsedFile, getString(6)).WillByDefault(Return(invalidOptString));
    
    auto optString = readableParsedFile.getString(6);

    ASSERT_FALSE(optString.isValid());
}