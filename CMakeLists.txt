cmake_minimum_required(VERSION 3.22)
project(Dutchnary)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dutchnary Src/Dutchnary.cpp Src/Word.cpp Src/Word.h Src/Dictionary.cpp Src/Dictionary.h)
target_compile_definitions(Dutchnary PUBLIC -DDataBase="${CmakeDataBase}")
