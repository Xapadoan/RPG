#include "../includes/loadBookBag.h"

int	loadBookBag(BookBag *books, FILE *file)
{
	char line[50];
	int value;
	Book *book;

	value = 0;
	//Init book
	book = initBook();
	if (!book) {
		fputs("Error : Failed to initialize book\n", stderr);
		return (0);
	}

	do {
		//Scan book name
		value = fscanf(file, "%s\n", line);
		if (value == 0 || value == EOF) {
			deleteBook(book);
			return (1);
		}

		//Copy and store book name in book
		book->name = MY_str_ncopy(line, 0, MY_str_len(line));
		if (!book->name) {
			fputs("Error : Failed to copy line\n", stderr);
			return (0);
		}

		//Set other data
		if (!setBookData(book)) {
			fputs("Error : Failed to set book data\n", stderr);
			return (0);
		}

		//Add to book bag
		if (!addCopyToBookBag(books, book)) {
			fputs("Error : Failed to add book to book bag\n", stderr);
			return (0);
		}
		free(book->name);
		book->name = NULL;
	} while (value != 0 && value != EOF);

	deleteBook(book);
	return (1);
}
