#include "../includes/deleteBookBag.h"

void	deleteBookBag(BookBag *books)
{
	Book *book;

	book = books->first;
	while (book) {
		books->first = book->next;
		deleteBook(book);
		book = books->first;
	}

	free(books);
}
