#include "include/BE_Surface.h"

SDL_Surface* BE_Surface::LoadFile(const char *file)
{
	// Load the surface.
	SDL_Surface* loadSurf = NULL;
	loadSurf = IMG_Load(file);
	if (loadSurf == NULL) return NULL; // Safety catch.

	// Format it to fit our current surface format.
	SDL_Surface* retSurf = SDL_DisplayFormat(loadSurf);

	SDL_FreeSurface(loadSurf); // Free from mem!
	return retSurf;
}
