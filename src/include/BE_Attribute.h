#pragma once

namespace BE
{
	namespace Primarch
	{
		class Attribute
		{
		public:
			int value;
		
			Attribute(int val);
			Attribute & operator=(const int val);
			Attribute & operator+=(const Attribute to_add);
			Attribute & operator+(const Attribute other);
		};
	}
}
