#ifndef DEF_PARSER_WRITE_CONFIG_FILE
#define DEF_PARSER_WRITE_CONFIG_FILE

#include <stdlib.h>
#include <stdio.h>

#include "../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_append.h"

void	writeConfigFile(FILE *file, char *str);

#endif
