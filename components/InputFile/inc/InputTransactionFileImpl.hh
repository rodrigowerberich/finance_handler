#pragma once

#include <InputTransactionFile.hh>

namespace ipfi{

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