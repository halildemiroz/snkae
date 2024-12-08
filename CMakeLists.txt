cmake_minimum_required(VERSION 3.5)
project(SDL C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(SDL2_INCLUDE_DIR "C:/SDL2/include")
set(SDL2_LIBRARY_DIR "C:/SDL2/lib")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIR})

link_libraries(SDL2main SDL2 SDL2_ttf SDL2_image)

add_executable(main src/main.c)
