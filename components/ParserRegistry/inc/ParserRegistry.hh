#pragma once

#include "InputType.hh"
#include "InputTransactionParser.hh"
#include "InputTransactionParserGenerator.hh"

namespace pr{

class ParserRegistry{
public:
    virtual const InputTransactionParser& getParser(const ipfi::InputType& inputType) const = 0;
    virtual bool addParserGenerator(const ipfi::InputType& inputType, const InputTransactionParserGenerator& inputParserGenerator) = 0;
};

}