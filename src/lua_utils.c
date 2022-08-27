#include "lua_utils.h"
#include "utils.h"

int getfieldbyid_str(lua_State *L, const int key, char **out_str) {
  lua_pushnumber(L, key);
  lua_gettable(L, -2);
  if (lua_isnil(L, -1))
    return 1;
  if (!lua_isstring(L, -1)) {
    error_lua_(L, "module's name must be a string");
  }
  const char *res = lua_tostring(L, -1);
  *out_str = (char *)malloc((strlen(res) + 1));
  strcpy(*out_str, res);
  lua_pop(L, 1);

  return 0;
}

_Bool lua_getbool(lua_State *L, const char *name) {
  _Bool res;
  lua_getglobal(L, name);
  switch (lua_type(L, -1)) {
  case LUA_TNIL:
    res = false;
    lua_pop(L, 1);
    break;
  case LUA_TBOOLEAN:
    res = lua_toboolean(L, -1);
    lua_pop(L, 1);
    break;
  default:
    error_lua_(L, "'%s' must be a boolean", name);
    break;
  }
  return res;
}
