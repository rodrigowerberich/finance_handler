ADD_EXECUTABLE(ParserRegistry_tst 
    main.cc
    test_InputTransactionParser.cc
    test_InputTransactionParserGenerator.cc
)

ADD_TEST(NAME ParserRegistry_tst COMMAND ParserRegistry_tst)

TARGET_LINK_LIBRARIES(ParserRegistry_tst 
    PUBLIC 
        gtest
        gmock
        ParserRegistry
)