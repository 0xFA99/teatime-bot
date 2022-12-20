cmake_minimum_required(VERSION 3.24)

project(silly VERSION 1.0
    DESCRIPTION "Silly Personal Bot"
    LANGUAGES CXX)

add_subdirectory(lib/DPP)
add_subdirectory(helper)

add_executable(${PROJECT_NAME} bot/main.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE
        dpp silly_helper)

target_include_directories(${PROJECT_NAME} PRIVATE
        lib/dpp/include)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)



