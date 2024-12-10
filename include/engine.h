#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

typedef struct {

    SDL_Window* window;
    SDL_Renderer* renderer;
    int isRunning;

} Engine;

int engine_Init(const char* title, int width, int height);
void engine_Update();
void engine_Render(int r, int g, int b, int a);
void engine_Clean();
void engine_HandleEvent();

// extern keyword'ü sadece var olduğunu belirtiyo hafızaya tanımlamıyo
// bu durumda engine oluşturulmadı ama bilgisayara var olduğu söylendi ve tekrardan tanımlanmadan kullanıma hazır
extern Engine engine;

#endif
