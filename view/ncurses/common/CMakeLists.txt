set(LIB_NAME ncurses_view_common)

add_library(${LIB_NAME} STATIC
    button.cc
    input_field.cc
    ui_element.cc
    utils.cc
    window.cc
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
