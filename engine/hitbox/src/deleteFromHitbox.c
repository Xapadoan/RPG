#include "../includes/deleteFromHitbox.h"

int	deleteFromHitbox(Hitbox *hitbox, int pos)
{
	int i;
	ElemHitbox	*to_delete;
	ElemHitbox	*to_delete_prev;

	to_delete = NULL;
	to_delete_prev = NULL;
	i = 0;

	if (!hitbox) {
		fputs("Warning : Cannot delete from empty hitbox\n", stderr);
		return (0);
	}

	if (pos == 0) {
		free(to_delete_prev);
		to_delete = hitbox->first;
		hitbox->first = hitbox->first->next;
	} else {
		to_delete_prev = hitbox->first;
		while (++i < pos)
			to_delete_prev = to_delete_prev->next;
		to_delete->next = to_delete_prev->next;
		to_delete_prev->next = to_delete_prev->next->next;
	}
	free(to_delete);
	hitbox->len--;
	return (1);
}
