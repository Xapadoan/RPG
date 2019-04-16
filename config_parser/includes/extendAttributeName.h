#ifndef DEF_PARSER_EXTEND_ATTRIBUTE_NAME
#define DEF_PARSER_EXTEND_ATTRIBUTE_NAME

#include <stdlib.h>

#include "../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_to_upper.h"

char	*extendAttributeName(char *attribute_name, char *to_add);

#endif
