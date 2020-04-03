cmake_minimum_required(VERSION 3.10)

set(PROJ_NAME Snake)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJ_NAME} main.cc)

target_link_libraries(${PROJ_NAME}
    model
)

add_subdirectory(model)
