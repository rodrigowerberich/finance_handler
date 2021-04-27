#include "gtest/gtest.h"

#include "InputTransactionFile.hh"
#include <string>

static int TEST_INT = 5;
static std::string TEST_STR = "/home/dir/teste";

TEST(InputTransactionFile, inputType) {
    auto inputFile = ipfi::InputTransactionFileImpl{TEST_INT, TEST_STR};
    ipfi::InputTransactionFile& refInputFile = inputFile;

    ASSERT_EQ(TEST_INT, refInputFile.inputType());
}

TEST(InputTransactionFile, inputTypeConst) {
    auto inputFile = ipfi::InputTransactionFileImpl{TEST_INT, TEST_STR};

    auto constVerifier = [](const ipfi::InputTransactionFile& refInputFile) { return refInputFile.inputType(); }; 

    ASSERT_EQ(TEST_INT, constVerifier(inputFile));
}

TEST(InputTransactionFile, pathToTransactionFile) {
    auto inputFile = ipfi::InputTransactionFileImpl{TEST_INT, TEST_STR};
    ipfi::InputTransactionFile& refInputFile = inputFile;

    ASSERT_EQ(TEST_STR, refInputFile.pathToTransactionFile());
}

TEST(InputTransactionFile, pathToTransactionFileConst) {
    auto inputFile = ipfi::InputTransactionFileImpl{TEST_INT, TEST_STR};

    auto constVerifier = [](const ipfi::InputTransactionFile& refInputFile) { return refInputFile.pathToTransactionFile(); }; 

    ASSERT_EQ(TEST_STR, constVerifier(inputFile));
}
