#include "../includes/useMapByte.h"

void	useMapByte(SDL_Surface *dest, const char *byte, SDL_Rect *pos){
	char clen[3];
	char cheight[3];
	char ctexture[2];
	SDL_Surface *texture;

	texture = NULL;

	clen[0] = byte[0];
	clen[1] = byte[1];
	clen[2] = byte[2];
	clen[3] = '\0';

	cheight[0] = byte[3];
	cheight[1] = byte[4];
	cheight[2] = byte[5];
	cheight[3] = '\0';

	ctexture[0] = byte[6];
	ctexture[1] = byte[7];
	ctexture[2] = '\0';

	texture = loadMapTexture(MY_hex2dec(ctexture));
	if (!texture) {
		fputs("Warning : Loading texture failed\n", stderr);
	}

	pos->w = MY_hex2dec(clen);
	pos->h = MY_hex2dec(cheight);

	fillRect(dest, texture, pos);

	//Move Yposition for the next line
	pos->y += MY_hex2dec(cheight);
	SDL_FreeSurface(texture);
}
