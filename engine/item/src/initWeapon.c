#include "../includes/initWeapon.h"

Weapon	*initWeapon(void)
{
	Weapon *weapon;

	weapon = NULL;
	weapon = malloc(sizeof(*weapon));
	if (!weapon) {
		fputs("Memory Error : Failed to allocate memory for weapon\n", stderr);
		return (NULL);
	}

	weapon->name = NULL;
	weapon->is_equiped = 0;
	weapon->weight = 0;
	weapon->value = 0;
	weapon->dammage = 0;
	weapon->crit_chance = 0;
	weapon->preview = NULL;
	weapon->sprites = initSpriteList();
	if (!weapon->sprites) {
		fputs("Error : Failed to initialize sprite list\n", stderr);
		return (NULL);
	}

	weapon->next = NULL;

	return (weapon);
}
