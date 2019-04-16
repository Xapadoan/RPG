#include "../includes/setPotionData.h"

int	setPotionData(Potion *potion)
{
	char **splitted_name;
	int nb_words;

	nb_words = 0;
	splitted_name = MY_str_split(potion->name, "_");
	if (!splitted_name) {
		fputs("Error : Failed to split potion name\n", stderr);
		return (0);
	}

	while (splitted_name[nb_words++] != '\0');

	switch (nb_words) {
		case (3) :
			//Format : Magnitude Attribute Potion/Poison

			//Set Magnitude
			if (MY_str_compare(splitted_name[0], "little")) {
				potion->magnitude = 20;
				potion->value = 30;
			} else if (MY_str_compare(splitted_name[0], "medium")) {
				potion->magnitude = 50;
				potion->value = 80;
			} else if (MY_str_compare(splitted_name[0], "large")) {
				potion->magnitude = 100;
				potion->value = 200;
			} else if (MY_str_compare(splitted_name[0], "ultimate")) {
				potion->magnitude = 200;
				potion->value = 500;
			} else {
				fputs("Error : Unknown magnitude descriptor\n", stderr);
				MY_free_2d_char(splitted_name);
				return (0);
			}
			break;
		case (4) :
			//Format : Magnitude Durable Attribute Potion/Poison

			//Set Magnitude
			if (MY_str_compare(splitted_name[0], "little")) {
				potion->magnitude = 30;
			} else if (MY_str_compare(splitted_name[0], "medium")) {
				potion->magnitude = 70;
			} else if (MY_str_compare(splitted_name[0], "large")) {
				potion->magnitude = 150;
			} else if (MY_str_compare(splitted_name[0], "ultimate")) {
				potion->magnitude = 300;
			} else {
				fputs("Error : Unknown magnitude descriptor\n", stderr);
				MY_free_2d_char(splitted_name);
				return (0);
			}
			break;

			//Set potion Duration
			if (MY_str_compare(splitted_name[1], "fast")) {
				potion->duration = 5;
			} else if (MY_str_compare(splitted_name[1], "slow")) {
				potion->duration = 10;
			} else {
				fputs("Error : Unknown duration descriptor\n", stderr);
				MY_free_2d_char(splitted_name);
				return (0);
			}
			break;
		default :
			fputs("Error : Potion name has impossible number of words\n", stderr);
			MY_free_2d_char(splitted_name);
			return (0);
			break;
	}

	if (!linkPotionAction(potion))
		fputs("Warning : Failed to link to potion action\n", stderr);

	MY_free_2d_char(splitted_name);
	return (1);
}
