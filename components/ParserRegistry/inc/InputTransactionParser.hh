#pragma once

#include "InputTransactionFile.hh"
#include "SavableParsedFile.hh"

namespace pr{

class InputTransactionParser{
public:
    virtual const pfs::SavableParsedFile& parse(const ipfi::InputTransactionFile& inputTransactionFile) const = 0;
};

}