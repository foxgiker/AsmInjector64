project("gktool")



add_library(${PROJECT_NAME} STATIC
    DetourHelper.cpp DetourHelper.h
)

target_link_libraries(gktool PUBLIC DTOUR)
target_include_directories(${PROJECT_NAME} PUBLIC .)