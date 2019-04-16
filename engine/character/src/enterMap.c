#include "../includes/enterMap.h"

void	enterMap(Team *team, const char *map_name)
{
	if (!setLocationMap(&(team->location), map_name))
		fputs("Warning : Can't set map in location\n", stderr);
}
