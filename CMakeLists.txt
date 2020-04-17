cmake_minimum_required(VERSION 3.10)

set(PROJ_NAME Snake)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

add_executable(${PROJ_NAME} main.cc)

target_link_libraries(${PROJ_NAME}
    model
    ncurses
    ncurses_game_view
    ncurses_menu
)

include_directories(${PROJECT_SOURCE_DIR}/controller)
include_directories(${PROJECT_SOURCE_DIR}/persistence/interface)
include_directories(${PROJECT_SOURCE_DIR}/view/interface)

add_subdirectory(controller)
add_subdirectory(model)
add_subdirectory(persistence)
add_subdirectory(view)
