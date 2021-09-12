#include "printPotion.h"

void printPotion(Potion *potion)
{
	if (!potion) {
		puts("\n--- NO Potion ---\n");
		return;
	}
	printf("\n--- %s ---\n", potion->name);
	printf("id: %d\tweight: %d\n", potion->id, potion->weight);
	printf("value: %d\tnb: %d\n", potion->value, potion->nb);
	printf("magnitude: %d\tduration: %d\n", potion->magnitude, potion->duration);
}
