#include "../includes/applyDurableStaminaPotion.h"

int	applyDurableStaminaPotion(Potion *self, Character *target)
{
	if (!self) {
		fputs("Error : No potion provided\n", stderr);
		return (0);
	}

	if (!target) {
		fputs("Error : No target provided\n", stderr);
		return (0);
	}

	fputs("Warning : applyDurableHealthPotion is not yet implemented\n", stderr);
	return (1);
}
