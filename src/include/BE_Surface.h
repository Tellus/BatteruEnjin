#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace BE
{
	namespace Frontend
	{
		class Surface
		{
			public:
				Surface();

				static SDL_Surface* LoadFile(const char *path, bool alpha);
		};
	}
}
