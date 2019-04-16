#ifndef DEF_SET_LOCATION_MAP
#define DEF_SET_LOCATION_MAP

#include <stdio.h>
#include <stdlib.h>
#include "Location.h"

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_clear_string.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

int	setLocationMap(Location *location, const char *map_name);

#endif
