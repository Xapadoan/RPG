#include "../includes/chooseMapItemAction.h"

void	chooseMapItemAction(MapItem *item)
{
	int hashed;

	hashed = hashItemName(item->name);
	switch (hashed) {
		case (BED) :
			item->action = &sleep;
			break;
		case (TABLE) :
			item->action = NULL;
			break;
		case (OVEN) :
			item->action = NULL;
			break;
		case (DESK) :
			item->action = &openItemContainer;
			break;
		case (CHAIR) :
			item->action = &sitOnChair;
			break;
		default :
			fprintf(stderr, "Warning : item name not linked to action : %s (%d)\n", item->name, hashed);
			break;
	}
}

int	hashItemName(const char *name)
{
	int res;
	int	i;

	res = 0;
	i = 0;
	while (name[i] != '\0') {
		res += (name[i] - 97) * MY_pow(10, i + 1);
		i++;
	}

	return (res);
}
