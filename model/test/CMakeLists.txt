set(TEST_NAME test_snake_model)

add_executable(${TEST_NAME}
    test_food.cc
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

#TODO: run after full build finished
add_custom_command(
    TARGET ${TEST_NAME}
    COMMENT "Unit testing model..."
    POST_BUILD
    COMMAND ${TEST_NAME}
)
