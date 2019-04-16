#include "../includes/applyStaminaPotion.h"

int	applyStaminaPotion(Potion *self, Character *target)
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

	target->stamina += self->magnitude;
	if (target->stamina > target->max_stamina)
		target->stamina = target->max_stamina;
	else if (target->stamina < 0) {
		target->stamina = 0;
		target->cmbt_state = CHARACTER_CMBT_STATE_EXHAUSTED;
	}

	return (1);
}
