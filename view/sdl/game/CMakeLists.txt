set(LIB_NAME sdl_game_view)

add_library(${LIB_NAME} STATIC
    sdl_game_view.cc
)

target_link_libraries(${LIB_NAME}
    model
    SDL2
    SDL2main
    SDL2_ttf
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
