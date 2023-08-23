
#include "wrap_test.h"
#include "test.h"
#include "common/Module.h"

namespace love
{
	namespace test
	{
#define instance() (Module::getInstance<Test>(Module::M_TEST))

		int w_customadd(lua_State* L)
		{
			double a = lua_tonumber(L, 1);
			double b = lua_tonumber(L, 2);
			double res = instance()->customAdd(a, b);
			lua_pushnumber(L, res);

			return 1;
		}

		//funciones expuestas
		// List of functions to wrap.
		static const luaL_Reg functions[] =
		{
			{ "customAdd",w_customadd },
			//aqui habra mas
			{ 0, 0 }
		};

		extern "C" int luaopen_love_test(lua_State * L)
		{
			Test* instance = instance();
			if (instance == nullptr)
			{
				luax_catchexcept(L, [&]() { instance = new love::test::Test(); });
			}
			else
			{
				instance()->retain();
			}

			WrappedModule w;
			w.module = instance;
			w.name = "test";
			w.type = &Test::type;
			w.functions = functions;
			w.types = 0;

			int n = luax_register_module(L, w);
			return n;

		}


	}
}



