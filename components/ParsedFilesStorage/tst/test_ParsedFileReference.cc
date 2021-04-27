#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ParsedFileReference.hh"

class MockParsedFileReference: pfs::ParsedFileReference{
public:
    MOCK_METHOD(int, getId, (), (const override));
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
};

using ::testing::Return;

TEST(ParsedFileReference, getId) {
    MockParsedFileReference parsedFileReference;
    
    int originalId = 1;

    ON_CALL(parsedFileReference, getId).WillByDefault(Return(originalId));
    
    auto id = parsedFileReference.getId();
    
    ASSERT_EQ(originalId, id);
}

TEST(ParsedFileReference, getInputType) {
    MockParsedFileReference parsedFileReference;
    
    ipfi::InputType originalInputType = 2;

    ON_CALL(parsedFileReference, getInputType).WillByDefault(Return(originalInputType));
    
    auto inputType = parsedFileReference.getInputType();
    
    ASSERT_EQ(originalInputType, inputType);
}
