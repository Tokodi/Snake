set(LIB_NAME file_persistence)

add_library(${LIB_NAME} STATIC
    file_persistence.cc
)

target_link_libraries(${LIB_NAME}
    persistence_common
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
