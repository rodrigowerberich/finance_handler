#pragma once

namespace opt{

    class Optional{
        virtual bool isValid() const = 0;
        virtual void invalidate() = 0;
    };

}