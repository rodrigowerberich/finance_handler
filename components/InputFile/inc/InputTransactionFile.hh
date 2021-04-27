#pragma once

#include "InputType.hh"
#include <string>

namespace ipfi{

class InputTransactionFile{
public:
    virtual InputType inputType() const = 0;
    virtual std::string pathToTransactionFile() const = 0;
};

}