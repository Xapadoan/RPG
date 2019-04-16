#ifndef DEF_LOAD_CONF_FILE
#define DEF_LOAD_CONF_FILE

#include <stdio.h>

#include "../../lib/libMY/libMY_string/includes/MY_str_compare.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_split.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "parseFile.h"

#define SRC_CONFIG_PATH "config/"
#define DEST_CONFIG_PATH "includes/config/"

int	loadConfFile(const char *file_name);

#endif
