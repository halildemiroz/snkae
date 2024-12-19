cmake_minimum_required(VERSION 3.5)
project(snkae C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2/include")
set(SDL2_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2/lib")

set(SDL2_image_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2_image/include")
set(SDL2_image_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2_image/lib")
set(SDL2_image_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2_image/cmake")

set(SDL2_ttf_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2_ttf/include")
set(SDL2_ttf_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2_ttf/lib/x64")
set(SDL2_ttf_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL2_ttf/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_image_INCLUDE_DIR})
link_directories(${SDL2_image_LIBRARY_DIR})

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIR})

include_directories(${SDL2_ttf_INCLUDE_DIR})
include_directories(${SDL2_ttf_LIBRARY_DIR})

link_libraries(SDL2main SDL2 SDL2_ttf SDL2_image)

add_executable(main src/main.c
src/game.c
src/loader.c
src/menu.c
)
