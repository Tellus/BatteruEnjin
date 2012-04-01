#include "include/BE_Resource.h"

namespace BE
{
	namespace Primarch
	{
		Resource::Resource(BE::Primarch::Character *parent)
		{
			this->parent = parent;
		}
	}
}