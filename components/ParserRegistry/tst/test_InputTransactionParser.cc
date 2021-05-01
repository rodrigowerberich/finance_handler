#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "InputTransactionFile.hh"
#include "SavableParsedFile.hh"
#include "InputTransactionParser.hh"

class MockInputTransactionFile: public ipfi::InputTransactionFile{
    MOCK_METHOD(ipfi::InputType, inputType, (), (const override));
    MOCK_METHOD(std::string, pathToTransactionFile, (), (const override));
};

class MockSavableParsedFile: public pfs::SavableParsedFile{
public:
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
    MOCK_METHOD(bool, convert, (msd::WritableMappedData& mappedData), (const override));
};

class MockInputTransactionParser: public pr::InputTransactionParser{
public:
    MOCK_METHOD(const pfs::SavableParsedFile&, parse, (const ipfi::InputTransactionFile& inputTransactionFile), (const override));
};


using ::testing::ReturnRef;
using ::testing::_;

TEST(InputTransactionParser, parse) {
    MockInputTransactionFile inputTransactionFile;
    MockSavableParsedFile savableParsedFile;
    MockInputTransactionParser inputTransactionParser;
    
    EXPECT_CALL(inputTransactionParser, parse(_)).Times(1).WillRepeatedly(ReturnRef(savableParsedFile));
    
    const auto& receivedSavableParsedFile = inputTransactionParser.parse(inputTransactionFile);
    
    ASSERT_EQ(&savableParsedFile, &receivedSavableParsedFile);
}