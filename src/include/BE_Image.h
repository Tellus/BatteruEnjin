#pragma once

namespace BE
{
	namespace Frontend
	{
		/**
		 * This class simplifies loading and working with images in SDL contexts. It
		 * can be associated with Entity::Graphic to be 
		 */
		class Image: public Graphic
		{
			Image(const char *file, bool with_alpha = false);

			Image(const char *file);

			Image();

	
		};
	}
}
