include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

add_executable(runBasicTests
        ModelTests.cpp SerializationTests.cpp QuadTreeTests.cpp ViewTests.cpp)

target_link_libraries(
        runBasicTests
        gtest gtest_main
        SpaceGameLib
)
