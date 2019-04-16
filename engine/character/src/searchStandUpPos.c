#include "../includes/searchStandUpPos.h"

int searchStandUpPos(Team *team, Map *map, int dir)
{
	int found;
	SDL_Rect virt_pos1;
	SDL_Rect virt_pos2;
	SDL_Rect origin;
	SDL_Rect team_dim;
	SDL_Rect item_dim;

	found = 0;
	origin.x = team->location.x;
	origin.y = team->location.y;
	origin.w = 0;
	origin.h = 0;
	virt_pos1.x = origin.x;
	virt_pos1.y = origin.y;
	virt_pos1.w = 0;
	virt_pos1.h = 0;
	virt_pos2.x = origin.x;
	virt_pos2.y = origin.y;
	virt_pos2.w = 0;
	virt_pos2.h = 0;
	team_dim = getHitboxDimensions(team->hitbox);
	item_dim = getHitboxDimensions(team->heroes[0].interacting_item->hitbox);

	if (dir & UP) {
		virt_pos1.y = item_dim.y - team_dim.h - CHARACTER_HITBOX_Y - 1;
		virt_pos2.y = virt_pos1.y;
		team->location.y = virt_pos1.y;
		//Same y , x going in opposite directions
		while (!found && virt_pos1.x > item_dim.x - team_dim.w - CHARACTER_HITBOX_X - 1 && virt_pos2.x < item_dim.x + item_dim.w - CHARACTER_HITBOX_X + 1) {
			team->location.x = virt_pos1.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.x--;
			displayHitbox(map->background, team->hitbox);

			team->location.x = virt_pos2.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.x++;
			virt_pos2.x++;
			displayHitbox(map->background, team->hitbox);
		}

		//Same y going down, different x static
		while (!found && virt_pos1.y < item_dim.y + item_dim.h - CHARACTER_HITBOX_Y + 1) {
			team->location.y = virt_pos1.y;
			team->location.x = virt_pos1.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			team->location.x = virt_pos2.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			virt_pos1.y++;
		}

		//Same y static, x joinning
		while (!found && virt_pos1.x < origin.x && virt_pos2.x > origin.x) {
			team->location.x = virt_pos1.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.x++;

			team->location.x = virt_pos2.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.x--;
		}
	} else if (dir & DOWN) {
		virt_pos1.y = item_dim.y + item_dim.h - CHARACTER_HITBOX_Y + 1;
		virt_pos2.y = virt_pos1.y;
		team->location.y = virt_pos1.y;
		updateTeam(team);

		//Same y , x going in opposite directions
		while (!found && virt_pos1.x > item_dim.x - team_dim.w - CHARACTER_HITBOX_X - 1 && virt_pos2.x < item_dim.x + item_dim.w - CHARACTER_HITBOX_X + 1) {
			team->location.x = virt_pos1.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.x--;

			team->location.x = virt_pos2.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.x++;
		}

		//Same y going up, different x static
		while (!found && virt_pos1.y > item_dim.y - team_dim.h - CHARACTER_HITBOX_Y - 1) {
			team->location.y = virt_pos1.y;
			team->location.x = virt_pos1.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			team->location.x = virt_pos2.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			virt_pos1.y--;
		}

		//Same y static, x joinning
		while (!found && virt_pos1.x < origin.x && virt_pos2.x > origin.x) {
			team->location.x = virt_pos1.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.x++;

			team->location.x = virt_pos2.x;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.x--;
		}
	} else if (dir & LEFT) {
		virt_pos1.x = item_dim.x - team_dim.w - CHARACTER_HITBOX_X - 1;
		virt_pos2.x = virt_pos1.x;
		team->location.x = virt_pos1.x;

		//Same x static, y going in opposite directions
		while (!found && virt_pos1.y > item_dim.y - team_dim.h - CHARACTER_HITBOX_Y - 1 && virt_pos2.y < item_dim.y + item_dim.h - CHARACTER_HITBOX_Y + 1) {
			team->location.y = virt_pos1.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.y--;

			team->location.y = virt_pos2.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.y++;

		}
		//Same x going right, different y static
		while (!found && virt_pos1.x < item_dim.x + item_dim.w - CHARACTER_HITBOX_X + 1) {
			team->location.x = virt_pos1.x;
			team->location.y = virt_pos1.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			team->location.y = virt_pos2.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			virt_pos1.x++;
		}
		//Same x static, y joinning
		while (!found && virt_pos1.y < origin.y && virt_pos2.y > origin.y) {
			team->location.y = virt_pos1.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.y++;

			team->location.y = virt_pos2.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.y--;
		}
	} else if (dir & RIGHT) {
		virt_pos1.x = item_dim.x + item_dim.w - CHARACTER_HITBOX_X + 1;
		virt_pos2.x = virt_pos1.x;
		team->location.x = virt_pos1.x;
		//Same x static, y going in opposite directions
		while (!found && virt_pos1.y > item_dim.y - team_dim.h - CHARACTER_HITBOX_Y - 1 && virt_pos2.y < item_dim.y + item_dim.h - CHARACTER_HITBOX_Y + 1) {
			team->location.y = virt_pos1.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.y--;

			team->location.y = virt_pos2.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.y++;

		}
		//Same x going left, different y static
		while (!found && virt_pos1.x > item_dim.x - team_dim.w - CHARACTER_HITBOX_W - 1) {
			team->location.x = virt_pos1.x;
			team->location.y = virt_pos1.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			team->location.y = virt_pos2.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;

			virt_pos1.x++;
		}
		//Same x static, y joinning
		while (!found && virt_pos1.y < origin.y && virt_pos2.y > origin.y) {
			team->location.y = virt_pos1.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos1.y++;

			team->location.y = virt_pos2.y;
			updateTeam(team);
			if (!~checkAllowedMoves(map, team, 0))
				found = 1;
			else
				virt_pos2.y--;
		}
	} else {
		fputs("Error : Unknown direction\n", stderr);
		return (0);
	}

	if (!found) {
		fputs("Notice : Can't find stand up position\n", stderr);
		team->location.x = origin.x;
		team->location.y = origin.y;
		updateTeam(team);
		return (0);
	}

	return (1);
}
