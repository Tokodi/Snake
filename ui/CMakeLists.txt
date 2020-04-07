set(LIB_NAME ui)

add_library(${LIB_NAME} STATIC
    menu_window.cc
    notifyer.cc
    view_ncurses.cc
    utils.cc
)

#TODO: shrink model, only game is needed here...
#TODO: rather rethink whole lib structure...
target_link_libraries(${LIB_NAME}
    ncurses
    model
    ui_common
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(common)
