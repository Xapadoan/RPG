#include "../includes/initArmor.h"

Armor	*initArmor(void)
{
	Armor *armor;

	armor = NULL;
	armor = malloc(sizeof(*armor));
	if (!armor) {
		fputs("Error : Failed to allocate memory for armor\n", stderr);
		return (NULL);
	}

	armor->name = NULL;
	armor->is_equiped = 0;
	armor->weight = 0;
	armor->value = 0;
	armor->rating = 0;
	armor->part = 0;
	armor->preview = NULL;
	armor->sprites = initSpriteList();
	if (!armor->sprites) {
		fputs("Error : Failed to initialize sprite list for armor\n", stderr);
		return (NULL);
	}
	armor->next = NULL;

	return (armor);
}
