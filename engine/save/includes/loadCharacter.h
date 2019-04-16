#ifndef DEF_LOAD_CHARACTER
#define DEF_LOAD_CHARACTER

#include <stdio.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

#include "../../character/includes/Character.h"

void	loadCharacter(Character *to_load, FILE *save_file);

#endif
