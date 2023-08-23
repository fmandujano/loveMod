#ifndef LOVE_TEST_H
#define LOVE_TEST_H

//modulo test 
#include "common/Module.h"
namespace love
{
	namespace test
	{
		class Test :public Module
		{
		public:
			static love::Type type;

			ModuleType getModuleType() const override {
				return M_TEST;
			}

			const char* getName() const override
			{
				return "love.test";
			}

			//definir nuestras propias funciones expuestas a lua
			double customAdd(double a, double b);
		};
	}
}









#endif

