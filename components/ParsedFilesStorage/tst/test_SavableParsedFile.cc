#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "SavableParsedFile.hh"

class MockWritableMappedData: public msd::WritableMappedData{
    MOCK_METHOD(bool, addInteger, (msd::Key key, int value), (override));
    MOCK_METHOD(bool, addDouble, (msd::Key key, double value), (override));
    MOCK_METHOD(bool, addString, (msd::Key key, const std::string& value), (override));
    MOCK_METHOD(bool, addString, (msd::Key key, std::string&& value), (override));
};

class MockSavableParsedFile: public pfs::SavableParsedFile{
public:
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
    MOCK_METHOD(bool, convert, (msd::WritableMappedData& mappedData), (const override));
};

using ::testing::Return;
using ::testing::_;

TEST(SavableParsedFile, getInputType) {
    MockSavableParsedFile savableParsedFile;
    
    ipfi::InputType originalInputType = 2;

    EXPECT_CALL(savableParsedFile, getInputType()).Times(1).WillRepeatedly(Return(originalInputType));
    
    auto inputType = savableParsedFile.getInputType();
    
    ASSERT_EQ(originalInputType, inputType);
}

TEST(SavableParsedFile, convert) {

    MockWritableMappedData writableMappedData;
    MockSavableParsedFile savableParsedFile;
    
    EXPECT_CALL(savableParsedFile, convert(_)).Times(1).WillRepeatedly(Return(true));
    
    auto converted = savableParsedFile.convert(writableMappedData);
    
    ASSERT_EQ(true, converted);
}