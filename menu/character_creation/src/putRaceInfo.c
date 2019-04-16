#include "../includes/putRaceInfo.h"

int	putRaceInfo(TTF_Font *font, SDL_Surface *screen, SDL_Rect *pos, unsigned int race)
{
	SDL_Color white;
	FILE *file;
	char *info;
	char *fileName;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	info = NULL;
	file = NULL;
	fileName = NULL;

	info = (char *)malloc(42 * sizeof(char));
	if (!info)
	{
		fputs("Error : Can't allocate memory for race general description\n", stderr);
		return (0);
	}

	switch (race)
	{
		case (HUMAN) :
			fileName = "resource/info/Humans.txt";
			break;
		case (SANAK) :
			fileName = "resource/info/Sanaks.txt";
			break;
		case (CORAN) :
			fileName = "resource/info/Corans.txt";
			break;
		case (FAIRY) :
			fileName = "resource/info/Fairies.txt";
			break;
		case (DWARF) :
			fileName = "resource/info/Dwarves.txt";
			break;
		case (ELF) :
			fileName = "resource/info/Elves.txt";
			break;
		default :
			fputs("Error : Unknown race\n", stderr);
			free(info);
			return (0);
			break;
	}

	file = fopen(fileName, "r");
	if (!file)
	{
		fputs("File Error : Can't open race description file\n", stderr);
		fclose(file);
		free(info);
		return (0);
	}

	while (fgets(info, 41, file))
	{
		cutAtNewLine(info);
		if (!putFont(font, info, white, screen, pos))
		{
			fputs("Error : Can't write race description\n", stderr);
			fclose(file);
			free(info);
			return (0);
		}
		pos->y += 22;
	}
	pos->y = CHARACTER_MENU_DIMENSION_MARGIN + 4;

	fclose(file);
	free(info);
	return (1);
}

int	putRaceSkillsInfo(TTF_Font *font, SDL_Surface *screen, SDL_Rect *pos, unsigned int race)
{
	FILE *file;
	SDL_Color white;
	char *fileName;
	char *info;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	file = NULL;
	info = NULL;
	fileName = NULL;

	info = (char *)malloc(24 * sizeof(char));
	if (!info)
	{
		fputs("Error : Can't allocate memory for race skills description\n", stderr);
		return (0);
	}
	switch (race)
	{
		case (HUMAN) :
			fileName = "resource/info/Humans_skills.txt";
			break;
		case (SANAK) :
			fileName = "resource/info/Sanaks_skills.txt";
			break;
		case (CORAN) :
			fileName = "resource/info/Corans_skills.txt";
			break;
		case (FAIRY) :
			fileName = "resource/info/Fairies_skills.txt";
			break;
		case (DWARF) :
			fileName = "resource/info/Dwarves_skills.txt";
			break;
		case (ELF) :
			fileName = "resource/info/Elves_skills.txt";
			break;
		default :
			fputs("Error : Unknown race\n", stderr);
			free(info);
			return (0);
			break;
	}

	file = fopen(fileName, "r");
	if (!file)
	{
		fputs("Error : Can't open race skills description file\n", stderr);
		free(info);
		return (0);
	}

	while (fgets(info, 23, file))
	{
		cutAtNewLine(info);
		if (!putFont(font, info, white, screen, pos))
		{
			fputs("Error : Can't write race description\n", stderr);
			free(info);
			fclose(file);
			return (0);
		}
		pos->y += 22;
	}
	pos->y = CHARACTER_MENU_DIMENSION_MARGIN + 4;

	free(info);
	fclose(file);
	return (1);
}

void	cutAtNewLine(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\n' && str[i++] != '\0');
	str[i] = '\0';
}
