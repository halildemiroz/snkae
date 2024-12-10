#define SDL_MAIN_HANDLED
#include "../include/engine.h"

#define FPS 60
#define FRAME_DELAY (1000/FPS)

int main(int argc, char* argv[]) {
	
	engine_Init("Game", 800, 600);

	unsigned int frameStart, frameTime;

	while(engine.isRunning) {

		frameStart = SDL_GetTicks();

		engine_HandleEvent();
		engine_Update();
		engine_Render(61, 81, 191, 100);


		frameTime = SDL_GetTicks() - frameStart;

		if(frameTime < FRAME_DELAY){
			SDL_Delay(FRAME_DELAY- frameTime);
		}
	
	}

	engine_Clean();

	return 0;
}
