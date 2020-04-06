set(LIB_NAME model)

add_library(${LIB_NAME} STATIC
    food.cc
    game.cc
    snake.cc
    table.cc
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(GTest)

if (${GTEST_FOUND})
add_subdirectory(test)
endif (${GTEST_FOUND})
