#include "../includes/initCharacter.h"

int	initCharacter(Character *character)
{
	character->name = NULL;
	character->level = 1;
	character->gender = 0;
	character->race = 0;

	character->luck = 50;
	character->strn = 50;
	character->agi = 50;
	character->intel = 50;
	character->acc = 50;
	character->mov_speed = 2;

	character->active_potions = initPotionBag();
	if (!character->active_potions) {
		fputs("Error : Failed to initialize active potions\n", stderr);
		return (0);
	}
	if (!(character->bag = initItemBag())) {
		fputs("Error : Failed to initialize bag\n", stderr);
		return (0);
	}

	character->max_health = 100;
	character->health = character->max_health;
	character->max_stamina = 100;
	character->stamina = character->max_stamina;

	character->cmbt_state = CHARACTER_CMBT_STATE_NORMAL;

	character->confirmed = 0;
	character->state_changed = 0;
	character->interacting_item = NULL;

	character->sprite = NULL;
	character->sprite2 = NULL;
	character->sprite3 = NULL;
	character->dir = DOWN;
	character->state = CHARACTER_STATE_STANDING;

	return (1);
}
