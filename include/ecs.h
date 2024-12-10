#ifndef ECS_H
#define ECS_H

#include <SDL_image.h>
#include <SDL.h>

typedef struct {
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    int frameWidth, frameHeight;
    int currentFrame, totalFrames;
    int animationSpeed;
    Uint32 lastFrameTime;

} Ecs;

void ecs_Texture();
void ecs_Init();


extern Ecs ecs;

#endif