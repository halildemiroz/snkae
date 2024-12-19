#include "../include/game.h"

Game game;

enum Menus {

    MAIN = 0,
    GAME,
    LOSE,

} gameMenus;

int game_Init(const char* title, int width, int height) {

    if(SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 0;
    }
    
    game.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(!game.window) {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        return 0;
    }

    game.renderer = SDL_CreateRenderer(game.window, -1, 0);
    if(!game.renderer) {
        printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        return 0;
    }

    loader_Init(48,48);

    game.isRunning = 1;

}

void collision_Walls(int windowWidth, int windowHeight) {

    if (character.destRect.x < 0) {

        character.destRect.x = 0;
        printf("Collision with left wall!\n");
        
        character.health--;
        
        if(character.health > 0) {
        
        character.destRect.x = 0;
        character.destRect.y = 0;

        printf("Health: %d\n", character.health);

        apple.destRect.x = rand() % (800 - apple.destRect.w);
        apple.destRect.y = rand() % (600 - apple.destRect.h);
        character.dir = 0;
        }

    }

    if (character.destRect.x + character.destRect.w > windowWidth) {
        
        character.destRect.x = windowWidth - character.destRect.w;
        printf("Collision with right wall!\n");
        
        character.health--;
       
        if(character.health > 0) {
        
        character.destRect.x = 0;
        character.destRect.y = 0;

        printf("Health: %d\n", character.health);

        apple.destRect.x = rand() % (800 - apple.destRect.w);
        apple.destRect.y = rand() % (600 - apple.destRect.h);
        character.dir = 0;
        }
    }

    if (character.destRect.y < 0) {
        
        character.destRect.y = 0;
        printf("Collision with top wall!\n");
        
        character.health--;

        if(character.health > 0) {
        
        character.destRect.x = 0;
        character.destRect.y = 0;

        printf("Health: %d\n", character.health);

        apple.destRect.x = rand() % (800 - apple.destRect.w);
        apple.destRect.y = rand() % (600 - apple.destRect.h);
        character.dir = 0;
        }

    }
    if (character.destRect.y + character.destRect.h > windowHeight) {

        character.destRect.y = windowHeight - character.destRect.h;
        printf("Collision with bottom wall!\n");

        character.health--;

        if(character.health > 0) {
        
        character.destRect.x = 0;
        character.destRect.y = 0;

        printf("Health: %d\n", character.health);

        apple.destRect.x = rand() % (800 - apple.destRect.w);
        apple.destRect.y = rand() % (600 - apple.destRect.h);
        character.dir = 0;
        }

    }
}

void collision_Apple() {

    if (character.destRect.x < apple.destRect.x + apple.destRect.w &&

        character.destRect.x + character.destRect.w > apple.destRect.x &&
        character.destRect.y < apple.destRect.y + apple.destRect.h &&
        character.destRect.h + character.destRect.y > apple.destRect.y) {

            printf("Collision detected!\n");

            apple.destRect.x = rand() % (800 - apple.destRect.w);
            apple.destRect.y = rand() % (600 - apple.destRect.h);

            character.score++;

            printf("Score: %d\n", character.score);
            printf("Health: %d\n", character.health);

    }

}

void game_Render(int r, int g, int b) {

    SDL_SetRenderDrawColor(game.renderer, r, g, b, 255);
    SDL_RenderClear(game.renderer);

    if(game.xpos >= 200 && game.xpos <= 600 && game.ypos >= 150 && game.ypos <= 350) {
        gameMenus = GAME;
    }
    if(character.health == 0) {
        gameMenus = LOSE;
    }

    // 650-700 400-450

    if(gameMenus == LOSE && game.xpos < 700 && game.xpos > 650 && game.ypos < 450 && game.ypos > 400) {
        gameMenus = MAIN;
        character.health = 5;
        character.score = 0;
        character.destRect.x = 0;
        character.destRect.y = 0;
        apple.destRect.x = rand() % 700;
        apple.destRect.y = rand() % 500;
        game.xpos = 0;
        game.ypos = 0;
        gameMenus = GAME;
        character.dir = 0;
    }

    switch (gameMenus) {
        case 0:
            render_Main_Menu("../assets/font.ttf", game.renderer);
            break;
        case 1:
            render_Game_Menu("../assets/font.ttf", game.renderer);
            break;
        case 2:
            render_Lose_Menu("../assets/font.ttf", game.renderer);
            break;

    }


    SDL_RenderPresent(game.renderer);

}

void game_Update() {

    if(character.dir == 1) {
        character.destRect.y-=character.speed/2.5;
    }
    else if(character.dir == 2) {
        character.destRect.y+=character.speed/2.5;
    }
    else if(character.dir == 3) {
        character.destRect.x-=character.speed/2.5;
    }
    else if(character.dir == 4) {
        character.destRect.x+=character.speed/2.5;
    }

}

void game_HandleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        game.isRunning = 0;
        break;
    default:
        break;
    }

    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&game.xpos, &game.ypos);
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {

        case SDLK_ESCAPE:
            game.isRunning = 0;
            break;

        case SDLK_w:
            character.dir = 1;
            break;

        case SDLK_s:
            character.dir = 2;
            break;

        case SDLK_a:
            character.dir = 3;
            break;

        case SDLK_d:
            character.dir = 4;
            break;

        }
        break;
    default:
        break;
    }

}

void game_Clean() {

    SDL_DestroyWindow(game.window);
    SDL_DestroyRenderer(game.renderer);
    SDL_Quit();

}
