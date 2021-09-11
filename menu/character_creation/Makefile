CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../includes/config\
				 -iquote ../../engine/font/includes\
				 -iquote ../../engine/character/includes\
				 -iquote ../../engine/location/includes\
				 -iquote ../../lib/libMY\
				 -iquote ../../engine/includes

OBJ=chooseConfirm.o\
		chooseRace.o\
		confirmCharacterCreation.o\
		hightlightInfo.o\
		prepareConfirmScreen.o\
		putCCMBoxes.o\
		putCharacterInfo.o\
		putCharacterPreview.o\
		putConfirm.o\
		putGender.o\
		putName.o\
		putRace.o\
		putRaceInfo.o\
		putRaces.o\
		putTeamInfo.o\
		putUserInfo.o\
		putYesNo.o\
		showRaceDescription.o\
		useCharacterCreationMenu.o\
		useRaceMenu.o\
		writeName.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

chooseConfirm.o: src/chooseConfirm.c\
	includes/chooseConfirm.h
	$(CC) $(CC_FLAGS) $< -o $@
chooseRace.o: src/chooseRace.c\
	includes/chooseRace.h\
	includes/showRaceDescription.h\
	includes/useRaceMenu.h\
	includes/putRaces.h\
	../../engine/includes/endSDL.h\
	../../includes/config/character_menu.h\
	../../includes/config/font.h
	$(CC) $(CC_FLAGS) $< -o $@
confirmCharacterCreation.o: src/confirmCharacterCreation.c\
	includes/confirmCharacterCreation.h\
	includes/prepareConfirmScreen.h\
	includes/chooseConfirm.h\
	../../includes/config/character_menu.h\
	../../engine/character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
hightlightInfo.o: src/hightlightInfo.c\
	includes/hightlightInfo.h\
	../../includes/config/character_menu.h
	$(CC) $(CC_FLAGS) $< -o $@
prepareConfirmScreen.o: src/prepareConfirmScreen.c\
	includes/prepareConfirmScreen.h\
	includes/putCharacterInfo.h\
	includes/putYesNo.h\
	../../includes/config/font.h\
	../../includes/config/character_menu.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putCCMBoxes.o: src/putCCMBoxes.c\
	includes/putCCMBoxes.h\
	includes/putTeamInfo.h\
	includes/putGender.h\
	includes/putRace.h\
	includes/putName.h\
	includes/putConfirm.h\
	includes/putUserInfo.h\
	../../includes/config/character_menu.h\
	../../includes/config/font.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
putCharacterInfo.o: src/putCharacterInfo.c\
	includes/putCharacterInfo.h\
	../../engine/font/includes/putFont.h\
	../../engine/character/includes/Character.h\
	../../engine/character/includes/Race.h
	$(CC) $(CC_FLAGS) $< -o $@
putCharacterPreview.o: src/putCharacterPreview.c\
	includes/putCharacterPreview.h\
	../../includes/config/character_sprite.h\
	../../includes/config/character_menu.h\
	../../engine/character/includes/Character.h\
	../../engine/character/includes/Race.h\
	../../engine/font/includes/putFont.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
putConfirm.o: src/putConfirm.c\
	includes/putConfirm.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putGender.o: src/putGender.c\
	includes/putGender.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putName.o: src/putName.c\
	includes/putName.h\
	../../includes/config/character_menu.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putRace.o: src/putRace.c\
	includes/putRace.h\
	../../includes/config/character_menu.h\
	../../engine/character/includes/Race.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putRaceInfo.o: src/putRaceInfo.c\
	includes/putRaceInfo.h\
	../../includes/config/character_menu.h\
	../../engine/character/includes/Race.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putRaces.o: src/putRaces.c\
	includes/putRaces.h\
	../../includes/config/character_menu.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putTeamInfo.o: src/putTeamInfo.c\
	includes/putTeamInfo.h\
	includes/putCharacterPreview.h\
	../../includes/config/character_menu.h\
	../../engine/character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
putUserInfo.o: src/putUserInfo.c\
	includes/putUserInfo.h\
	../../includes/config/character_menu.h\
	../../engine/font/includes/putFontColumn.h
	$(CC) $(CC_FLAGS) $< -o $@
putYesNo.o: src/putYesNo.c\
	includes/putYesNo.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
showRaceDescription.o: src/showRaceDescription.c\
	includes/showRaceDescription.h\
	includes/putRaceInfo.h\
	../../includes/config/character_menu.h
	$(CC) $(CC_FLAGS) $< -o $@
useCharacterCreationMenu.o: src/useCharacterCreationMenu.c\
	includes/useCharacterCreationMenu.h\
	includes/putCCMBoxes.h\
	includes/hightlightInfo.h\
	includes/chooseRace.h\
	includes/writeName.h\
	includes/confirmCharacterCreation.h\
	../../engine/includes/endSDL.h\
	../../engine/character/includes/loadCharacterSprite.h\
	../../engine/character/includes/loadBaseStats.h\
	../../engine/character/includes/Character.h\
	../../includes/config/font.h\
	../../includes/config/character_menu.h
	$(CC) $(CC_FLAGS) $< -o $@
useRaceMenu.o: src/useRaceMenu.c\
	includes/useRaceMenu.h\
	../../includes/config/character_menu.h
	$(CC) $(CC_FLAGS) $< -o $@
writeName.o: src/writeName.c\
	includes/writeName.h\
	../../includes/config/font.h\
	../../includes/config/character_menu.h\
	../../includes/config/character.h\
	../../lib/libMY/MY_string.h\
	../../engine/font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
