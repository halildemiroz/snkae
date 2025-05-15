cmake_minimum_required(VERSION 3.10)
project(snkae C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(/opt/homebrew/Cellar/sdl2/2.32.2/include)

link_directories(/opt/homebrew/Cellar/sdl2/2.32.2/lib)

link_libraries(SDL2main SDL2 SDL2_ttf SDL2_image)

add_executable(snkae src/main.c
src/game.c
src/loader.c
src/menu.c
)
