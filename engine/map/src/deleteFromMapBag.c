#include "../includes/deleteFromMapBag.h"

int	deleteFromMapBag(MapBag *bag, int pos)
{
	int i;
	MapItem	*to_delete;
	MapItem	*to_delete_prev;

	to_delete = NULL;
	to_delete_prev = NULL;
	i = 0;

	if (!bag || !bag->first) {
		fputs("Warning : Cannot delete from empty bag\n", stderr);
		return (0);
	}

	if (pos <= 0) {
		to_delete = bag->first;
		bag->first = bag->first->next;
	} else {
		to_delete_prev = bag->first;
		while (++i < pos)
			to_delete_prev = to_delete_prev->next;
		to_delete = to_delete_prev->next;
		to_delete_prev->next = to_delete_prev->next->next;
	}
	deleteMapItem(to_delete);
	bag->len--;
	return (1);
}
