set(SOURCES
        Main.cpp
        WordTests.cpp
        )

add_executable(DutchnaryTests ${SOURCES})
target_include_directories(DutchnaryTests PUBLIC ${CATCH2_INCLUDES} ${DUTCHNARY_INCLUDE_DIR})
target_link_libraries(DutchnaryTests LibDutch)