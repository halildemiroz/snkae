#include <stdatomic.h>
#define SDL_MAIN_HANDLED
#include "../include/game.h"
#include <stdio.h>
#define FPS 60
#define FRAME_DELAY (1000/FPS)

int main(int argc, char* argv[]) {

	game_Init("Snkae", 800, 600);

	unsigned int frameStart, frameTime;

	while(game.isRunning) {

		frameStart = SDL_GetTicks();

		game_Render(0,0,0);
		game_HandleEvent();
		game_Update();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameTime < FRAME_DELAY){
			SDL_Delay(FRAME_DELAY- frameTime);
		}
	
	}

	game_Clean();

	return 0;
}
