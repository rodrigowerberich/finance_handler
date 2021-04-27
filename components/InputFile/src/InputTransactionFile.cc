#include "InputTransactionFileImpl.hh"

namespace ipfi{

InputTransactionFileImpl::InputTransactionFileImpl(InputType inputType, std::string pathToTransactionFile): m_inputType{inputType}, m_pathToTransactionFile{pathToTransactionFile}{

}

InputType InputTransactionFileImpl::inputType() const{
    return m_inputType;
}

std::string InputTransactionFileImpl::pathToTransactionFile() const{
    return m_pathToTransactionFile;
}

}