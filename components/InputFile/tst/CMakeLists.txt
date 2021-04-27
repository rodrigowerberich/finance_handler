ADD_EXECUTABLE(InputFile_tst 
    main.cc
    test_InputTransactionFile.cc
)

ADD_TEST(NAME InputFile_tst COMMAND InputFile_tst)

TARGET_LINK_LIBRARIES(InputFile_tst 
    PUBLIC 
        gtest
        InputFile
)