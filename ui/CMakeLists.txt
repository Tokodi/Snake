set(LIB_NAME ui)

add_library(${LIB_NAME} STATIC
    utils.cc
)

target_link_libraries(${LIB_NAME}
    ncurses
    ui_common
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(common)
