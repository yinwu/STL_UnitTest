cmake_minimum_required(VERSION 3.0)

project(UnitTest)

include_directories(
    "C:/yinwu/GTest/googletest/googletest/include/"
)

link_directories(
    "C:/GTest/lib"
)

file(GLOB CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

message(${CPP_FILES})

add_executable(${PROJECT_NAME} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main)