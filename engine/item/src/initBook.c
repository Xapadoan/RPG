#include "../includes/initBook.h"

Book	*initBook(void)
{
	Book *book;

	book = NULL;
	book = malloc(sizeof(*book));
	if (!book) {
		fputs("Memory Error : Failed to allocate memory for book\n", stderr);
		return (NULL);
	}

	book->name = NULL;
	book->weight = ITEM_BOOK_DEFAULT_WEIGHT;
	book->value = 0;
	book->preview = NULL;
	book->next = NULL;
	book->read = NULL;

	return (book);
}
