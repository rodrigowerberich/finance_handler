#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "InputTransactionFile.hh"
#include "SavableParsedFile.hh"
#include "InputTransactionParser.hh"
#include "InputTransactionParserGenerator.hh"

class MockInputTransactionParser: public pr::InputTransactionParser{
public:
    MOCK_METHOD(const pfs::SavableParsedFile&, parse, (const ipfi::InputTransactionFile& inputTransactionFile), (const override));
};

class MockInputTransactionParserGenerator: public pr::InputTransactionParserGenerator{
public:
    MOCK_METHOD(const pr::InputTransactionParser&, generateParser, (), (const override));
};


using ::testing::ReturnRef;

TEST(InputTransactionParserGenerator, generateParser) {
    MockInputTransactionParser inputTransactionParser;
    MockInputTransactionParserGenerator inputTransactionParserGenerator;
    
    EXPECT_CALL(inputTransactionParserGenerator, generateParser()).Times(1).WillRepeatedly(ReturnRef(inputTransactionParser));
    
    const auto& receivedInputTransactionParser = inputTransactionParserGenerator.generateParser();
    
    ASSERT_EQ(&inputTransactionParser, &receivedInputTransactionParser);
}