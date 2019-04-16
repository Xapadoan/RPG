#ifndef DEF_PARSE_FILE
#define DEF_PARSE_FILE

#include <stdio.h>
#include <stdlib.h>

#include "../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_to_upper.h"
#include "../../lib/libMY/libMY_string/includes/MY_str_split.h"
#include "../../lib/libMY/libMY_string/includes/MY_remove_char.h"
#include "../../lib/libMY/libMY_array/includes/MY_free_2d_char.h"

#include "extendAttributeName.h"
#include "writeConfigFile.h"

int	parseFile(FILE *src_file, FILE *dest_file, const char *file_name);
void	putIntro(FILE *file, const char *file_name);

#endif
