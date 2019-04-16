#include "../includes/loadMapLine.h"

void	loadMapLine(SDL_Surface *dest, const char *line, SDL_Rect *pos)
{
	int i;
	int j;
	char current_bit[MAP_SIZE_BIT];
	char cW[3];

	//Gets the width of the column
	cW[0] = line[0];
	cW[1] = line[1];
	cW[2] = line[2];
	cW[3] = '\0';
	//Go to the top of the column
	pos->y = 0;
	j = 0;
	i = 0;
	while (line[i] != '\0'){
		if (line[i] == ' ' || line[i] == '\n'){
			useMapByte(dest, current_bit, pos);
			j = 0;
		} else {
			current_bit[j] = line[i];
			j++;
		}
		i++;
	}
	//Move Xposition for the next column
	pos->x += MY_hex2dec(cW);
}
