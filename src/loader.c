#include "../include/loader.h"
#include <stdlib.h>
#include <time.h> 

Loader loader;

Character character;
Apple apple;

void loader_Init(int w, int h) {

    srand(time(NULL));

    character.destRect.x = 0;
    character.destRect.y = 0;
    character.destRect.w = w;
    character.destRect.h = h;
    character.speed = 10;
    character.health = 5;

    /* ---------------------- */

    apple.destRect.w = 48;
    apple.destRect.h = 48;
    apple.destRect.x = rand() % 700;
    apple.destRect.y = rand() % 500;
    
}
