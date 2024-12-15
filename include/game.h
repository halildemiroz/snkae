#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {

    SDL_Window* window;
    SDL_Renderer* renderer;
    int isRunning;

} Game;

int game_Init(const char* title, int width, int height);
void game_Update();
void game_Render(int r, int g, int b);
void game_Clean();
void game_HandleEvent();
void collision();

// extern keyword'ü sadece var olduğunu belirtiyo hafızaya tanımlamıyo
// bu durumda engine oluşturulmadı ama bilgisayara var olduğu söylendi ve tekrardan tanımlanmadan kullanıma hazır
extern Game game;

#endif
