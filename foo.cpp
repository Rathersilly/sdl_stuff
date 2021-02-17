#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

// foo.cpp but updated with renderer
// https://www.parallelrealities.co.uk/tutorials/shooter/shooter1.php#exercises
// ^^ used for reference
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
SDL_Surface* sSur = NULL;
SDL_Surface* sHello = NULL;
SDL_Texture* tex = NULL;

int main() {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//const int SCREEN_WIDTH = 100;
	//const int SCREEN_HEIGHT = 100;
	const std::string IMAGE_FILE = "hello_world.png";


	// init
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	win = SDL_CreateWindow("Why Hello There",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	tex = IMG_LoadTexture(ren, "hello_world.png");
	SDL_Rect dest;
	dest.x = 0; dest.y = 0;
	// This function appears to se the width and height of dest according to the image size
	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
	//SDL_RenderCopy(ren, tex, NULL, &dest);
	
	SDL_Event e;
	bool quit = false;
	while(!quit) {
		// prepare scene
		SDL_SetRenderDrawColor(ren, 96, 128, 255, 255);
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, tex, NULL, &dest);
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

		//SDL_Delay(3000);
		SDL_Delay(16);
	}


	//SDL_Delay(3000);

	SDL_FreeSurface(sSur);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	win = NULL;
	SDL_Quit();


}

