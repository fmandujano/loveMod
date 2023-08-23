#ifndef LOVE_WRAP_TEST_H
#define LOVE_WRAP_TEST_H

#include "common/runtime.h"

namespace love
{
	namespace test
	{
		extern "C" LOVE_EXPORT int luaopen_love_test(lua_State* L);
	}
}

#endif