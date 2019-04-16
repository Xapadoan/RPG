#include "../includes/fillRect.h"

void	fillRect(SDL_Surface *dest, SDL_Surface *texture, SDL_Rect *area)
{
	SDL_Rect pos;
	SDL_Rect part;

	part.x = 0;
	part.y = 0;
	part.w = texture->w;
	part.h = texture->h;
	pos.x = area->x;
	pos.y = area->y;
	//Puts the first line
	part.y = area->y % texture->h;
	part.h = texture->h - (area->y % texture->h);
	if (area->y % texture->h){
		//Puts the top left corner
		part.x = area->x % texture->w;
		part.w = texture->w -(area->x % texture->w);

		SDL_BlitSurface(texture, &part, dest, &pos);
		pos.x += part.w;
		part.x = 0;
		part.w = texture->w;
		//Puts the line
		while (pos.x + texture->h <= area->x + area->w){
			SDL_BlitSurface(texture, &part, dest, &pos);
			pos.x += texture->w;
		}
		//Puts the top right corner
		part.w = (area->x + area->w) % texture->w;
		SDL_BlitSurface(texture, &part, dest, &pos);
		pos.y += part.h;
	}
	//Puts the middle line
	part.y = 0;
	part.h = texture->h;
	while (pos.y + texture->h <= area->y + area->h){
		pos.x = area->x;
		//Puts the first rect
		part.x = area->x % texture->w;
		part.w = texture->w - (area->x % texture->w);
		SDL_BlitSurface(texture, &part, dest, &pos);
		pos.x += part.w;

		//Puts the line
		part.x = 0;
		part.w = texture->w;
		while (pos.x + texture->w <= area->x + area->w){
			SDL_BlitSurface(texture, &part, dest, &pos);
			pos.x += texture->w;
		}

		//Puts the last rect
		part.w = (area->x + area->w) % texture->w;
		SDL_BlitSurface(texture, &part, dest, &pos);
		pos.y += texture->h;
	}
	//Puts the last line
	part.y = 0;
	part.h = (area->y + area->h) % texture->h;
	pos.x = area->x;
	//printf("Pos Y:%d\n", pos.y);
	if ((area->y + area->h) % texture->h){
		//Puts the bottom left corner
		part.x = area->x % texture->w;
		part.w = texture->w - (area->x % texture->w);
		SDL_BlitSurface(texture, &part, dest, &pos);
		pos.x += part.w;

		//Puts the line
		part.x = 0;
		part.w = texture->w;
		while (pos.x + texture->w <= area->x + area->w){
			SDL_BlitSurface(texture, &part, dest, &pos);
			pos.x += texture->w;
		}

		//Puts the bottom right corner
		part.w = (area->x + area->w) % texture->w;
		SDL_BlitSurface(texture, &part, dest, &pos);
	}
}
