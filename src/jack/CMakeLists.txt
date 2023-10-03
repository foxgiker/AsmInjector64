
project("jack")

add_library(${PROJECT_NAME} SHARED main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gktool DTOUR)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/deps/tou"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/deps/tou"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)