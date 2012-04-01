#include "include/BE_Attribute.h"

namespace BE
{
	namespace Primarch
	{
		Attribute::Attribute(int val)
		{
			this->value = val;
		}
		
		Attribute & Attribute::operator=(const int val)
		{
			this->value = val;
			return *this;
		}
		
		Attribute & Attribute::operator+=(const Attribute to_add)
		{
			this->value += to_add.value;
			return *this;
		}
		
		Attribute & Attribute::operator+(const Attribute other)
		{
			return Attribute(*this) += other;
		}
	}
}