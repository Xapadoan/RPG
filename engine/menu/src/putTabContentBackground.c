#include "../includes/putTabContentBackground.h"

int	putTabContentBackground(TabMenu *menu)
{
	SDL_Color color;
	SDL_Rect rect;

	rect.x = MENU_BORDERS_WIDTH;
	rect.w = menu->tab_content_pos.w - 2 * MENU_BORDERS_WIDTH;
	rect.y = MENU_CONTAINER_SEPARATION_WIDTH / 2 + 1;
	rect.h = menu->tab_content_pos.h - (MENU_CONTAINER_SEPARATION_WIDTH / 2 + MENU_BORDERS_RADIUS);
	color.r = MENU_COLORS_BACKGROUND_R;
	color.g = MENU_COLORS_BACKGROUND_G;
	color.b = MENU_COLORS_BACKGROUND_B;
	if (!menu) {
		fputs("Error : Failed to update tab content\n", stderr);
		return (0);
	}

	if (!menu->tab_content) {
		menu->tab_content = SDL_CreateRGBSurface(MENU_FLAGS, menu->tab_content_pos.w, menu->tab_content_pos.h, MENU_COLORS_DEPTH, 0, 0, 0, 0);
		if (!menu->tab_content) {
			fputs("SDL Error : Failed to create RGB surface for tab content\n", stderr);
			return (0);
		}
	}

	SDL_BlitSurface(menu->menu_surface, &(menu->tab_content_pos), menu->tab_content, NULL);

	if (SDL_FillRect(menu->tab_content, &rect, SDL_MapRGB(menu->tab_content->format,\
					MENU_COLORS_BACKGROUND_R,\
					MENU_COLORS_BACKGROUND_G,\
					MENU_COLORS_BACKGROUND_B))) {
		fputs("SDL Error : Failed to fill tab content with background color\n", stderr);
		return (0);
	}

	rect.x = MENU_BORDERS_RADIUS;
	rect.w = menu->tab_content_pos.w - 2 * MENU_BORDERS_RADIUS;
	rect.y += rect.h - 1;
	rect.h = MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH;
	if (SDL_FillRect(menu->tab_content, &rect, SDL_MapRGB(menu->tab_content->format,\
					MENU_COLORS_BACKGROUND_R,\
					MENU_COLORS_BACKGROUND_G,\
					MENU_COLORS_BACKGROUND_B))) {
		fputs("SDL Error : Failed to fill tab content with background color\n", stderr);
		return (0);
	}

	if (!drawThickCircle(menu->tab_content,\
				&rect,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH - 1,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH - 1,\
				&color,\
				CIRCLE_BOTTOM_LEFT_CORNER)) {
		fputs("Error : Failed to put bottom left corner\n", stderr);
		return (0);
	}

	rect.x += rect.w;
	if (!drawThickCircle(menu->tab_content,\
				&rect,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH - 1,\
				MENU_BORDERS_RADIUS - MENU_BORDERS_WIDTH - 1,\
				&color,\
				CIRCLE_BOTTOM_RIGHT_CORNER)) {
		fputs("Error : Failed to put bottom left corner\n", stderr);
		return (0);
	}

	return (1);
}
