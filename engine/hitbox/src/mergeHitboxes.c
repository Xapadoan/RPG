#include "../includes/mergeHitboxes.h"

Hitbox	*mergeHitboxes(Hitbox *htb1, Hitbox *htb2)
{
	ElemHitbox *current;

	current  = NULL;
	if (!htb1 || !htb1->first)
		return (htb2);
	else if (!htb2 || !htb2->first)
		return (htb1);

	current = htb2->first;
	while (current != NULL && copyToHitbox(current, htb1))
		current = current->next;

	return (htb1);
}
