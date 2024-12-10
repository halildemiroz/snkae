#include "../include/ecs.h"

Ecs ecs;

void ecs_Init(int totalFrames) {

    ecs.destRect.x = 0;
    ecs.destRect.y = 0;
    ecs.destRect.w = 288;
    ecs.destRect.h = 288;

    ecs.srcRect.x = 0;
    ecs.srcRect.y = 0;
    ecs.srcRect.w = 96;
    ecs.srcRect.h = 96;

    ecs.frameWidth = 96;
    ecs.frameHeight = 96;
    ecs.currentFrame = 0;
    ecs.totalFrames = totalFrames;
    ecs.animationSpeed = 100;
    ecs.lastFrameTime = 0;

}

void ecs_Texture(const char* texturePath){
    
    SDL_Surface* surface = IMG_Load(texturePath);
    ecs.texture = SDL_CreateTextureFromSurface(engine.renderer, surface);

}

void ecs_Render() {

    SDL_RenderCopy(engine.renderer, ecs.texture, &ecs.srcRect, &ecs.destRect);

}
