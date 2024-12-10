#ifndef ECS_H
#define ECS_H

#include <SDL_image.h>
#include <SDL.h>
#include "../include/engine.h"

typedef struct {
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    int frameWidth, frameHeight;
    int currentFrame, totalFrames;
    int animationSpeed;
    Uint32 lastFrameTime;

} Ecs;

void ecs_Texture(const char* texturePath);
void ecs_Init(int totalFrames);
void ecs_Render();


extern Ecs ecs;

#endif
