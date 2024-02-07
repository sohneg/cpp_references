#include <dlfcn.h>
#include <cstring>

extern "C" int strcmp(const char *s1, const char *s2) {
  // Zeiger auf die echte strcmp-Funktion
  int (*real_strcmp)(const char *, const char *) = reinterpret_cast<int (*)(const char *, const char *)>(dlsym(RTLD_NEXT, "strcmp"));

  return 0;
}
