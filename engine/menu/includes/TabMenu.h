#ifndef DEF_TAB_MENU
#define DEF_TAB_MENU

#include <SDL/SDL.h>
#include "../../includes/FnctPtr.h"

typedef struct TabMenu {
	SDL_Rect menu_pos;
	SDL_Surface *menu_surface;

	SDL_Rect header_pos;
	SDL_Surface *header;

	SDL_Rect tabs_preview_pos;
	SDL_Surface *tabs_preview;

	struct TabList *tabs;
	unsigned int active_tab;

	SDL_Rect tab_content_pos;
	SDL_Surface *tab_content;

	SDL_Surface *event_surface;
	SDL_Rect event_pos;
} TabMenu;

typedef struct TabList {
	unsigned int nb_tabs;
	struct Tab *first;
} TabList;

typedef struct Tab {
	unsigned int nb_entries;
	unsigned int id;
	SDL_Surface *scrollbar;
	struct TabEntry *first;
	unsigned int current_pos;
	struct Tab *next;
	struct Tab *previous;
} Tab;

typedef struct TabEntry {
	//Relative pos to tab_content
	SDL_Rect *pos;
	unsigned int display_pos;
	SDL_Surface *surface;
	char *misc_content;
	FnctPtr hoverAction;
	FnctPtr triggerAction;
	struct TabEntry *next;
	struct TabEntry *previous;
} TabEntry;

#endif
