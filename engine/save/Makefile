CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../character/includes\
				 -iquote ../location/includes\
				 -iquote ../hitbox/includes\
				 -iquote ../../includes/config\
				 -iquote ../../lib/libMY

OBJ=loadCharacter.o\
		loadTeam.o\
		saveCharacter.o\
		saveTeam.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

loadCharacter.o: src/loadCharacter.c\
	includes/loadCharacter.h\
	../../lib/libMY/MY_string.h\
	../character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
loadTeam.o: src/loadTeam.c\
	includes/loadTeam.h\
	includes/loadCharacter.h\
	../character/includes/Team.h\
	../character/includes/loadCharacterSprite.h
	$(CC) $(CC_FLAGS) $< -o $@
saveCharacter.o: src/saveCharacter.c\
	includes/saveCharacter.h\
	../character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
saveTeam.o: src/saveTeam.c\
	includes/saveTeam.h\
	includes/saveCharacter.h\
	../character/includes/Team.h
	$(CC) $(CC_FLAGS) $< -o $@
