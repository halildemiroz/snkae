cmake_minimum_required(VERSION 3.5)
project(SDL C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(SDL2_INCLUDE_DIR "C:/SDL2/include")
set(SDL2_LIBRARY_DIR "C:/SDL2/lib")

set(SDL2_image_INCLUDE_DIR "C:/SDL2_image/include")
set(SDL2_image_LIBRARY_DIR "C:/SDL2_image/lib")
set(SDL2_image_DIR "C:/SDL2_image/cmake")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_image_INCLUDE_DIR})
link_directories(${SDL2_image_LIBRARY_DIR})

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIR})

link_libraries(SDL2main SDL2 SDL2_ttf SDL2_image)

add_executable(main src/main.c src/engine.c)
