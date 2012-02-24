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

	std::cout << "Booted up.\n";

	if (Screen == NULL)
	{
		std::cout << "Invalid video mode. Bye!\n";
		return false;
	}

	return true;
}

void BE_Frontend::OnEvent(SDL_Event *event)
{

}

void BE_Frontend::OnRender()
{

}

void BE_Frontend::OnLoop()
{

}

void BE_Frontend::OnCleanUp()
{
	SDL_Quit();
}
