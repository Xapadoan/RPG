#include "../includes/searchItemInList.h"

int	searchItemInList(FILE *file, MapItem *item)
{
	int x;
	int y;
	int nb_sprite;
	char line[200];


	x = 0;
	y = 0;
	nb_sprite = 0;
	if (!file || !item) {
		fputs("Error : missing arguments for searchinf item\n", stderr);
		return (0);
	}

	rewind(file);

	while (fscanf(file, "%*x\t%s\t%x\t%*x\t%x\t%*x\t%*s\t%d", line, &x, &y, &nb_sprite) != EOF
			&& !(item->pos.x == x && item->pos.y == y)) {
		while (nb_sprite-- > 0)
			MY_go_to_next_line(file);
	}

	return (fgetc(file) != EOF);
}
