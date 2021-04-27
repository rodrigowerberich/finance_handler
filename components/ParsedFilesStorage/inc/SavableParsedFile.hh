#pragma once

#include "InputType.hh"
#include "MapSavableObject.hh"

namespace pfs{

class SavableParsedFile : public msd::MapSavableObject {
public:
    virtual ipfi::InputType getInputType() const = 0;
    virtual bool convert(msd::WritableMappedData& mappedData) const = 0;
};

}