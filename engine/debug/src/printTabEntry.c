#include "printTabEntry.h"

void	printTabEntry(TabEntry *entry, int flags) {
	if (!entry) {
		puts("\n--- NO Entry ---\n");
		return;
	}

	puts("\n--- Entry ---");
	puts(entry->misc_content);

	if (flags & 1) {
		printf("x: %d\ty: %d\n", entry->pos->x, entry->pos->y);
		printf("w: %d\th: %d\n", entry->pos->w, entry->pos->h);
	}
}
