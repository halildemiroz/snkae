#ifndef LOADER_H
#define LOADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"

typedef struct {

    SDL_Texture* texture;

} Loader;

extern Loader loader;

void loader_Init(int w, int h);

void loader_LoadTexture(const char* path, SDL_Renderer* renderer);


#endif
