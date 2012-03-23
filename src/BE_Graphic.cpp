#include "include/BE_Graphic.h"

namespace BE
{
	namespace Frontend
	{
		void Graphic::Render(SDL_Surface *target, SDL_Rect point)
		{
			SDL_BlitSurface(this->GraphicData, NULL, target, point);
			return;
		}
	}
}
