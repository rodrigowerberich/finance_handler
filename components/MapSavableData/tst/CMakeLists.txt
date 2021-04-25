ADD_EXECUTABLE(MapSavableData_tst 
    main.cc
    test_MapReadableObject.cc
    test_WritableMappedData.cc
)

ADD_TEST(NAME MapSavableData_tst COMMAND MapSavableData_tst)

TARGET_LINK_LIBRARIES(MapSavableData_tst 
    PUBLIC 
        gtest
        MapSavableData
)