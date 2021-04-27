#pragma once

#include "InputType.hh"

namespace pfs{

class ParsedFileReference{
public:
    virtual int getId() const = 0;
    virtual ipfi::InputType getInputType() const = 0;
};

}