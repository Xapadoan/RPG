#ifndef DEF_GET_DISPLAY_TAB_ENTRY
#define DEF_GET_DISPLAY_TAB_ENTRY

#include <stdio.h>
#include <stdlib.h>

#include "TabMenu.h"

TabEntry	*getDisplayTabEntry(Tab *tab, unsigned int display_id);

/*
 * DESCRIPTION :
 * 		Gets the entry the Tab having the corresponding display_id
 * 		A pointer is initialized to the first element of the tab.
 * 		This pointer is incremanted until the right eentry is found
 * 		or the end of tab is reach (the pointer points to NULL).
 *
 * RETURN VALUE :
 * 		- A pointer to the entry
 * 		- NULL if the provided tab is NULL or empty
 */

#endif
