#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ParsedFiles.hh"

class MockParsedFileReference: public pfs::ParsedFileReference{
public:
    MOCK_METHOD(int, getId, (), (const override));
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
};

class MockSavableParsedFile: public pfs::SavableParsedFile{
public:
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
    MOCK_METHOD(bool, convert, (msd::WritableMappedData& mappedData), (const override));
};

class MockReadableParsedFile: public pfs::ReadableParsedFile{
public:
    MOCK_METHOD(ipfi::InputType, getInputType, (), (const override));
    MOCK_METHOD(opt::OptInteger, getInteger, (msd::Key key), (const override));
    MOCK_METHOD(opt::OptDouble, getDouble, (msd::Key key), (const override));
    MOCK_METHOD(opt::OptString, getString, (msd::Key key), (const override));
};

class MockParsedFiles: public pfs::ParsedFiles{
public:
    MOCK_METHOD(bool, store, (const pfs::SavableParsedFile& parsedFile), (const override));
    MOCK_METHOD(const pfs::ReadableParsedFile&, load, (const pfs::ParsedFileReference& reference), (const override));
};

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::_;

TEST(ParsedFiles, store) {
    MockParsedFiles parsedFiles;
    MockSavableParsedFile savableParsedFile;
    
    EXPECT_CALL(parsedFiles, store(_)).Times(1).WillRepeatedly(Return(true));
    
    auto stored = parsedFiles.store(savableParsedFile);
    
    ASSERT_EQ(true, stored);
}

TEST(ParsedFiles, load) {
    MockParsedFileReference parsedFileReference;
    MockReadableParsedFile readableParsedFile;
    MockParsedFiles parsedFiles;
    
    EXPECT_CALL(parsedFiles, load(_)).Times(1).WillRepeatedly(ReturnRef(readableParsedFile));
    
    const auto& obtainedReadableParsedFile = parsedFiles.load(parsedFileReference);
    
    ASSERT_EQ(&readableParsedFile, &obtainedReadableParsedFile);
}