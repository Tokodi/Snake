set(LIB_NAME ncurses_game_view)

add_library(${LIB_NAME} STATIC
    ncurses_game_view.cc
)

target_link_libraries(${LIB_NAME}
    model
    ncurses_view_common
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
