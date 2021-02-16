#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

// foo.cpp but updated with renderer
// https://www.parallelrealities.co.uk/tutorials/shooter/shooter1.php#exercises
// ^^ used for reference
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
SDL_Surface* sSur = NULL;
SDL_Surface* sHello = NULL;

int main() {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const std::string IMAGE_FILE = "hello_world.bmp";


	// init
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("Why Hello There",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	sSur = SDL_GetWindowSurface(win);

	sHello =  SDL_LoadBMP(IMAGE_FILE.c_str());

	//SDL_BlitSurface(sHello, NULL, sSur, NULL);
	//SDL_UpdateWindowSurface(win);
	
	SDL_Event e;
	bool quit = false;
	while(!quit) {
		// prepare scene
		SDL_SetRenderDrawColor(ren, 96, 128, 255, 255);
		SDL_RenderClear(ren);
		// input handling
		while(SDL_PollEvent(&e) != 0) {
			switch (e.type) {
				case SDL_QUIT:
					quit = true;
					break;
				default:
					break;
			}
		}
		// present scene
		SDL_RenderPresent(ren);

		SDL_Delay(16);
	}


	//SDL_Delay(3000);

	SDL_FreeSurface(sSur);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	win = NULL;
	SDL_Quit();


}

