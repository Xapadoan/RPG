CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../includes/config\
				 -iquote ../map/includes\
				 -iquote ../character/includes\
				 -iquote ../hitbox/includes\
				 -iquote ../../lib/libMY/libMY_string/includes\
				 -iquote ../../lib/libMY/libMY_int/includes\
				 -iquote ../location/includes

OBJ=addToSpriteList.o\
		applyRGBA.o\
		blitOnCenter.o\
		deleteFromSpriteList.o\
		displayCharacter.o\
		displayHitbox.o\
		displayMap.o\
		displayMapItems.o\
		displaySpriteList.o\
		drawBresenhamCircle.o\
		drawThickCircle.o\
		fillHoles.o\
		fillRect.o\
		initSpriteList.o\
		putPixel.o\
		sortGroundItems.o

addToSpriteList.o: src/addToSpriteList.c\
	includes/addToSpriteList.h\
	includes/SpriteList.h\
	../../includes/config/screen.h
	$(CC) $(CC_FLAGS) $< -o $@
applyRGBA.o: src/applyRGBA.c\
	includes/applyRGBA.h\
	../../includes/config/screen.h
	$(CC) $(CC_FLAGS) $< -o $@
blitOnCenter.o: src/blitOnCenter.c\
	includes/blitOnCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteFromSpriteList.o: src/deleteFromSpriteList.c\
	includes/deleteFromSpriteList.h\
	includes/SpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
displayCharacter.o: src/displayCharacter.c\
	includes/displayCharacter.h\
	../../lib/libMY/libMY_int/includes/MY_is_pair.h\
	../../lib/libMY/libMY_string/includes/MY_replace_char.h\
	../character/includes/loadCharacterSprite.h
	$(CC) $(CC_FLAGS) $< -o $@
displayHitbox.o: src/displayHitbox.c\
	includes/displayHitbox.h\
	../hitbox/includes/Hitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
displayMap.o: src/displayMap.c\
	includes/displayMap.h\
	includes/SpriteList.h\
	includes/initSpriteList.h\
	includes/deleteSpriteList.h\
	includes/displaySpriteList.h\
	includes/displayCharacter.h\
	includes/displayMapItems.h\
	includes/sortGroundItems.h\
	../../includes/config/screen.h\
	../../includes/config/map.h\
	../../includes/config/character_sprite.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h\
	../character/includes/Team.h\
	../map/includes/Map.h\
	../map/includes/initMapBag.h\
	../map/includes/deleteMapBag.h
	$(CC) $(CC_FLAGS) $< -o $@
displayMapItems.o: src/displayMapItems.c\
	includes/displayMapItems.h\
	../map/includes/Map.h\
	../hitbox/includes/isInRect.h
	$(CC) $(CC_FLAGS) $< -o $@
displaySpriteList.o: src/displaySpriteList.c\
	includes/displaySpriteList.h\
	includes/SpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
drawBresenhamCircle.o: src/drawBresenhamCircle.c\
	includes/drawBresenhamCircle.h\
	includes/putPixel.h\
	includes/circle_portions.h\
	../../lib/libMY/libMY_int/includes/MY_abs.h
	$(CC) $(CC_FLAGS) $< -o $@
drawThickCircle.o: src/drawThickCircle.c\
	includes/drawThickCircle.h\
	includes/circle_portions.h\
	includes/drawBresenhamCircle.h\
	includes/fillHoles.h
	$(CC) $(CC_FLAGS) $< -o $@
fillHoles.o: src/fillHoles.c\
	includes/fillHoles.h\
	includes/putPixel.h
	$(CC) $(CC_FLAGS) $< -o $@
fillRect.o: src/fillRect.c\
	includes/fillRect.h
	$(CC) $(CC_FLAGS) $< -o $@
initSpriteList.o: src/initSpriteList.c\
	includes/initSpriteList.h\
	includes/SpriteList.h\
	includes/deleteSpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
putPixel.o: src/putPixel.c\
	includes/putPixel.h
	$(CC) $(CC_FLAGS) $< -o $@
sortGroundItems.o: src/sortGroundItems.c\
	includes/sortGroundItems.h\
	includes/SpriteList.h\
	includes/initSpriteList.h\
	includes/addToSpriteList.h\
	../../includes/config/character_sprite.h\
	../map/includes/Map.h\
	../character/includes/Team.h\
	../hitbox/includes/checkRectIntersection.h
	$(CC) $(CC_FLAGS) $< -o $@

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)
