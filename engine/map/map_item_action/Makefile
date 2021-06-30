CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../menu/includes\
				 -iquote ../../character/includes\
				 -iquote ../../../includes/config\
				 -iquote ../includes\
				 -iquote ../../../lib/libMY/libMY_string/includes\
				 -iquote ../../../lib/libMY/libMY_file/includes\
				 -iquote ../../display/includes\
				 -iquote ../../location/includes\
				 -iquote ../../hitbox/includes\
				 -iquote ../../item/includes\
				 -iquote ../../font/includes\
				 -iquote ../../move/includes\
				 -iquote ../../../lib/libMY/libMY_int/includes\

OBJ=openItemContainer.o\
	sitOnChair.o\
	sleep.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

openItemContainer.o: src/openItemContainer.c\
	includes/openItemContainer.h\
	../../character/includes/Team.h\
	../includes/Map.h\
	../../menu/includes/prepareExchangeScreen.h\
	../../menu/includes/TabMenu.h\
	../../menu/includes/initTabMenu.h\
	../../menu/includes/deleteTabMenu.h\
	../../menu/includes/setTabMenuHeight.h\
	../../menu/includes/setTabMenuWidth.h\
	../../menu/includes/setTabMenuHeaderHeight.h\
	../../menu/includes/setTabsPreviewHeight.h\
	../../menu/includes/updateItemExchangeMenu.h\
	../../menu/includes/createItemExchangeTabs.h\
	../../menu/includes/loadItemExchangeMenuContent.h\
	../../menu/includes/handleTabMenuEvent.h
	$(CC) $(CC_FLAGS) $< -o $@
sitOnChair.o: src/sitOnChair.c\
	includes/sitOnChair.h\
	../../../includes/config/controls.h\
	../../../includes/config/character_sprite.h\
	../../../includes/config/map_item_sprite_mark.h\
	../../../includes/config/map_item.h\
	../../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h\
	../../display/includes/displayMap.h\
	../../character/includes/Team.h\
	../../character/includes/changeTeamState.h\
	../includes/Map.h\
	../includes/openMapItemList.h\
	../includes/searchItemInList.h\
	../../location/includes/Direction.h
	$(CC) $(CC_FLAGS) $< -o $@
sleep.o: src/sleep.c\
	includes/sleep.h\
	../../../includes/config/map_item.h\
	../../../includes/config/character_sprite.h\
	../../../includes/config/screen.h\
	../../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../../lib/libMY/libMY_string/includes/MY_str_append.h\
	../../../lib/libMY/libMY_string/includes/MY_str_compare.h\
	../../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h\
	../../character/includes/Team.h\
	../../character/includes/updateTeam.h\
	../../character/includes/maxCureTeam.h\
	../../character/includes/putClosedEyes.h\
	../../location/includes/Direction.h\
	../../display/includes/displayMapItems.h\
	../includes/Map.h\
	../includes/openMapItemList.h
	$(CC) $(CC_FLAGS) $< -o $@

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)
