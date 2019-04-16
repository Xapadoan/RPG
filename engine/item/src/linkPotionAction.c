#include "../includes/linkPotionAction.h"

int	linkPotionAction(Potion *potion)
{
	if (!potion) {
		fputs("Error : No potion provided\n", stderr);
		return (0);
	}

	switch (potion->id) {
		case (0) :
			potion->use = &applyHealthPotion;
			break;
		default :
			fputs("Warning : Unknown potion id\n", stderr);
			return (0);
			break;
	}

	return (1);
}
