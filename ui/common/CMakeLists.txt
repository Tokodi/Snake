set(LIB_NAME ui_common)

add_library(${LIB_NAME} STATIC
    button.cc
    ui_element.cc
    window.cc
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
