#ifndef capp_h
#define capp_h

#include <SDL2/SDL.h>
class CApp {
	private:
		bool 			Running;

		SDL_Surface*	Surf_Display;

	public:
		CApp();
		
		int OnExecute();

		bool OnInit();
		void OnEvent(SDL_Event*);
		void OnLoop();
		void OnRender();
		void OnCleanup();
};

#endif

