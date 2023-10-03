

add_library(DTOUR INTERFACE)

target_include_directories(DTOUR INTERFACE include)
target_link_libraries(DTOUR INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/detours.lib)