CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../location/includes\
				 -iquote ../map/includes

OBJ=addToHitbox.o\
		checkRectIntersection.o\
		copyToHitbox.o\
		deleteFromHitbox.o\
		deleteHitbox.o\
		getCollisionOrigin.o\
		getHitboxDimensions.o\
		getMapHitbox.o\
		initHitbox.o\
		isInRect.o\
		loadHitbox.o\
		mergeHitboxes.o\
		restrictMovements.o\
		scanIntersection.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

addToHitbox.o: src/addToHitbox.c\
	includes/addToHitbox.h\
	includes/Hitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
checkRectIntersection.o: src/checkRectIntersection.c\
	includes/checkRectIntersection.h\
	includes/isInRect.h
	$(CC) $(CC_FLAGS) $< -o $@
copyToHitbox.o: src/copyToHitbox.c\
	includes/copyToHitbox.h\
	includes/Hitbox.h\
	includes/addToHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteFromHitbox.o: src/deleteFromHitbox.c\
	includes/deleteFromHitbox.h\
	includes/Hitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteHitbox.o: src/deleteHitbox.c\
	includes/deleteHitbox.h\
	includes/Hitbox.h\
	includes/deleteFromHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
getCollisionOrigin.o: src/getCollisionOrigin.c\
	includes/getCollisionOrigin.h\
	includes/isInRect.h\
	../location/includes/Direction.h
	$(CC) $(CC_FLAGS) $< -o $@
getHitboxDimensions.o: src/getHitboxDimensions.c\
	includes/getHitboxDimensions.h\
	includes/Hitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
getMapHitbox.o: src/getMapHitbox.c\
	includes/getMapHitbox.h\
	includes/Hitbox.h\
	includes/initHitbox.h\
	includes/mergeHitboxes.h\
	../map/includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
initHitbox.o: src/initHitbox.c\
	includes/initHitbox.h\
	includes/Hitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
isInRect.o: src/isInRect.c\
	includes/isInRect.h
	$(CC) $(CC_FLAGS) $< -o $@
loadHitbox.o: src/loadHitbox.c\
	includes/loadHitbox.h\
	includes/addToHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
mergeHitboxes.o: src/mergeHitboxes.c\
	includes/mergeHitboxes.h\
	includes/Hitbox.h\
	includes/copyToHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
restrictMovements.o: src/restrictMovements.c\
	includes/restrictMovements.h\
	includes/Hitbox.h\
	includes/getCollisionOrigin.h\
	includes/checkRectIntersection.h\
	../location/includes/Direction.h
	$(CC) $(CC_FLAGS) $< -o $@
scanIntersection.o: src/scanIntersection.c\
	includes/scanIntersection.h\
	includes/Hitbox.h\
	includes/checkRectIntersection.h\
	includes/copyToHitbox.h\
	includes/initHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
