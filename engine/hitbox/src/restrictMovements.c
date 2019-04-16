#include "../includes/restrictMovements.h"

int	restrictMovements(Hitbox *origin, Hitbox *env, int margin)
{
	unsigned int i;
	unsigned int j;
	int dir;
	ElemHitbox *elem_origin;
	ElemHitbox *elem_env;
	SDL_Rect marged;

	i = 0;
	j = 0;
	dir = 0;
	elem_origin = NULL;
	elem_env = NULL;

	if (!origin || !env)
		return (UP | DOWN | LEFT | RIGHT);

	elem_origin = origin->first;
	elem_env = env->first;
	while (elem_origin != NULL) {
		marged.x = elem_origin->pos.x - margin;
		marged.y = elem_origin->pos.y - margin;
		marged.h = elem_origin->pos.h + 2 * margin;
		marged.w = elem_origin->pos.w + 2 * margin;
		while (elem_env != NULL) {
			if (checkRectIntersection(&marged, &(elem_env->pos)) != 0)
				dir |= getCollisionOrigin(&(marged), &(elem_env->pos), margin);
			elem_env = elem_env->next;
			j++;
		}
		elem_origin = elem_origin->next;
		i++;
	}
	
	return (~dir);
}
