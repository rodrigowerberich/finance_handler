#pragma once

#include "ParsedFileReference.hh"
#include "SavableParsedFile.hh"
#include "ReadableParsedFile.hh"

namespace pfs{

class ParsedFiles {
public:
    virtual bool store(const SavableParsedFile& parsedFile) const = 0;
    virtual const ReadableParsedFile& load(const ParsedFileReference& reference) const = 0;
};

}