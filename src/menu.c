#include "../include/menu.h"
#include "../include/game.h"
#include "SDL2/SDL_render.h"

Menu menu;

void render_Main_Menu(const char* font_Path, SDL_Renderer* renderer) {

    TTF_Init();

    TTF_Font *font = TTF_OpenFont(font_Path, 300);
    if (font == NULL) {
        fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
        return;
    }

    SDL_Color White = {255, 255, 255};

    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, "Play", White);
    if (surfaceMessage == NULL) {
        fprintf(stderr, "Failed to create surface: %s\n", TTF_GetError());
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    if (message == NULL) {
        fprintf(stderr, "Failed to create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surfaceMessage);
        TTF_CloseFont(font);
        return;
    }

    menu.message_Rect.x = 200;
    menu.message_Rect.y = 150;
    menu.message_Rect.w = 400;
    menu.message_Rect.h = 200;

    menu.button_Rect.x = 200;
    menu.button_Rect.y = 150;
    menu.button_Rect.w = 400;
    menu.button_Rect.h = 200;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &menu.button_Rect);

    if (SDL_RenderCopy(renderer, message, NULL, &menu.message_Rect) != 0) {
        fprintf(stderr, "Failed to render copy: %s\n", SDL_GetError());
    }

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
    TTF_CloseFont(font);

}

void render_Game_Menu(const char* font_Path, SDL_Renderer* renderer) {

    // Font stuff

    TTF_Init();
    TTF_Font* font = TTF_OpenFont(font_Path, 300);

    SDL_Color White = {255, 255, 255};
    char healthText[50];
    snprintf(healthText, sizeof(healthText), "Health: %d", character.health);

    char scoreText[50];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", character.score);

    SDL_Surface* surfaceHealth = TTF_RenderText_Solid(font, healthText, White);
    SDL_Surface* surfaceScore = TTF_RenderText_Solid(font, scoreText, White);

    SDL_Texture* health = SDL_CreateTextureFromSurface(renderer, surfaceHealth);
    SDL_Texture* score = SDL_CreateTextureFromSurface(renderer, surfaceScore);

    menu.health_Rect.x = 10;
    menu.health_Rect.y = 10;
    menu.health_Rect.w = 100;
    menu.health_Rect.h = 50;

    menu.score_Rect.x = 10;
    menu.score_Rect.y = 60;
    menu.score_Rect.w = 100;
    menu.score_Rect.h = 50;

    SDL_RenderCopy(renderer, health, NULL, &menu.health_Rect);
    SDL_RenderCopy(renderer, score, NULL, &menu.score_Rect);

    // Snake and Apple rendering
    // Apple
    
    SDL_SetRenderDrawColor(game.renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(game.renderer, &apple.destRect);
    // Snake


    SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game.renderer, &character.destRect);


    collision_Apple();
    collision_Walls(800,600);

    SDL_FreeSurface(surfaceHealth);
    SDL_FreeSurface(surfaceScore);
    SDL_DestroyTexture(health);
    SDL_DestroyTexture(score);
    TTF_CloseFont(font);

}

void render_Lose_Menu(const char* font_Path, SDL_Renderer* renderer) {

    TTF_Init();
    TTF_Font* font = TTF_OpenFont(font_Path, 300);

    SDL_Color White = {255, 255, 255};

    SDL_Surface* message = TTF_RenderText_Solid(font, " You Lost!", White);
    SDL_Surface* retry = TTF_RenderText_Solid(font, "Play Again", White);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, message);
    SDL_Texture* retryTexture = SDL_CreateTextureFromSurface(renderer, retry);

    menu.message_Rect.x = 200;
    menu.message_Rect.y = 150;
    menu.message_Rect.w = 400;
    menu.message_Rect.h = 200;

    menu.button_Rect.x = 200;
    menu.button_Rect.y = 150;
    menu.button_Rect.w = 400;
    menu.button_Rect.h = 200;

    menu.message2_Rect.x = 650;
    menu.message2_Rect.y = 400;
    menu.message2_Rect.w = 100;
    menu.message2_Rect.h = 50;

    menu.button2_Rect.x = 650;
    menu.button2_Rect.y = 400;
    menu.button2_Rect.w = 100;
    menu.button2_Rect.h = 50;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &menu.button_Rect);
    SDL_RenderFillRect(renderer, &menu.button2_Rect);

    SDL_RenderCopy(renderer, texture, NULL, &menu.message_Rect);
    SDL_RenderCopy(renderer, retryTexture, NULL, &menu.message2_Rect);

    SDL_FreeSurface(message);
    SDL_FreeSurface(retry);
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(retryTexture);
    TTF_CloseFont(font);

}
