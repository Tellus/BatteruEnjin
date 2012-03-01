#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class BE_Surface
{
	public:
		BE_Surface();

		static SDL_Surface* LoadFile(const char *path);
};
