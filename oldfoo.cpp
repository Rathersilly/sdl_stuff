#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

SDL_Window* win = NULL;
SDL_Surface* sur = NULL;
SDL_Surface* hello = NULL;

int main() {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const std::string IMAGE_FILE = "hello_world.bmp";



	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("Why Hello There",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	sur = SDL_GetWindowSurface(win);
	hello =  SDL_LoadBMP(IMAGE_FILE.c_str());

	SDL_BlitSurface(hello, NULL, sur, NULL);
	SDL_UpdateWindowSurface(win);
	
	SDL_Event e;
	bool quit = false;
	while(!quit) {
		while(SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT ) {
				quit = true;
			}
		}
	}


	//SDL_Delay(3000);

	SDL_FreeSurface(sur);
	SDL_DestroyWindow(win);
	win = NULL;
	SDL_Quit;


}
