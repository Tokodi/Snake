set(LIB_NAME ncurses_menu)

add_library(${LIB_NAME} STATIC
    menu_window.cc
    notifyer.cc
    size_getter_window.cc
)

target_link_libraries(${LIB_NAME}
    ncurses_view_common
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
