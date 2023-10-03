cmake_minimum_required(VERSION 3.25)
project(AsmInjector)

set(CMAKE_CXX_STANDARD 17)

# 设置qt的环境变量
set(ENV{qt_DIR} D:/Qt/6.5.1/msvc2019_64/lib/cmake)
# 设置wdk根目录
set(ENV{WDKContentRoot} "D:/Windows Kits/10")


add_subdirectory(deps)
add_subdirectory(src)
