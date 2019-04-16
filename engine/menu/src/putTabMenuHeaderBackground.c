#include "../includes/putTabMenuHeaderBackground.h"

int	putTabMenuHeaderBackground(TabMenu *menu)
{
	SDL_Rect rect;
	SDL_Color color;

	color.r = MENU_COLORS_BACKGROUND_R;
	color.g = MENU_COLORS_BACKGROUND_G;
	color.b = MENU_COLORS_BACKGROUND_B;
	rect.x = menu->header_pos.x + MENU_BORDERS_RADIUS;
	rect.y = menu->header_pos.y + MENU_BORDERS_WIDTH;
	rect.w = menu->header_pos.w - 2 * MENU_BORDERS_RADIUS;
	rect.h = menu->header_pos.h - MENU_BORDERS_WIDTH - MENU_CONTAINER_SEPARATION_WIDTH / 2;
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	if (!menu->header) {
		menu->header = SDL_CreateRGBSurface(MENU_FLAGS, menu->header_pos.w, menu->header_pos.h, MENU_COLORS_DEPTH, 0, 0, 0, 0);
		if (!menu->header) {
			fputs("SDL Error : Failed to create RGB surface for header\n", stderr);
			return (0);
		}
	}

	SDL_BlitSurface(menu->menu_surface, &(menu->header_pos), menu->header, NULL);
	SDL_FillRect(menu->header, &rect, SDL_MapRGB(menu->header->format, MENU_COLORS_BACKGROUND_R, MENU_COLORS_BACKGROUND_G, MENU_COLORS_BACKGROUND_B));

	rect.x = menu->header_pos.x + MENU_BORDERS_WIDTH;
	rect.y = menu->header_pos.y + MENU_BORDERS_RADIUS;
	rect.w = menu->header_pos.w - 2 * MENU_BORDERS_WIDTH;
	rect.h = menu->header_pos.h - MENU_BORDERS_RADIUS - MENU_CONTAINER_SEPARATION_WIDTH / 2;
	SDL_FillRect(menu->header, &rect, SDL_MapRGB(menu->header->format, MENU_COLORS_BACKGROUND_R, MENU_COLORS_BACKGROUND_G, MENU_COLORS_BACKGROUND_B));

	rect.x = menu->header_pos.x + MENU_BORDERS_RADIUS;
	rect.y = menu->header_pos.y + MENU_BORDERS_RADIUS;
	if (!drawThickCircle(menu->header,\
				&rect,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH,\
				&color,\
				CIRCLE_TOP_LEFT_CORNER)) {
		fputs("Error : Failed to fill top left corner\n", stderr);
		return (0);
	}

	rect.x = menu->header_pos.x + menu->header_pos.w - MENU_BORDERS_RADIUS - 1;
	rect.y = menu->header_pos.y + MENU_BORDERS_RADIUS;
	if (!drawThickCircle(menu->header,\
				&rect,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH,\
				&color,\
				CIRCLE_TOP_RIGHT_CORNER)) {
		fputs("Error : Failed to fill top left corner\n", stderr);
		return (0);
	}

	return (1);
}
