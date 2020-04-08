set(TEST_NAME test_snake_model)

add_executable(${TEST_NAME}
    test_food.cc
    test_game.cc
    test_main.cc
    test_snake.cc
    test_table.cc
)

target_link_libraries(${TEST_NAME}
    gtest
    model
    pthread
)

add_test(${TEST_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}
)

set_tests_properties(${TEST_NAME}
    PROPERTIES
    LABELS "cpp"
)

add_custom_command(
    TARGET ${TEST_NAME}
    COMMENT "Game model unit test"
    POST_BUILD
    COMMAND ${TEST_NAME}
)
