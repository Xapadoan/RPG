#include "../includes/addCopyToTabList.h"

int	addCopyToTabList(TabList *list, Tab *tab) {
	if (!list | !tab) {
		fputs("Arg Error : Missing arguments for addCopyToTabList\n", stderr);
		return (0);
	}

	return (1);
}
