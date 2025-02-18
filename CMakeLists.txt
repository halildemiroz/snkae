cmake_minimum_required(VERSION 3.5)
project(snkae C)

set(CMAKE_C_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

link_libraries(SDL2main SDL2 SDL2_ttf SDL2_image)

add_executable(main src/main.c
src/game.c
src/loader.c
src/menu.c
)
