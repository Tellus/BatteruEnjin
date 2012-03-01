#include "include/BE_Graphic.h"

void BE_Graphic::Render(SDL_Surface *target, SDL_Rect point)
{
	SDL_BlitSurface(this->GraphicData, NULL, target, point);
	return;
}
