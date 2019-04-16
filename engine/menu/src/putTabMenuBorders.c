#include "../includes/putTabMenuBorders.h"

int	putTabMenuBorders(TabMenu *menu) {
	SDL_Color color;
	SDL_Rect pos;

	color.r = MENU_COLORS_BORDERS_R;
	color.g = MENU_COLORS_BORDERS_G;
	color.b = MENU_COLORS_BORDERS_B;
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	if (!menu->menu_surface) {
		menu->menu_surface = SDL_CreateRGBSurface(MENU_FLAGS, menu->menu_pos.w, menu->menu_pos.h, MENU_COLORS_DEPTH, 0, 0, 0, 0);
		if (!menu->menu_surface) {
			fputs("SDL Error : Failed to create menu surface\n", stderr);
			return (0);
		}

		if (SDL_SetColorKey(menu->menu_surface, SDL_SRCCOLORKEY, SDL_MapRGB(menu->menu_surface->format, 0, 0, 0)) == -1)
			fputs("Warning : Failed to set transparancy\n", stderr);
	}

	//Top Border
	pos.x = MENU_BORDERS_RADIUS;
	pos.w = menu->menu_pos.w - 2 * MENU_BORDERS_RADIUS;
	pos.y = 0;
	pos.h = MENU_BORDERS_WIDTH;

	if (SDL_FillRect(menu->menu_surface, &pos,\
				SDL_MapRGB(menu->menu_surface->format,\
					MENU_COLORS_BORDERS_R,\
					MENU_COLORS_BORDERS_G,\
					MENU_COLORS_BORDERS_B\
					)) == -1) {
		fputs("SDL Error : Failed to put top border\n", stderr);
		return (0);
	}

	//Left Border
	pos.x = 0;
	pos.w = MENU_BORDERS_WIDTH;
	pos.y = MENU_BORDERS_RADIUS;
	pos.h = menu->menu_pos.h - 2 * MENU_BORDERS_RADIUS;

	if (SDL_FillRect(menu->menu_surface, &pos,\
				SDL_MapRGB(menu->menu_surface->format,\
					MENU_COLORS_BORDERS_R,\
					MENU_COLORS_BORDERS_G,\
					MENU_COLORS_BORDERS_B\
					)) == -1) {
		fputs("SDL Error : Failed to put top border\n", stderr);
		return (0);
	}

	//Bottom Border
	pos.x = MENU_BORDERS_RADIUS;
	pos.w = menu->menu_pos.w - 2 * MENU_BORDERS_RADIUS;
	pos.y = menu->menu_pos.h - MENU_BORDERS_WIDTH;
	pos.h = MENU_BORDERS_WIDTH;

	if (SDL_FillRect(menu->menu_surface, &pos,\
				SDL_MapRGB(menu->menu_surface->format,\
					MENU_COLORS_BORDERS_R,\
					MENU_COLORS_BORDERS_G,\
					MENU_COLORS_BORDERS_B\
					)) == -1) {
		fputs("SDL Error : Failed to put top border\n", stderr);
		return (0);
	}

	//Right Border
	pos.x = menu->menu_pos.w - MENU_BORDERS_WIDTH;
	pos.w = MENU_BORDERS_WIDTH;
	pos.y = MENU_BORDERS_RADIUS;
	pos.h = menu->menu_pos.h - 2 * MENU_BORDERS_RADIUS;

	if (SDL_FillRect(menu->menu_surface, &pos,\
				SDL_MapRGB(menu->menu_surface->format,\
					MENU_COLORS_BORDERS_R,\
					MENU_COLORS_BORDERS_G,\
					MENU_COLORS_BORDERS_B\
					)) == -1) {
		fputs("SDL Error : Failed to put top border\n", stderr);
		return (0);
	}

	//Top Left Corner
	pos.x = MENU_BORDERS_RADIUS;
	pos.y = MENU_BORDERS_RADIUS;
	if (!drawThickCircle(menu->menu_surface,\
				&pos,\
				MENU_BORDERS_RADIUS,\
				MENU_BORDERS_WIDTH,\
				&color,\
				CIRCLE_TOP_LEFT_CORNER)) {
		fputs("Error : Failed to draw top-left corner\n", stderr);
		return (0);
	}

	//Bottom Left Corner
	pos.x = MENU_BORDERS_RADIUS;
	pos.y = menu->menu_pos.h - MENU_BORDERS_RADIUS - 1;
	if (!drawThickCircle(menu->menu_surface,\
				&pos,\
				MENU_BORDERS_RADIUS,\
				MENU_BORDERS_WIDTH,\
				&color,\
				CIRCLE_BOTTOM_LEFT_CORNER)) {
		fputs("Error : Failed to draw bottom-left corner\n", stderr);
		return (0);
	}

	//Bottom Right Corner
	pos.x = menu->menu_pos.w - MENU_BORDERS_RADIUS - 1;
	pos.y = menu->menu_pos.h - MENU_BORDERS_RADIUS - 1;
	if (!drawThickCircle(menu->menu_surface,\
				&pos,\
				MENU_BORDERS_RADIUS,\
				MENU_BORDERS_WIDTH,\
				&color,\
				CIRCLE_BOTTOM_RIGHT_CORNER)) {
		fputs("Error : Failed to draw bottom-left corner\n", stderr);
		return (0);
	}

	//Top Right Corner
	pos.x = menu->menu_pos.w - MENU_BORDERS_RADIUS - 1;
	pos.y = MENU_BORDERS_RADIUS;
	if (!drawThickCircle(menu->menu_surface,\
				&pos,\
				MENU_BORDERS_RADIUS,\
				MENU_BORDERS_WIDTH,\
				&color,\
				CIRCLE_TOP_RIGHT_CORNER)) {
		fputs("Error : Failed to draw bottom-left corner\n", stderr);
		return (0);
	}


	//Header / TabsPreview separation
	pos.x = 0;
	pos.w = menu->menu_pos.w;
	pos.y = menu->tabs_preview_pos.y - MENU_CONTAINER_SEPARATION_WIDTH / 2 - 1;
	pos.h = MENU_CONTAINER_SEPARATION_WIDTH;

	if (SDL_FillRect(menu->menu_surface, &pos,\
				SDL_MapRGB(menu->menu_surface->format,\
					MENU_COLORS_BORDERS_R,\
					MENU_COLORS_BORDERS_G,\
					MENU_COLORS_BORDERS_B\
					)) == -1) {
		fputs("SDL Error : Failed to put top border\n", stderr);
		return (0);
	}

	//TabsPreview / TabContent separation
	pos.x = 0;
	pos.w = menu->menu_pos.w;
	pos.y = menu->tab_content_pos.y - MENU_CONTAINER_SEPARATION_WIDTH / 2;
	pos.h = MENU_CONTAINER_SEPARATION_WIDTH;

	if (SDL_FillRect(menu->menu_surface, &pos,\
				SDL_MapRGB(menu->menu_surface->format,\
					MENU_COLORS_BORDERS_R,\
					MENU_COLORS_BORDERS_G,\
					MENU_COLORS_BORDERS_B\
					)) == -1) {
		fputs("SDL Error : Failed to put top border\n", stderr);
		return (0);
	}

	return (1);
}
