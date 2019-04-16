#include "../includes/deleteWeapon.h"

void	deleteWeapon(Weapon *weapon)
{
	free(weapon->name);
	SDL_FreeSurface(weapon->preview);
	deleteSpriteList(weapon->sprites);
	weapon->next = NULL;
	free(weapon);
}
