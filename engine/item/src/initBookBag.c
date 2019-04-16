#include "../includes/initBookBag.h"

BookBag	*initBookBag(void)
{
	BookBag *books;
	Book *book;

	book = NULL;
	books = NULL;

	books = malloc(sizeof(*books));
	if (!books) {
		fputs("Memory Error : Failed to allocate memory for book bag\n", stderr);
		return (NULL);
	}

	book = initBook();
	if (!book) {
		fputs("Error : Failed to init book\n", stderr);
		return (NULL);
	}

	books->nb = 0;
	books->weight = 0;
	books->value = 0;
	books->first = book;
	return (books);
}
