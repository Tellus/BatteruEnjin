

/**
 * This class simplifies loading and working with images in SDL contexts. It
 * can be associated with BE_Entity::Graphic to be 
 */
class BE_Image: public BE_Graphic
{
	BE_Image(const char *file, bool with_alpha = false);

	BE_Image(const char *file);

	BE_Image();

	
};
