#include <string>

namespace BE
{
	namespace Primarch
	{
		class Primarch
		{
		public:
			virtual ~Primarch() = 0;
			
			std::string type;
		}
	}
}
