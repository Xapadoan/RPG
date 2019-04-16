#include "../includes/deleteLocation.h"

void	deleteLocation(Location *location)
{
	free(location->map_name);
}
