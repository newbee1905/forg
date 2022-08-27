#include <lualib.h>
#include <lauxlib.h>
#include <lua.h>
#include <luajit.h>
#include <stdio.h>

#include "config.h" // filename
#include "utils.h" // error_lua_

int main(int argc, char **argv) {
	char buff[256];
	int error;
	lua_State *L;

	L = lua_open();
	luaopen_base(L);
	luaopen_string(L);
	luaopen_math(L);

  if (luaL_dofile(L, filename))
    error_lua_(L, "cannot run configuration file: %s", lua_tostring(L, -1));

  return 0;
}
