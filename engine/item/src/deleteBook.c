#include "../includes/deleteBook.h"

void	deleteBook(Book *book)
{
	if (book->name)
		free(book->name);

	if (book->preview)
		SDL_FreeSurface(book->preview);

	book->next = NULL;
	book->read = NULL;
	free(book);
}
