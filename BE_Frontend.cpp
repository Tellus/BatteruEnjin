#include "include/BE_Frontend.h"

BE_Frontend::BE_Frontend()
{
	Running = true;
}

int BE_Frontend::OnExecute()
{
	if (OnInit() == false) return -1;

	SDL_Event event;

	std::cout << "Execution started.\n";
	while (Running == true)
	{
		while (SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}

		OnLoop();
		OnRender();
	}
		
	OnCleanUp();

	return 0;
}

bool BE_Frontend::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	std::cout << "Booting up video mode.\n";

	Screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	SDL_WM_SetCaption("Batteru Enjin Prototype", NULL);

	std::cout << "Booted up.\n";

	if (Screen == NULL)
	{
		std::cout << "Invalid video mode. Bye!\n";
		return false;
	}

	// Load up the image for blitting.
	SDL_Rect src_area;
	src_area.x = 150;
	src_area.y = 150;
//	src_area.w = 99;
//	src_area.h = 80;

	SDL_Rect trg_area;
	trg_area.x = trg_area.y = 30;
//	trg_area.w = trg_area.h = 64;

	this->ShowImg("img/devil_full2.png", 300, 200);
	this->ShowImg("img/devil_full2.png", src_area, trg_area);

	return true;
}

void BE_Frontend::OnEvent(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
	{
		Running = false;
	}
}

void BE_Frontend::OnRender()
{
	this->BlitSurface(this->Temp, 10, 10);

	SDL_Flip(this->Screen);
}

void BE_Frontend::OnLoop()
{

}

void BE_Frontend::OnCleanUp()
{
	SDL_FreeSurface(this->Screen);

	SDL_Quit();
}

bool BE_Frontend::BlitSurface(SDL_Surface *to_blit, int x, int y)
{
	if (to_blit == NULL) return false;

	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	
	SDL_BlitSurface(to_blit, NULL, this->Screen, &destination);

	return true;
}

bool BE_Frontend::BlitSurface(SDL_Surface *to_blit, SDL_Rect source_area, SDL_Rect target_area)
{
	if (to_blit == NULL) return false;

	SDL_BlitSurface(to_blit, &source_area, this->Screen, &target_area);

	return true;
}

bool BE_Frontend::ShowImg(const char *file, int x, int y)
{
	SDL_Surface *lded = BE_Surface::LoadFile(file, true);
	if (lded == NULL) return false;

	this->BlitSurface(lded, x, y);

	return true;
}

bool BE_Frontend::ShowImg(const char *file, SDL_Rect source_area, SDL_Rect target_area)
{
	SDL_Surface *lded = BE_Surface::LoadFile(file, true);
	if (lded == NULL) return false;

	this->BlitSurface(lded, source_area, target_area);

	return true;
}
