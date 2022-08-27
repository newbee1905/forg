#ifndef UTILS_H
#define UTILS_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <luajit.h>
#include <stdlib.h> // fopen

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? a : b)

#define check(a)                                                               \
  if (a != NULL)                                                               \
  free(a)

#define error_lua_(L, fmt, ...)                                                \
  do {                                                                         \
    fprintf(stderr, "\033[31myaf:\033[0m " fmt "\n", ##__VA_ARGS__);           \
    lua_pop(L, 1);                                                             \
    lua_close(L);                                                              \
    exit(1);                                                                   \
  } while (0)

#define error_(fmt, ...)                                                       \
  do {                                                                         \
    fprintf(stderr, "\033[31myaf:\033[0m " fmt "\n", ##__VA_ARGS__);           \
    exit(1);                                                                   \
  } while (0)

#endif // UTILS_H
