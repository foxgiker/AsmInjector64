


add_library(tou INTERFACE)

target_include_directories(tou INTERFACE .)
target_link_libraries(tou INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/jack.lib)