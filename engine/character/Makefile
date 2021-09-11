CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../location/includes\
				 -iquote ../map/includes\
				 -iquote ../hitbox/includes\
				 -iquote ../display/includes\
				 -iquote ../font/includes\
				 -iquote ../../includes/config\
				 -iquote ../../lib/libMY\
				 -iquote ../item/includes\
				 -iquote ../../menu/character_creation/includes\
				 -iquote ../move/includes\
				 -iquote ../includes

OBJ=changeTeamState.o\
		createTeam.o\
		deleteCharacter.o\
		deleteTeam.o\
		enterMap.o\
		handleStateChange.o\
		initCharacter.o\
		initTeam.o\
		isFacingMapItem.o\
		loadBaseStats.o\
		loadCharacterSprite.o\
		maxCureTeam.o\
		putClosedEyes.o\
		searchStandUpPos.o\
		standUp.o\
		updateTeam.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

changeTeamState.o: src/changeTeamState.c\
	includes/changeTeamState.h\
	includes/standUp.h\
	../map/includes/Map.h includes/Team.h
	$(CC) $(CC_FLAGS) $< -o $@
createTeam.o: src/createTeam.c\
	includes/createTeam.h\
	includes/Team.h\
	includes/enterMap.h\
	includes/initTeam.h\
	../../menu/character_creation/includes/useCharacterCreationMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteCharacter.o: src/deleteCharacter.c\
	includes/deleteCharacter.h\
	includes/Character.h\
	../item/includes/deletePotionBag.h\
	../item/includes/deleteItemBag.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteTeam.o: src/deleteTeam.c\
	includes/deleteTeam.h\
	includes/Team.h\
	includes/deleteCharacter.h\
	../location/includes/deleteLocation.h\
	../hitbox/includes/deleteHitbox.h\
	../item/includes/deleteItemBag.h
	$(CC) $(CC_FLAGS) $< -o $@
enterMap.o: src/enterMap.c\
	includes/enterMap.h\
	includes/Team.h\
	../location/includes/setLocationMap.h
	$(CC) $(CC_FLAGS) $< -o $@
handleStateChange.o: src/handleStateChange.c\
	includes/handleStateChange.h\
	includes/Team.h\
	includes/updateTeam.h
	$(CC) $(CC_FLAGS) $< -o $@
initCharacter.o: src/initCharacter.c\
	includes/initCharacter.h\
	includes/Character.h\
	../location/includes/Direction.h\
	../map/includes/initMapItem.h\
	../item/includes/initPotionBag.h
	$(CC) $(CC_FLAGS) $< -o $@
initTeam.o: src/initTeam.c\
	includes/initTeam.h\
	includes/Team.h\
	includes/initCharacter.h\
	../location/includes/initLocation.h\
	../location/includes/setLocationMap.h\
	../hitbox/includes/initHitbox.h\
	../hitbox/includes/addToHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
isFacingMapItem.o: src/isFacingMapItem.c\
	includes/isFacingMapItem.h\
	includes/Team.h\
	../../includes/config/map_item.h\
	../map/includes/Map.h\
	../hitbox/includes/restrictMovements.h\
	../hitbox/includes/getHitboxDimensions.h\
	../../lib/libMY/MY_int.h
	$(CC) $(CC_FLAGS) $< -o $@
loadBaseStats.o: src/loadBaseStats.c\
	includes/loadBaseStats.h\
	includes/Race.h\
	includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
loadCharacterSprite.o: src/loadCharacterSprite.c\
	includes/loadCharacterSprite.h\
	includes/Character.h\
	includes/Race.h\
	../../includes/config/character_sprite.h\
	../../lib/libMY/MY_string.h\
	../location/includes/Direction.h
	$(CC) $(CC_FLAGS) $< -o $@
maxCureTeam.o: src/maxCureTeam.c\
	includes/maxCureTeam.h\
	includes/Team.h
	$(CC) $(CC_FLAGS) $< -o $@
putClosedEyes.o: src/putClosedEyes.c\
	includes/putClosedEyes.h\
	../../includes/config/character_sprite.h\
	includes/Character.h\
	includes/Race.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
searchStandUpPos.o: src/searchStandUpPos.c\
	includes/searchStandUpPos.h\
	includes/Character.h\
	includes/updateTeam.h\
	../hitbox/includes/getHitboxDimensions.h\
	../location/includes/Direction.h\
	../map/includes/Map.h\
	../move/includes/checkAllowedMoves.h
	$(CC) $(CC_FLAGS) $< -o $@
standUp.o: src/standUp.c\
	includes/standUp.h\
	includes/Team.h\
	includes/searchStandUpPos.h\
	../map/includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
updateTeam.o: src/updateTeam.c\
	includes/updateTeam.h\
	includes/Team.h\
	includes/loadCharacterSprite.h\
	../../includes/config/character_hitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
