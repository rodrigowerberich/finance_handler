#pragma once

#include "InputTransactionParser.hh"

namespace pr{

class InputTransactionParserGenerator{
public:
    virtual const pr::InputTransactionParser& generateParser() const = 0;
};

}