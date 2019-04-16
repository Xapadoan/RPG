#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <SDL/SDL.h>

#define CHARACTER_STATE_WALKING	0x00
#define CHARACTER_STATE_SITTED 0x01
#define CHARACTER_STATE_RUNNING 0x02
#define CHARACTER_STATE_STANDING 0x03
#define CHARACTER_STATE_FIGHTING 0x04

#define CHARACTER_CMBT_STATE_NORMAL 0b0000
#define CHARACTER_CMBT_STATE_DEAD 0b0001
#define CHARACTER_CMBT_STATE_DYING 0b0010
#define CHARACTER_CMBT_STATE_EXHAUSTED 0b0100

typedef struct Character
{
	unsigned int level;

	int health;
	int max_health;
	int stamina;
	int max_stamina;
	int mov_speed;
	unsigned int cmbt_state;

	struct PotionBag *active_potions;
	struct ItemBag *bag;

	unsigned int luck;
	unsigned int strn;
	unsigned int agi;
	unsigned int intel;
	unsigned int acc;

	char *name;
	unsigned int gender;
	unsigned int race;

	unsigned int confirmed;
	unsigned int state_changed;
	struct MapItem *interacting_item;

	SDL_Surface *sprite;
	SDL_Surface *sprite2;
	SDL_Surface *sprite3;

	unsigned int state;
	int dir;
} Character;

#endif
