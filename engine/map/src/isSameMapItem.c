#include "../includes/isSameMapItem.h"

int	isSameMapItem(MapItem *item1, MapItem *item2) {
	if (!(item1->pos.x == item2->pos.y\
			&& item1->pos.y == item2->pos.y))
		return (0);
	return (MY_str_compare(item1->name, item2->name));
}
