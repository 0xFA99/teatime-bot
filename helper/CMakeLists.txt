cmake_minimum_required(VERSION 3.24)

project(silly_helper VERSION 1.0
        DESCRIPTION "Helper program for extended silly bot"
        LANGUAGES CXX)

set(CMAKE_DEBUG_POSTFIX d)

add_library(${PROJECT_NAME} STATIC)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME exec_command
)

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_sources(${PROJECT_NAME} PRIVATE src/exec_command.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE src/helper
        PUBLIC include)