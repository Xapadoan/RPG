#include "../includes/deleteSpriteList.h"

int	deleteSpriteList(SpriteList *list)
{
	while (list->len > 0)
		if (!deleteFromSpriteList(list, 0)) {
			fputs("Warning : Failed to delete sprite list\n", stderr);
			return (0);
		}
	free(list);

	return (1);
}
