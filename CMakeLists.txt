cmake_minimum_required(VERSION 3.10)

set(PROJ_NAME Snake)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

add_executable(${PROJ_NAME} main.cc)

target_link_libraries(${PROJ_NAME}
    model
)

add_subdirectory(model)
