CMAKE_MINIMUM_REQUIRED(VERSION 3.10)


ADD_LIBRARY(ParsedFilesStorage 
    INTERFACE
)

TARGET_INCLUDE_DIRECTORIES(ParsedFilesStorage
    INTERFACE
        inc
)

TARGET_LINK_LIBRARIES(ParsedFilesStorage 
    INTERFACE 
        InputFile
        MapSavableData
)

ADD_SUBDIRECTORY(tst)