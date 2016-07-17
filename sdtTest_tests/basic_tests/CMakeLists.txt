include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

add_executable(runBasicTests
        myTests.cpp ModelTests.cpp )

target_link_libraries(
        runBasicTests
        gtest gtest_main
        sdTestLib
)
