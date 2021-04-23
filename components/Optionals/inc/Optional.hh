#pragma once

namespace Optional{

    class OptionalI{
        virtual bool isValid() const = 0;
        virtual void invalidate() = 0;
    };

}