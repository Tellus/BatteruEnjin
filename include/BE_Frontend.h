#ifndef __BE_FRONTEND
#define __BE_FRONTEND

#include <SDL/SDL.h>
#include <iostream>

class BE_Frontend
{
	public:
		BE_Frontend();

		int OnExecute();

		bool OnInit();
		void OnEvent(SDL_Event *event);
		void OnLoop();
		void OnRender();
		void OnCleanUp();

		bool Running;

		SDL_Surface *Screen;
};

#endif
