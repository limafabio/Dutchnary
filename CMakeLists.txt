cmake_minimum_required(VERSION 3.22)
project(Dutchnary)

set(CMAKE_CXX_STANDARD 20)

set(DUTCHNARY_SOURCES
        Src/Word.cpp
        Src/Word.h
        Src/Dictionary.cpp
        Src/Dictionary.h )

add_library(LibDutch STATIC  ${DUTCHNARY_SOURCES})
target_compile_definitions(LibDutch PUBLIC -DDataBase="${CmakeDataBase}")

set_target_properties(LibDutch PROPERTIES
        OUTPUT_NAME 'LibDutch'
        FOLDER 'LIBDUTCH')

add_executable(Dutchnary Src/Dutchnary.cpp)
set(DUTCHNARY_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/Src)

target_include_directories(Dutchnary PUBLIC ${DUTCHNARY_INCLUDE_DIR})

target_link_libraries(Dutchnary LibDutch)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/External")

include(Catch2)

add_subdirectory(Tests)


