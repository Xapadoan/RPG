#include "../includes/isItemContainer.h"

int	isItemContainer(MapItem *item)
{
	return ((item->id >> (2 * 4)) == 2);
}
