#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "InputType.hh"
#include "SavableParsedFile.hh"
#include "InputTransactionParser.hh"
#include "InputTransactionParserGenerator.hh"
#include "ParserRegistry.hh"

class MockInputTransactionParser: public pr::InputTransactionParser{
public:
    MOCK_METHOD(const pfs::SavableParsedFile&, parse, (const ipfi::InputTransactionFile& inputTransactionFile), (const override));
};

class MockInputTransactionParserGenerator: public pr::InputTransactionParserGenerator{
public:
    MOCK_METHOD(const pr::InputTransactionParser&, generateParser, (), (const override));
};

class MockParserRegistry: public pr::ParserRegistry{
public:
    MOCK_METHOD(const pr::InputTransactionParser&, getParser, (const ipfi::InputType& inputType), (const override));
    MOCK_METHOD(bool, addParserGenerator, (const ipfi::InputType& inputType, const pr::InputTransactionParserGenerator& inputParserGenerator), (override));
};

using ::testing::ReturnRef;
using ::testing::Return;
using ::testing::_;

TEST(ParserRegistry, getParser) {

    MockInputTransactionParser inputTransactionParser;
    MockParserRegistry parserRegistry;

    auto inputType = ipfi::InputType{4};

    EXPECT_CALL(parserRegistry, getParser(inputType)).Times(1).WillRepeatedly(ReturnRef(inputTransactionParser));
    
    const auto& receivedInputTransactionParser = parserRegistry.getParser(inputType);
    
    ASSERT_EQ(&inputTransactionParser, &receivedInputTransactionParser);
}

TEST(ParserRegistry, addParserGenerator) {

    MockInputTransactionParserGenerator inputTransactionParserGenerator;
    MockParserRegistry parserRegistry;

    auto inputType = ipfi::InputType{4};

    EXPECT_CALL(parserRegistry, addParserGenerator(inputType, _)).Times(1).WillRepeatedly(Return(true));
    
    auto added = parserRegistry.addParserGenerator(inputType, inputTransactionParserGenerator);
    
    ASSERT_EQ(true, added);
}