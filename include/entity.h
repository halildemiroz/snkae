#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>

typedef struct{

    SDL_Rect destRect;
    int speed, direction, score, health;
    enum Direction{
    
        NO = 0,
        UP,
        DOWN,
        LEFT,
        RIGHT
    } dir;

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
