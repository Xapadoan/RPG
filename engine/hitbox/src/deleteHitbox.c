#include "../includes/deleteHitbox.h"

int	deleteHitbox(Hitbox *hitbox)
{
	if (!hitbox)
		return (1);

	while (hitbox->len > 0 && hitbox->first != NULL)
		if (!deleteFromHitbox(hitbox, 0)) {
			fputs("Error : Failed to delete element of hitbox\n", stderr);
			return (0);
		}
	free(hitbox);
	return (1);
}
