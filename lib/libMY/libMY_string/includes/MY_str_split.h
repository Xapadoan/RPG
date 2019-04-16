#ifndef DEF_MY_STR_SPLIT
#define DEF_MY_STR_SPLIT

#include <stdlib.h>

#include "MY_str_len.h"
#include "MY_str_substr.h"
#include "MY_str_ncopy.h"

char **MY_str_split(const char *str, const char *delim);

#endif
