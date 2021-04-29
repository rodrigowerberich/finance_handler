ADD_EXECUTABLE(ParsedFilesStorage_tst 
    main.cc
    test_ParsedFileReference.cc
    test_ReadableParsedFile.cc
    test_SavableParsedFile.cc
    test_ParsedFiles.cc
)

ADD_TEST(NAME ParsedFilesStorage_tst COMMAND ParsedFilesStorage_tst)

TARGET_LINK_LIBRARIES(ParsedFilesStorage_tst 
    PUBLIC 
        gtest
        gmock
        ParsedFilesStorage
)