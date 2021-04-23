#pragma once

#include "OptInteger.hh"
#include "OptDouble.hh"
#include "OptString.hh"

#include "Key.hh"

namespace msd{

class MapReadableObject{
public:
    virtual opt::OptInteger getInteger(Key key) const = 0;
    virtual opt::OptDouble  getDouble(Key key) const = 0;
    virtual opt::OptString  getString(Key key) const = 0;
};

}
