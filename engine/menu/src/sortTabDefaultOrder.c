#include "../includes/sortTabDefaultOrder.h"

int	sortTabDefaultOrder(Tab *tab)
{
	unsigned int i;
	TabEntry *current;

	current = NULL;
	i = 0;
	if (!tab) {
		fputs("Arg Error : Missing arguments for sortTabDefaultOrder\n", stderr);
		return (0);
	}

	if (!tab->first)
		return (1);

	current = tab->first;
	while (current) {
		current->display_pos = i;
		current = current->next;
		i++;
	}

	return (1);
}
