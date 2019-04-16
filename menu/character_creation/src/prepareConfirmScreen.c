#include "../includes/prepareConfirmScreen.h"

SDL_Surface	*prepareConfirmScreen(Character *to_confirm)
{
	TTF_Font *font;
	SDL_Surface *dest;
	SDL_Rect posText;
	SDL_Color white;

	posText.x = CHARACTER_MENU_DIMENSION_MARGIN;
	posText.y = CHARACTER_MENU_DIMENSION_MARGIN;
	white.r = 255;
	white.g = 255;
	white.b = 255;
	dest = NULL;
	font = NULL;

	dest = IMG_Load(CHARACTER_MENU_BOX_CONFIRM);
	if (!dest)
	{
		fputs("IMG Error : Can't load confirm_character.png\n", stderr);
		return (NULL);
	}

	font = TTF_OpenFont(FONT_CHARACTER_CREATION_TYPE, FONT_CHARACTER_CREATION_SIZE);
	if (!font)
	{
		fputs("TTF Error : Can't open character creation font (for confirmation message)\n", stderr);
		return (NULL);
	}

	if (!putFont(font, "Do you want to create", white, dest, &posText))
	{
		fputs("Error : Can't ask confirmation question\n", stderr);
		TTF_CloseFont(font);
		return (NULL);
	}
	
	if (!putCharacterInfo(dest, to_confirm, font, white, &posText))
	{
		fputs("Error : Can't put character info\n", stderr);
		TTF_CloseFont(font);
		return (NULL);
	}

	if (!putYesNo(dest, font, white))
	{
		fputs("Error : Can't put choices of confirmation question\n", stderr);
		TTF_CloseFont(font);
		return (NULL);
	}

	TTF_CloseFont(font);
	return (dest);
}
