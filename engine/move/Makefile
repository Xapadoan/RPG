CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../hitbox/includes\
				 -iquote ../character/includes\
				 -iquote ../map/includes\
				 -iquote ../display/includes\
				 -iquote ../location/includes\
				 -iquote ../../includes/config\
				 -iquote ../../lib/libMY

OBJ=checkAllowedMoves.o\
		checkAllowedMovesOmmit.o\
		go.o\
		handlePressedKeys.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

checkAllowedMoves.o: src/checkAllowedMoves.c\
	includes/checkAllowedMoves.h\
	../../includes/config/character_hitbox.h\
	../map/includes/Map.h\
	../character/includes/Team.h\
	../hitbox/includes/initHitbox.h\
	../hitbox/includes/scanIntersection.h\
	../hitbox/includes/restrictMovements.h\
	../hitbox/includes/deleteHitbox.h\
	../hitbox/includes/mergeHitboxes.h\
	../display/includes/displayHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
checkAllowedMovesOmmit.o: src/checkAllowedMovesOmmit.c\
	includes/checkAllowedMovesOmmit.h\
	../../includes/config/character_hitbox.h\
	../map/includes/Map.h\
	../character/includes/Team.h\
	../hitbox/includes/initHitbox.h\
	../hitbox/includes/scanIntersection.h\
	../hitbox/includes/restrictMovements.h\
	../hitbox/includes/deleteHitbox.h\
	../hitbox/includes/mergeHitboxes.h\
	../display/includes/displayHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
go.o: src/go.c\
	includes/go.h\
	includes/checkAllowedMoves.h\
	../character/includes/Team.h\
	../character/includes/updateTeam.h\
	../location/includes/Direction.h\
	../map/includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
handlePressedKeys.o: src/handlePressedKeys.c\
	includes/handlePressedKeys.h\
	includes/go.h\
	../../includes/config/controls.h\
	../character/includes/Team.h\
	../character/includes/changeTeamState.h\
	../location/includes/Direction.h\
	../map/includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
