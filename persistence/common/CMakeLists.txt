set(LIB_NAME persistence_common)

add_library(${LIB_NAME} STATIC
    score_record.cc
)

target_include_directories(${LIB_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
