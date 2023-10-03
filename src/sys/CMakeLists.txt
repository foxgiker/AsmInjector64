project("demo")

find_package(WDK REQUIRED)
wdk_add_driver(kmdfDemo main.c)