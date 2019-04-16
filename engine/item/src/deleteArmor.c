#include "../includes/deleteArmor.h"

void	deleteArmor(Armor *armor)
{
	free(armor->name);
	SDL_FreeSurface(armor->preview);
	deleteSpriteList(armor->sprites);
	armor->next = NULL;
	free(armor);
}
