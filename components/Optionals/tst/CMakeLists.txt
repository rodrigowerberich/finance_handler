ADD_EXECUTABLE(Optionals_tst 
    main.cc
    test_OptInteger.cc
    test_OptDouble.cc
    test_OptString.cc
)

ADD_TEST(NAME Optionals_tst COMMAND Optionals_tst)

TARGET_LINK_LIBRARIES(Optionals_tst 
    PUBLIC 
        gtest
        Optionals
)