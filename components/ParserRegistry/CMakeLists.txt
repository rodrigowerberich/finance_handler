CMAKE_MINIMUM_REQUIRED(VERSION 3.10)


ADD_LIBRARY(ParserRegistry 
    INTERFACE
)

TARGET_INCLUDE_DIRECTORIES(ParserRegistry
    INTERFACE
        inc
)

TARGET_LINK_LIBRARIES(ParserRegistry 
    INTERFACE 
        InputFile
        ParsedFilesStorage
)

ADD_SUBDIRECTORY(tst)