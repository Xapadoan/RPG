#ifndef DEF_MERGE_HITBOXES
#define DEF_MERGE_HITBOXES

#include "Hitbox.h"
#include "copyToHitbox.h"

Hitbox	*mergeHitboxes(Hitbox *htb1, Hitbox *htb2);

/*
 * DESCRIPTION :
 * 	This function merges two hitbox into one ('htb1')
 *
 * RETURN VALUE :
 * 	This function return a pointer to the merged hitbox ('htb1') or NULL if
 * 		an error occured.
 */

#endif
