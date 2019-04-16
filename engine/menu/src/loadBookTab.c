#include "../includes/loadBookTab.h"

int	loadBookTab(TabMenu *menu, BookBag *books) {
	Book *book;

	book = NULL;
	if (!menu | !books) {
		fputs("Error : Missing arguments for load Book Tab\n", stderr);
		return (0);
	}

	if (!menu->tabs) {
		fputs("Error : Menu tab list are not initialized\n", stderr);
		return (0);
	}

	book = books->first;
	while (book->next) {
		if (!addBookDataToTab(menu, book)) {
			fputs("Error : Failed to add book data to tab\n", stderr);
			return (0);
		}
		book = book->next;
	}

	return (1);
}
