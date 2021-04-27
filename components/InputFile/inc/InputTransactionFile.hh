#pragma once

#include "InputType.hh"
#include <string>

namespace ipfi{

class InputTransactionFile{
public:
    virtual InputType inputType() const = 0;
    virtual std::string pathToTransactionFile() const = 0;
};

class InputTransactionFileImpl: public InputTransactionFile{
public:
    InputTransactionFileImpl(InputType inputType, std::string pathToTransactionFile);
    virtual InputType inputType() const;
    virtual std::string pathToTransactionFile() const;
private:
    InputType m_inputType;
    std::string m_pathToTransactionFile;
};

}