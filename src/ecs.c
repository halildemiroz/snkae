#include "../include/ecs.h"

Ecs ecs;

void ecs_Init() {

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
    ecs.totalFrames = 10;
    ecs.animationSpeed = 100;
    ecs.lastFrameTime = 0;

}