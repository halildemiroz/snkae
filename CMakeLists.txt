cmake_minimum_required(VERSION 3.18)
project(snkae C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# SDL2 main library
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.30.2
)

# SDL2_image extension
FetchContent_Declare(
  SDL2_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG release-2.8.2
)

# SDL2_ttf extension
FetchContent_Declare(
  SDL2_ttf
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
  GIT_TAG release-2.22.0
)

# SDL build options
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL2IMAGE_SAMPLES OFF CACHE BOOL "" FORCE)
set(SDL2TTF_SAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL2 SDL2_image SDL2_ttf)

# Your executable
add_executable(snkae 
    src/main.c 
    src/game.c 
    src/loader.c 
    src/menu.c 
)

# Link SDL libraries (automatically adds most include dirs)
target_link_libraries(snkae
    SDL2-static
    SDL2_image
    SDL2_ttf
)

target_include_directories(snkae PRIVATE
    ${SDL2_SOURCE_DIR}/include
    ${SDL2_image_SOURCE_DIR}/include
    ${SDL2_ttf_SOURCE_DIR}
)
