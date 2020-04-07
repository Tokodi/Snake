set(LIB_NAME controller)

add_library(${LIB_NAME} STATIC
    game_controller.hpp
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIB_NAME}
    model
    ui
)
