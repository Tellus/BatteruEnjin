#include <SDL/SDL.h>

class BE_Graphic
{
	public:
	bool active = true;
	bool visible = true;
	float x = 0;
	float y = 0;

	BE_Graphic();
	
	/**
	 * Renders the graphic to a surface. Typically the screen, but it could be
	 * a screen-by-proxy (say a BE_World surface).
	 * \param target Target surface to render to.
	 * \param point Target area of rendering. The entire Graphic is always rendered.
	 * \note Usually you needn't override this function yourself, and mostly the
	 * parent container (BE_World or such) will handle the calls for you.
	 * \todo Add version with camera support.
	 */
	virtual Render(SDL_Surface *target, SDL_Rect point);
	virtual Update();

	protected:
	/**
	 * The true data area. Any BE_Graphic child must use this as the basis of
	 * their rendering action if they don't really want to bother themselves.
	 */
	SDL_Surface *GraphicData;
}
