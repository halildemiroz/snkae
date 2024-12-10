#include "../include/engine.h"
#include "../include/ecs.h"

Engine engine;

int engine_Init(const char* title, int width, int height) {

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Ini failed: %s\n", SDL_GetError());
        return 0;
    }
    
    engine.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(!engine.window) {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        return 0;
    }

    engine.renderer = SDL_CreateRenderer(engine.window, -1, 0);
    if(!engine.renderer) {
        printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        return 0;
    }

    engine.isRunning = true;

    ecs_Init(10);
    ecs_Texture("../assets/IDLE.png");

}

void engine_HandleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            engine.isRunning = 0;
            break;
        default:
            break;
    }

    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    engine.isRunning = 0;
                    break;
                case SDLK_w:
                    ecs_Init(7);
                    ecs_Texture("../assets/ATTACk.png");
                    printf("w");
                    break;
                case SDLK_s:
                    ecs_Init(10);
                    ecs_Texture("../assets/IDLE.png");
                    printf("s");
                    break;
                default:
                    break;
            }
    }

}


void engine_Update() {

    Uint32 currentTime = SDL_GetTicks();
    
    if(currentTime > ecs.lastFrameTime + ecs.animationSpeed){
        ecs.currentFrame = (ecs.currentFrame + 1) % ecs.totalFrames;
        ecs.srcRect.x = ecs.currentFrame * ecs.frameWidth;
        ecs.lastFrameTime = currentTime;
    }

}

void engine_Render(int r, int g, int b, int a) {

    SDL_SetRenderDrawColor(engine.renderer, r, g, b, a);
    SDL_RenderClear(engine.renderer);

    ecs_Render();

    SDL_RenderPresent(engine.renderer);

}

void engine_Clean() {

    SDL_DestroyTexture(ecs.texture);
    SDL_DestroyWindow(engine.window);
    SDL_DestroyRenderer(engine.renderer);
    SDL_Quit();

}
