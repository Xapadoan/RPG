CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../character/includes\
				 -iquote ../map/includes\
				 -iquote ../../includes/config\
				 -iquote ../move/includes\
				 -iquote ../menu/includes\
				 -iquote ../font/includes\
				 -iquote ../item/includes\
				 -iquote ../display/includes\
				 -iquote ../hitbox/includes\
				 -iquote ../includes\
				 -iquote ../location/includes\
				 -iquote ../../lib/libMY\
				 -iquote ../map/map_item_action/includes

OBJ=handleMovement.o\
		playGame.o\
		triggerAction.o\
		triggerKeyDown.o\
		triggerKeyUp.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

handleMovement.o: src/handleMovement.c\
	includes/handleMovement.h\
	../../includes/config/controls.h\
	../character/includes/Team.h\
	../character/includes/changeTeamState.h\
	../map/includes/Map.h\
	../move/includes/go.h
	$(CC) $(CC_FLAGS) $< -o $@

playGame.o: src/playGame.c\
	includes/playGame.h\
	includes/triggerKeyUp.h\
	../character/includes/Team.h\
	../character/includes/deleteTeam.h\
	../character/includes/handleStateChange.h\
	../map/includes/initMap.h\
	../map/includes/loadMap.h\
	../map/includes/Map.h\
	../map/includes/deleteMap.h\
	../display/includes/displayMap.h\
	../move/includes/handlePressedKeys.h
	$(CC) $(CC_FLAGS) $< -o $@
triggerAction.o: src/triggerAction.c\
	includes/triggerAction.h\
	../map/includes/Map.h\
	../character/includes/Team.h\
	../character/includes/isFacingMapItem.h
	$(CC) $(CC_FLAGS) $< -o $@
triggerKeyDown.o: src/triggerKeyDown.c\
	includes/triggerKeyDown.h\
	includes/handleMovement.h\
	../../includes/config/controls.h\
	../character/includes/Team.h\
	../location/includes/Direction.h\
	../map/includes/Map.h\
	../move/includes/go.h
	$(CC) $(CC_FLAGS) $< -o $@
triggerKeyUp.o: src/triggerKeyUp.c\
	includes/triggerKeyUp.h\
	includes/triggerAction.h\
	../../includes/config/controls.h\
	../map/includes/Map.h\
	../character/includes/Team.h
	$(CC) $(CC_FLAGS) $< -o $@
