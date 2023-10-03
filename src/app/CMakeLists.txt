project("gok")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_language(C ASM_MASM)
if(CMAKE_ASM_MASM_COMPILER_WORKS)
    SET(MASMFound TRUE)
    message( "enable  ASM_MASM success!")
else()
    include(CMakeDetermineASM_MASMCompiler)
    include(CMakeTestASM_MASMCompiler)
    if(NOT CMAKE_ASM_MASM_COMPILER_WORKS)
        message(FATAL_ERROR "enable  ASM_MASM failed")
    endif()
endif(CMAKE_ASM_MASM_COMPILER_WORKS)


# 必须要设置这个开关，让cmake自动处理QT中的宏
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Widgets)


add_executable(${PROJECT_NAME}  main.cpp asmhelper.asm
        MainUI.cpp
        MainUI.h
        UITestTab.cpp
        UITestTab.h)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt6::Core
        Qt6::Widgets
        gktool
        tou
)


set_target_properties(${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_dependencies(${PROJECT_NAME} tou)