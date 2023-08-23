#include "test.h"

namespace love
{
	namespace test
	{
		love::Type Test::type("test", &Module::type);

		double Test::customAdd(double a, double b)
		{
			return 2 * (a + b);
		}
	}
}