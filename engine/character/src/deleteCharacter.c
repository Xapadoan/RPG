#include "deleteCharacter.h"

void	deleteCharacter(Character *character)
{
	free(character->name);
	SDL_FreeSurface(character->sprite);
	SDL_FreeSurface(character->sprite2);
	SDL_FreeSurface(character->sprite3);
	deletePotionBag(character->active_potions);
	deleteItemBag(character->bag);
}
