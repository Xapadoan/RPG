#include "../includes/go.h"

void	go(Map *map, Team *team, int dir)
{
	int allowed;

	allowed = 0;
	if (team->location.x >= team->heroes[0].mov_speed)
		allowed |= LEFT;
	if (team->location.x <= map->background->w - team->heroes[0].mov_speed)
		allowed |= RIGHT;
	if (team->location.y >= team->heroes[0].mov_speed)
		allowed |= UP;
	if (team->location.y <= map->background->h - team->heroes[0].mov_speed)
		allowed |= DOWN;

	allowed &= checkAllowedMoves(map, team, team->heroes[0].mov_speed);

	if ((dir & UP) && (UP & allowed)) {
		if (!(dir ^ UP))
			team->location.y -= team->heroes[0].mov_speed;
		else
			team->location.y -= team->heroes[0].mov_speed / 2;
	}

	if ((dir & DOWN) && (DOWN & allowed)) {
		if (!(dir ^ DOWN))
			team->location.y += team->heroes[0].mov_speed;
		else
			team->location.y += team->heroes[0].mov_speed / 2;
	}

	if ((dir & LEFT) && (LEFT & allowed)) {
		if (!(dir ^ LEFT))
			team->location.x -= team->heroes[0].mov_speed;
		else team->location.x -= team->heroes[0].mov_speed / 2;
	}

	if ((dir & RIGHT) && (RIGHT & allowed)) {
		if (!(dir ^ RIGHT))
			team->location.x += team->heroes[0].mov_speed;
		else
			team->location.x += team->heroes[0].mov_speed / 2;
	}

	if (team->heroes[0].state != CHARACTER_STATE_SITTED)
		updateTeam(team);
}
