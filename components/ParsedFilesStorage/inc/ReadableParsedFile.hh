#pragma once

#include "InputType.hh"
#include "MapReadableObject.hh"

namespace pfs{

class ReadableParsedFile : public msd::MapReadableObject {
public:
    virtual ipfi::InputType getInputType() const = 0;
    virtual opt::OptInteger getInteger(msd::Key key) const = 0;
    virtual opt::OptDouble  getDouble(msd::Key key) const = 0;
    virtual opt::OptString  getString(msd::Key key) const = 0;
};

}