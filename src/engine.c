#include "../include/engine.h"

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

    engine.isRunning = 1;
    
}

void engine_Render() {

    SDL_SetRenderDrawColor(engine.renderer, 0, 0, 0, 255);
    SDL_RenderClear(engine.renderer);

    // SDL_RenderCopy(engine.renderer, engine.texture, &engine.srcRect, &engine.destRect);

    SDL_RenderPresent(engine.renderer);

}

void engine_HandleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        engine.isRunning = 0;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                engine.isRunning = 0;
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }

}


void engine_Update() {}

void engine_Clean() {

    SDL_DestroyWindow(engine.window);
    SDL_DestroyRenderer(engine.renderer);
    SDL_Quit();

}
