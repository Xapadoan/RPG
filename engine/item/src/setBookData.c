#include "../includes/setBookData.h"

static int linkBookAction(Book *book);

int	setBookData(Book *book)
{
	char *img_path;

	img_path = (char *)malloc((MY_str_len(ITEM_BOOK_PATH) + MY_str_len("leather_book.png") + 1) * sizeof(char));
	if (!img_path) {
		fputs("Memory Error : Failed to allocate memory for book preview path\n", stderr);
		return (0);
	}
	MY_str_append(img_path, ITEM_BOOK_PATH);
	MY_str_append(img_path, "leather_book.png");
	book->preview = IMG_Load(img_path);
	if (!book->preview) {
		fprintf(stderr, "IMG Error : Failed to load :\n\t%s\n", img_path);
		return (0);
	}

	book->weight = ITEM_BOOK_DEFAULT_WEIGHT;
	book->value = ITEM_BOOK_DEFAULT_VALUE;

	if (!linkBookAction(book))
		fputs("Warning : Failed to link to potion action\n", stderr);

	return (1);
}

int	linkBookAction(Book *book)
{
	char *path;

	path = (char *)malloc((MY_str_len(ITEM_BOOK_PATH) + MY_str_len(book->name) + 5) * sizeof(char));
	if (!path) {
		fputs("Memory Error : Failed to allocate memory for book content path\n", stderr);
		return (0);
	}
	MY_str_append(path, ITEM_BOOK_PATH);
	MY_str_append(path, book->name);
	MY_str_append(path, ".txt");

	book->read = NULL;
	free(path);
	return (1);
}
