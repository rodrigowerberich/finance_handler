#pragma once


#include "Key.hh"
#include "WritableMappedData.hh"

namespace msd{

class MapSavableObject{
public:
    virtual bool convert(WritableMappedData& mappedData) const = 0;
};

}