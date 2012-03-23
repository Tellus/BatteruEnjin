#include "include/BE_Surface.h"

namespace BE
{
	namespace Frontend
	{
		SDL_Surface* Surface::LoadFile(const char *file, bool alpha)
		{
			// Load the surface.
			SDL_Surface* loadSurf = NULL;
			loadSurf = IMG_Load(file);
			if (loadSurf == NULL) return NULL; // Safety catch.

			// Format it to fit our current surface format. We do this with transparency.
			SDL_Surface* retSurf = NULL;

			if (alpha)
			{
				retSurf = SDL_DisplayFormatAlpha(loadSurf);
			}
			else
			{
				retSurf = SDL_DisplayFormat(loadSurf);
			}

			SDL_FreeSurface(loadSurf); // Free from mem!
			return retSurf;
		}
	}
}
