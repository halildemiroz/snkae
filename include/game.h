#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

#include "loader.h"
#include "menu.h"
#include "entity.h"

/*
enum Direction{
    
    NO = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT

} dir;
*/


typedef struct {

    SDL_Window* window;
    SDL_Renderer* renderer;
    int isRunning;
    int xpos,ypos;

} Game;

int game_Init(const char* title, int width, int height);
void game_Update();
void game_Render(int r, int g, int b);
void game_Clean();
void game_HandleEvent();

void collision_Apple();
void collision_Walls(int windowWidth, int windowHeight);

void get_Click_Pos();

// extern keyword'ü sadece var olduğunu belirtiyo hafızaya tanımlamıyo
// bu durumda engine oluşturulmadı ama bilgisayara var olduğu söylendi ve tekrardan tanımlanmadan kullanıma hazır
extern Game game;

#endif
