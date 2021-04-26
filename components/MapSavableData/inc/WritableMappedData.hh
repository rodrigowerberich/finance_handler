#pragma once

#include <string>

#include "Key.hh"

namespace msd{

class WritableMappedData{
public:
    virtual bool addInteger(Key key, int value) = 0;
    virtual bool addDouble(Key key, double value) = 0;
    virtual bool addString(Key key, const std::string& value) = 0;
    virtual bool addString(Key key, std::string&& value) = 0;

    bool add(Key key, int value){
        return addInteger(key, value);
    }

    bool add(Key key, double value){
        return addDouble(key, value);
    }

    bool add(Key key, const std::string& value){
        return addString(key, value);
    }

    bool add(Key key, std::string&& value){
        return addString(key, std::move(value));
    }
};

}
