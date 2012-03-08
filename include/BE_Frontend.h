#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include "include/BE_Surface.h"

namespace BE
{
	namespace Frontend
	{
		class Frontend
		{
			public:
				Frontend();

				int OnExecute();

				bool OnInit();
				void OnEvent(SDL_Event *event);
				void OnLoop();
				void OnRender();
				void OnCleanUp();

				bool Running;

				SDL_Surface *Screen;
				SDL_Surface *Temp;

				// Simple method to display an image on-screen.
				bool ShowImg(const char *file, int x, int y);
				bool ShowImg(const char *file, SDL_Rect dest);

				/**
				 * Displays an image on the screen surface. This override allows you
				 * to define the target area as well as which part of the source surface
				 * you want displayed.
				 * \param file Path to the image you want loaded. Proxies IMG_Load.
				 * \param dest The destination rectangle on the screen.
				 * \param fragment The area of the source you want drawn.
				 * \return True if succesful, false otherwise.
				 **/
				bool ShowImg(const char *file, SDL_Rect source_area, SDL_Rect target_area);

			protected:
				/**
				 * Blits a surface to the screen in the defined area. Frontend will
				 * handle the actual swapping for you.
				 **/
				bool BlitSurface(SDL_Surface *to_blit, int x, int y);

				/**
				 * Draws a surface to the screen in the defined area. Frontend will
				 * handle the blitting afterwards.
				 * \param to_blit The surface you want to blit.
				 * \param source_area Rect of to_blit you want blitted.
				 * \param target_area Rect of the screen you want to blit onto.
				 * \return True if succesful, false otherwise.
				 */
				bool BlitSurface(SDL_Surface *to_blit, SDL_Rect source_area, SDL_Rect target_area);
		};
	}
}
