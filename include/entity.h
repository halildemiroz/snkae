#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

typedef struct{

    SDL_Rect destRect;
    int speed, direction, score, health;
    int dir; // 0 = NO, 1 = UP, 2 = DOWN, 3 = LEFT, 4 = RIGHT

} Character;

typedef struct {

    SDL_Rect destRect;

} Apple;

void render_Apple();
void render_Character();

void delete_Apple();

extern Apple apple;
extern Character character;

#endif