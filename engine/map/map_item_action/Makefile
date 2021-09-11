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
				 -iquote ../../../lib/libMY\
				 -iquote ../../display/includes\
				 -iquote ../../location/includes\
				 -iquote ../../hitbox/includes\
				 -iquote ../../item/includes\
				 -iquote ../../font/includes\
				 -iquote ../../move/includes\
				 -iquote ../../includes

OBJ=openItemContainer.o\
	sitOnChair.o\
	sleepInBed.o

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
	../../menu/includes/handleItemExchangeMenuEvent.h
	$(CC) $(CC_FLAGS) $< -o $@
sitOnChair.o: src/sitOnChair.c\
	includes/sitOnChair.h\
	../../../includes/config/controls.h\
	../../../includes/config/character_sprite.h\
	../../../includes/config/map_item_sprite_mark.h\
	../../../includes/config/map_item.h\
	../../../lib/libMY/MY_file.h\
	../../display/includes/displayMap.h\
	../../character/includes/Team.h\
	../../character/includes/changeTeamState.h\
	../includes/Map.h\
	../includes/openMapItemList.h\
	../includes/searchItemInList.h\
	../../location/includes/Direction.h
	$(CC) $(CC_FLAGS) $< -o $@
sleepInBed.o: src/sleepInBed.c\
	includes/sleepInBed.h\
	../../../includes/config/map_item.h\
	../../../includes/config/character_sprite.h\
	../../../includes/config/screen.h\
	../../../lib/libMY/MY_string.h\
	../../../lib/libMY/MY_file.h\
	../../character/includes/Team.h\
	../../character/includes/updateTeam.h\
	../../character/includes/maxCureTeam.h\
	../../character/includes/putClosedEyes.h\
	../../location/includes/Direction.h\
	../../display/includes/displayMapItems.h\
	../includes/Map.h\
	../includes/searchItemInList.h\
	../includes/openMapItemList.h
	$(CC) $(CC_FLAGS) $< -o $@

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)
