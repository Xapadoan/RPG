CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../lib/libMY/libMY_string/includes\
				 -iquote ../hitbox/includes\
				 -iquote ../../includes/config\
				 -iquote ../../lib/libMY/libMY_int/includes\
				 -iquote ../item/includes\
				 -iquote map_item_action/includes\
				 -iquote ../../lib/libMY/libMY_file/includes\
				 -iquote ../display/includes\
				 -iquote ../../lib/libMY/libMY_array/includes\
				 -iquote ../character/includes\
				 -iquote ../location/includes\
				 -iquote ../move/includes\
				 -iquote ../menu/includes\
				 -iquote ../font/includes

OBJ=addToMapBag.o\
		chooseMapItemAction.o\
		copyToMapBag.o\
		deleteFromMapBag.o\
		deleteMap.o\
		deleteMapBag.o\
		deleteMapItem.o\
		initMap.o\
		initMapBag.o\
		initMapItem.o\
		isItemContainer.o\
		isSameMapItem.o\
		loadMap.o\
		loadMapBag.o\
		loadMapItem.o\
		loadMapLine.o\
		loadMapStructures.o\
		loadMapTexture.o\
		loadStructureSprite.o\
		loadYMap.o\
		openMapItemList.o\
		searchItemInList.o\
		useMapByte.o

all: $(OBJ)
	$(MAKE) -C map_item_action all

clean:
	rm -f $(OBJ)
	$(MAKE) -C map_item_action clean

re: clean $(OBJ)
	$(MAKE) -C map_item_action re

addToMapBag.o: src/addToMapBag.c\
	includes/addToMapBag.h\
	includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
chooseMapItemAction.o: src/chooseMapItemAction.c\
	includes/chooseMapItemAction.h\
	includes/Map.h\
	map_item_action/includes/hashed_actions.h\
	map_item_action/includes/map_action_list.h\
	../../lib/libMY/libMY_int/includes/MY_pow.h
	$(CC) $(CC_FLAGS) $< -o $@
copyToMapBag.o: src/copyToMapBag.c\
	includes/copyToMapBag.h\
	includes/Map.h\
	includes/addToMapBag.h\
	includes/initMapItem.h\
	includes/deleteMapItem.h\
	../../includes/config/map_item.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_ncopy.h\
	../hitbox/includes/Hitbox.h\
	../hitbox/includes/initHitbox.h\
	../hitbox/includes/copyToHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteFromMapBag.o: src/deleteFromMapBag.c\
	includes/deleteFromMapBag.h\
	includes/Map.h\
	includes/deleteMapItem.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteMap.o: src/deleteMap.c\
	includes/deleteMap.h\
	includes/Map.h\
	includes/deleteMapBag.h\
	../hitbox/includes/deleteHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteMapBag.o: src/deleteMapBag.c\
	includes/deleteMapBag.h\
	includes/Map.h\
	includes/deleteFromMapBag.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteMapItem.o: src/deleteMapItem.c\
	includes/deleteMapItem.h\
	includes/Map.h\
	includes/isItemContainer.h\
	../hitbox/includes/deleteHitbox.h\
	../item/includes/deleteItemBag.h
	$(CC) $(CC_FLAGS) $< -o $@
initMap.o: src/initMap.c\
	includes/initMap.h\
	includes/Map.h\
	includes/initMapBag.h\
	../hitbox/includes/initHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
initMapBag.o: src/initMapBag.c\
	includes/initMapBag.h\
	includes/Map.h\
	includes/initMapItem.h
	$(CC) $(CC_FLAGS) $< -o $@
initMapItem.o: src/initMapItem.c\
	includes/initMapItem.h\
	includes/Map.h\
	../hitbox/includes/initHitbox.h\
	../item/includes/initItemBag.h
	$(CC) $(CC_FLAGS) $< -o $@
isItemContainer.o: src/isItemContainer.c\
	includes/isItemContainer.h\
	includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
isSameMapItem.o: src/isSameMapItem.c\
	includes/isSameMapItem.h\
	includes/Map.h\
	../../lib/libMY/libMY_string/includes/MY_str_compare.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMap.o: src/loadMap.c\
	includes/loadMap.h\
	includes/loadYMap.h\
	includes/Map.h\
	includes/loadMapStructures.h\
	includes/loadMapBag.h\
	../../includes/config/map.h\
	../hitbox/includes/loadHitbox.h\
	../character/includes/Team.h\
	../display/includes/displayHitbox.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMapBag.o: src/loadMapBag.c\
	includes/loadMapBag.h\
	includes/Map.h\
	includes/loadMapItem.h\
	includes/addToMapBag.h\
	includes/openMapItemList.h\
	../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMapItem.o: src/loadMapItem.c\
	includes/loadMapItem.h\
	includes/Map.h\
	includes/initMapItem.h\
	includes/deleteMapItem.h\
	includes/chooseMapItemAction.h\
	includes/isItemContainer.h\
	../../includes/config/map_item.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h\
	../../lib/libMY/libMY_string/includes/MY_str_ncopy.h\
	../../lib/libMY/libMY_string/includes/MY_str_split.h\
	../../lib/libMY/libMY_int/includes/MY_str2int.h\
	../../lib/libMY/libMY_array/includes/MY_free_2d_char.h\
	../hitbox/includes/loadHitbox.h\
	../location/includes/Direction.h\
	../item/includes/loadItemContainerItems.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMapLine.o: src/loadMapLine.c\
	includes/loadMapLine.h\
	includes/useMapByte.h\
	../../includes/config/map.h\
	../../lib/libMY/libMY_int/includes/MY_hex2dec.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMapStructures.o: src/loadMapStructures.c\
	includes/loadMapStructures.h\
	includes/loadStructureSprite.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMapTexture.o: src/loadMapTexture.c\
	includes/loadMapTexture.h\
	../../includes/config/textures_path.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) $< -o $@
loadStructureSprite.o: src/loadStructureSprite.c\
	includes/loadStructureSprite.h\
	../../includes/config/struct_sprite.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) $< -o $@
loadYMap.o: src/loadYMap.c\
	includes/loadYMap.h\
	includes/loadMapLine.h\
	../../includes/config/map.h
	$(CC) $(CC_FLAGS) $< -o $@
openMapItemList.o: src/openMapItemList.c\
	includes/openMapItemList.h\
	../../includes/config/map.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) $< -o $@
searchItemInList.o: src/searchItemInList.c\
	includes/searchItemInList.h\
	includes/Map.h\
	../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h
	$(CC) $(CC_FLAGS) $< -o $@
useMapByte.o: src/useMapByte.c\
	includes/useMapByte.h\
	includes/loadMapTexture.h\
	../../lib/libMY/libMY_int/includes/MY_hex2dec.h\
	../display/includes/fillRect.h
	$(CC) $(CC_FLAGS) $< -o $@
