#ifndef MENUS_H
#define MENUS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string.h>

typedef struct{

    TTF_Font *font;
    SDL_Rect message_Rect, button_Rect, health_Rect, score_Rect, message2_Rect, button2_Rect;

} Menu;

extern Menu menu;

void render_Main_Menu(const char *font_Path, SDL_Renderer *renderer);
void render_Game_Menu(const char *font_Path, SDL_Renderer *renderer);
void render_Lose_Menu(const char *font_Path, SDL_Renderer *renderer);

#endif
