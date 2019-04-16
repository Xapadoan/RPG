#include "../includes/applyHealthPotion.h"

int	applyHealthPotion(Potion *self, Character *target)
{
	if (!self) {
		fputs("Error : No potion provided\n", stderr);
		return (0);
	}

	if (!target) {
		fputs("Error : No target provided\n", stderr);
		return (0);
	}

	if (target->cmbt_state == CHARACTER_CMBT_STATE_DEAD)
		return (1);

	target->health += self->magnitude;
	if (target->health > target->max_health)
		target->health = target->max_health;
	else if (target->health < 0) {
		target->health = 0;
		target->cmbt_state = CHARACTER_CMBT_STATE_DEAD;
	}

	return (1);
}
