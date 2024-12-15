#include "../include/game.h"
#include "../include/loader.h"

Game game;

enum Direction{
    
    NO = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT

} dir;

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
        dir = NO;
        }

        else
            game.isRunning = 0;
    
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
        dir = NO;
        }

        else
            game.isRunning = 0;

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
        dir = NO;
        }

        else
            game.isRunning = 0;

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
        dir = NO;
        }

        else
            game.isRunning = 0;

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

    SDL_SetRenderDrawColor(game.renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(game.renderer, &apple.destRect);

    SDL_SetRenderDrawColor(game.renderer, 0,0,255,255);
    SDL_RenderFillRect(game.renderer, &character.destRect);

    collision_Apple();
    collision_Walls(800,600);

    SDL_RenderPresent(game.renderer);

}

void game_Update() {

    if(dir == UP) {
        character.destRect.y-=character.speed/2.5;
    }
    else if(dir == DOWN) {
        character.destRect.y+=character.speed/2.5;
    }
    else if(dir == LEFT) {
        character.destRect.x-=character.speed/2.5;
    }
    else if(dir == RIGHT) {
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
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        
        case SDLK_w:
            dir = UP;
            break;
        case SDLK_s:
            dir = DOWN;
            break;
        case SDLK_a:
            dir = LEFT;
            break;
        case SDLK_d:
            dir = RIGHT;
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
