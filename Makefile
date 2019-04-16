CC=gcc
CC_FLAGS=-g -Wall -Wextra -Werror
LD_FLAGS=-Llib/libMY -lMY_int -lMY_array -lMY_string -lMY_file -lSDL\
		 -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx
ENGINE_LD_FLAGS= -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx
EXEC=myRPG_v-0.00.003

LIBMY_STRING_DIR=lib/libMY/libMY_string
LIBMY_STRING_OBJ=$(LIBMY_STRING_DIR)/obj/MY_str_len.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_append.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_ncopy.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_substr.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_split.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_compare.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_to_upper.o\
				 $(LIBMY_STRING_DIR)/obj/MY_remove_char.o\
				 $(LIBMY_STRING_DIR)/obj/MY_replace_char.o\
				 $(LIBMY_STRING_DIR)/obj/MY_clear_string.o\
				 $(LIBMY_STRING_DIR)/obj/MY_str_capitalize.o\
				 $(LIBMY_STRING_DIR)/obj/MY_dec2str.o

LIBMY_ARRAY_DIR=lib/libMY/libMY_array
LIBMY_ARRAY_OBJ=$(LIBMY_ARRAY_DIR)/obj/MY_free_2d_char.o

LIBMY_INT_DIR=lib/libMY/libMY_int
LIBMY_INT_OBJ=$(LIBMY_INT_DIR)/obj/MY_hex2dec.o\
			  $(LIBMY_INT_DIR)/obj/MY_pow.o\
			  $(LIBMY_INT_DIR)/obj/MY_str2int.o\
			  $(LIBMY_INT_DIR)/obj/MY_is_pair.o\
			  $(LIBMY_INT_DIR)/obj/MY_hex2char.o\
			  $(LIBMY_INT_DIR)/obj/MY_abs.o\
			  $(LIBMY_INT_DIR)/obj/MY_str2hex.o

LIBMY_FILE_DIR=lib/libMY/libMY_file
LIBMY_FILE_OBJ=$(LIBMY_FILE_DIR)/obj/MY_go_to_next_line.o

PARSER_DIR=config_parser
PARSER_OBJ=$(PARSER_DIR)/obj/loadConfFile.o $(PARSER_DIR)/obj/parseFile.o\
		   $(PARSER_DIR)/obj/extendAttributeName.o\
		   $(PARSER_DIR)/obj/writeConfigFile.o

ENGINE_DIR=engine
ENGINE_IFLAGS=$(CHARACTER_IFLAGS) $(DISPLAY_IFLAGS) $(HITBOX_IFLAGS) $(MAP_IFLAGS)\
			  $(MAP_ITEM_IFLAGS) $(SAVE_IFLAGS) $(MUSIC_IFLAGS) $(PLAY_IFLAGS)\
			  $(LOCATION_IFLAGS) $(FONT_IFLAGS) $(MOVE_IFLAGS) $(MENU_IFLAGS)\
			  $(ITEM_IFLAGS)
ENGINE_OBJ=$(ENGINE_DIR)/obj/initEngine.o $(ENGINE_DIR)/obj/endSDL.o $(CHARACTER_OBJ)\
		   $(DISPLAY_OBJ) $(HITBOX_OBJ) $(MAP_OBJ) $(MAP_ITEM_OBJ) $(SAVE_OBJ)\
		   $(MUSIC_OBJ) $(PLAY_OBJ) $(LOCATION_OBJ) $(FONT_OBJ) $(MOVE_OBJ)\
		   $(MENU_OBJ) $(ITEM_OBJ) $(MY_MAIN_MENU_OBJ)\
		   $(MY_CHARACTER_CREATION_OBJ)

CHARACTER_DIR=$(ENGINE_DIR)/character
CHARACTER_OBJ=$(CHARACTER_DIR)/obj/initCharacter.o\
			  $(CHARACTER_DIR)/obj/initTeam.o\
			  $(CHARACTER_DIR)/obj/deleteCharacter.o\
			  $(CHARACTER_DIR)/obj/deleteTeam.o\
			  $(CHARACTER_DIR)/obj/createTeam.o\
			  $(CHARACTER_DIR)/obj/loadBaseStats.o\
			  $(CHARACTER_DIR)/obj/enterMap.o\
			  $(CHARACTER_DIR)/obj/loadCharacterSprite.o\
			  $(CHARACTER_DIR)/obj/updateTeam.o\
			  $(CHARACTER_DIR)/obj/isFacingMapItem.o\
			  $(CHARACTER_DIR)/obj/maxCureTeam.o\
			  $(CHARACTER_DIR)/obj/putClosedEyes.o\
			  $(CHARACTER_DIR)/obj/handleStateChange.o\
			  $(CHARACTER_DIR)/obj/changeTeamState.o\
			  $(CHARACTER_DIR)/obj/standUp.o\
			  $(CHARACTER_DIR)/obj/searchStandUpPos.o

MAP_DIR=$(ENGINE_DIR)/map
MAP_OBJ=$(MAP_DIR)/obj/initMap.o $(MAP_DIR)/obj/initMapBag.o\
		$(MAP_DIR)/obj/loadMap.o $(MAP_DIR)/obj/loadYMap.o\
		$(MAP_DIR)/obj/loadMapLine.o $(MAP_DIR)/obj/loadMapTexture.o\
		$(MAP_DIR)/obj/useMapByte.o $(MAP_DIR)/obj/deleteMap.o\
		$(MAP_DIR)/obj/loadMapStructures.o $(MAP_DIR)/obj/loadStructureSprite.o\
		$(MAP_DIR)/obj/initMapItem.o $(MAP_DIR)/obj/deleteMapBag.o\
		$(MAP_DIR)/obj/deleteFromMapBag.o $(MAP_DIR)/obj/deleteMapItem.o\
		$(MAP_DIR)/obj/loadMapBag.o $(MAP_DIR)/obj/loadMapItem.o\
		$(MAP_DIR)/obj/addToMapBag.o $(MAP_DIR)/obj/chooseMapItemAction.o\
		$(MAP_DIR)/obj/copyToMapBag.o $(MAP_DIR)/obj/openMapItemList.o\
		$(MAP_DIR)/obj/searchItemInList.o $(MAP_DIR)/obj/isSameMapItem.o\
		$(MAP_DIR)/obj/isItemContainer.o

MAP_ITEM_DIR=$(MAP_DIR)/map_item_action
MAP_ITEM_IFLAGS=-iquote $(MENU_DIR)/includes -iquote $(CHARACTER_DIR)/includes\
				-iquote $(MAP_DIR)/includes
MAP_ITEM_OBJ=$(MAP_ITEM_DIR)/obj/sleep.o\
			 $(MAP_ITEM_DIR)/obj/sitOnChair.o\
			 $(MAP_ITEM_DIR)/obj/openItemContainer.o

HITBOX_DIR=$(ENGINE_DIR)/hitbox
HITBOX_OBJ=$(HITBOX_DIR)/obj/initHitbox.o $(HITBOX_DIR)/obj/addToHitbox.o\
		   $(HITBOX_DIR)/obj/deleteFromHitbox.o\
		   $(HITBOX_DIR)/obj/deleteHitbox.o $(HITBOX_DIR)/obj/loadHitbox.o\
		   $(HITBOX_DIR)/obj/checkRectIntersection.o\
		   $(HITBOX_DIR)/obj/getCollisionOrigin.o\
		   $(HITBOX_DIR)/obj/copyToHitbox.o\
		   $(HITBOX_DIR)/obj/restrictMovements.o\
		   $(HITBOX_DIR)/obj/scanIntersection.o $(HITBOX_DIR)/obj/isInRect.o\
		   $(HITBOX_DIR)/obj/mergeHitboxes.o\
		   $(HITBOX_DIR)/obj/getHitboxDimensions.o\
		   $(HITBOX_DIR)/obj/getMapHitbox.o

DISPLAY_DIR=$(ENGINE_DIR)/display
DISPLAY_OBJ=$(DISPLAY_DIR)/obj/displayMapItems.o\
			$(DISPLAY_DIR)/obj/displayMap.o $(DISPLAY_DIR)/obj/displayHitbox.o\
			$(DISPLAY_DIR)/obj/fillRect.o $(DISPLAY_DIR)/obj/displayCharacter.o\
			$(DISPLAY_DIR)/obj/sortGroundItems.o\
			$(DISPLAY_DIR)/obj/initSpriteList.o\
			$(DISPLAY_DIR)/obj/addToSpriteList.o\
			$(DISPLAY_DIR)/obj/deleteFromSpriteList.o\
			$(DISPLAY_DIR)/obj/deleteSpriteList.o\
			$(DISPLAY_DIR)/obj/displaySpriteList.o\
			$(DISPLAY_DIR)/obj/applyRGBA.o $(DISPLAY_DIR)/obj/blitOnCenter.o\
			$(DISPLAY_DIR)/obj/putPixel.o\
			$(DISPLAY_DIR)/obj/drawBresenhamCircle.o\
			$(DISPLAY_DIR)/obj/drawThickCircle.o\
			$(DISPLAY_DIR)/obj/fillHoles.o

SAVE_DIR=$(ENGINE_DIR)/save
SAVE_OBJ=$(SAVE_DIR)/obj/loadCharacter.o $(SAVE_DIR)/obj/loadTeam.o\
		 $(SAVE_DIR)/obj/saveCharacter.o $(SAVE_DIR)/obj/saveTeam.o

MUSIC_DIR=$(ENGINE_DIR)/music
MUSIC_OBJ=$(MUSIC_DIR)/obj/startPlayingMusic.o\
		  $(MUSIC_DIR)/obj/stopPlayingMusic.o

PLAY_DIR=$(ENGINE_DIR)/play
PLAY_OBJ=$(PLAY_DIR)/obj/triggerKeyUp.o engine/play/obj/playGame.o\
		 $(PLAY_DIR)/obj/triggerAction.o\
		 $(PLAY_DIR)/obj/handleMovement.o

LOCATION_DIR=$(ENGINE_DIR)/location
LOCATION_OBJ=$(LOCATION_DIR)/obj/initLocation.o\
			 $(LOCATION_DIR)/obj/setLocationMap.o\
			 $(LOCATION_DIR)/obj/deleteLocation.o

FONT_DIR=$(ENGINE_DIR)/font
FONT_OBJ=$(FONT_DIR)/obj/putFontCenter.o $(FONT_DIR)/obj/putFont.o\
		 $(FONT_DIR)/obj/putFontColumn.o

MOVE_DIR=$(ENGINE_DIR)/move
MOVE_OBJ=$(MOVE_DIR)/obj/go.o $(MOVE_DIR)/obj/checkAllowedMoves.o\
		 $(MOVE_DIR)/obj/handlePressedKeys.o\
		 $(MOVE_DIR)/obj/checkAllowedMovesOmmit.o

MENU_DIR=$(ENGINE_DIR)/menu
MENU_IFLAGS=-iquote $(MENU_DIR)/includes -iquote $(ITEM_DIR)/includes\
			-iquote includes/config -iquote $(LIBMY_STRING_DIR)/includes\
			-iquote $(LIBMY_INT_DIR)/includes -iquote $(FONT_DIR)/includes
MENU_OBJ=$(MENU_DIR)/obj/prepareExchangeScreen.o $(MENU_DIR)/obj/initTabMenu.o\
		 $(MENU_DIR)/obj/deleteTabMenu.o $(MENU_DIR)/obj/deleteTabList.o\
		 $(MENU_DIR)/obj/deleteTab.o $(MENU_DIR)/obj/deleteTabEntry.o\
		 $(MENU_DIR)/obj/setTabMenuWidth.o $(MENU_DIR)/obj/setTabMenuHeight.o\
		 $(MENU_DIR)/obj/setTabMenuHeaderHeight.o\
		 $(MENU_DIR)/obj/setTabsPreviewHeight.o\
		 $(MENU_DIR)/obj/putTabMenuBorders.o\
		 $(MENU_DIR)/obj/updateItemExchangeHeader.o\
		 $(MENU_DIR)/obj/putTabMenuHeaderBackground.o\
		 $(MENU_DIR)/obj/updateItemExchangeTabsPreview.o\
		 $(MENU_DIR)/obj/putTabsPreviewSeparation.o\
		 $(MENU_DIR)/obj/loadTabPreviewIcon.o\
		 $(MENU_DIR)/obj/initTabList.o $(MENU_DIR)/obj/initTab.o\
		 $(MENU_DIR)/obj/putTabContentBackground.o\
		 $(MENU_DIR)/obj/createItemExchangeTabs.o\
		 $(MENU_DIR)/obj/loadItemExchangeMenuContent.o\
		 $(MENU_DIR)/obj/loadPotionTab.o $(MENU_DIR)/obj/addPotionDataToTab.o\
		 $(MENU_DIR)/obj/initTabEntry.o $(MENU_DIR)/obj/addEntryToTab.o\
		 $(MENU_DIR)/obj/updateTabContent.o\
		 $(MENU_DIR)/obj/sortTabDefaultOrder.o\
		 $(MENU_DIR)/obj/getDisplayTabEntry.o\
		 $(MENU_DIR)/obj/updateItemExchangeMenu.o\
		 $(MENU_DIR)/obj/handleTabMenuEvent.o $(MENU_DIR)/obj/getActiveTab.o\
		 $(MENU_DIR)/obj/putNoEntryMessage.o $(MENU_DIR)/obj/putItemPreview.o\
		 $(MENU_DIR)/obj/loadItemDescription.o $(MENU_DIR)/obj/loadArmorTab.o\
		 $(MENU_DIR)/obj/addArmorDataToTab.o $(MENU_DIR)/obj/loadBookTab.o\
		 $(MENU_DIR)/obj/addBookDataToTab.o $(MENU_DIR)/obj/loadMiscItemTab.o\
		 $(MENU_DIR)/obj/addMiscItemDataToTab.o $(MENU_DIR)/obj/loadWeaponTab.o\
		 $(MENU_DIR)/obj/addWeaponDataToTab.o

ITEM_DIR=$(ENGINE_DIR)/item
ITEM_OBJ=$(ITEM_DIR)/obj/initItemBag.o $(ITEM_DIR)/obj/initPotionBag.o\
		 $(ITEM_DIR)/obj/initPotion.o $(ITEM_DIR)/obj/deletePotion.o\
		 $(ITEM_DIR)/obj/deletePotionBag.o $(ITEM_DIR)/obj/initArmorBag.o\
		 $(ITEM_DIR)/obj/deleteArmorBag.o $(ITEM_DIR)/obj/initArmor.o\
		 $(ITEM_DIR)/obj/deleteArmor.o $(ITEM_DIR)/obj/initWeaponBag.o\
		 $(ITEM_DIR)/obj/deleteWeaponBag.o $(ITEM_DIR)/obj/initWeapon.o\
		 $(ITEM_DIR)/obj/deleteWeapon.o $(ITEM_DIR)/obj/initBookBag.o\
		 $(ITEM_DIR)/obj/deleteBookBag.o $(ITEM_DIR)/obj/initBook.o\
		 $(ITEM_DIR)/obj/deleteBook.o $(ITEM_DIR)/obj/initMiscBag.o\
		 $(ITEM_DIR)/obj/deleteMiscBag.o $(ITEM_DIR)/obj/initMiscItem.o\
		 $(ITEM_DIR)/obj/deleteMiscItem.o $(ITEM_DIR)/obj/deleteItemBag.o\
		 $(ITEM_DIR)/obj/loadItemContainerItems.o\
		 $(ITEM_DIR)/obj/applyHealthPotion.o\
		 $(ITEM_DIR)/obj/applyStaminaPotion.o\
		 $(ITEM_DIR)/obj/applyDurableHealthPotion.o\
		 $(ITEM_DIR)/obj/applyDurableStaminaPotion.o\
		 $(ITEM_DIR)/obj/addCopyToPotionBag.o\
		 $(ITEM_DIR)/obj/linkPotionAction.o $(ITEM_DIR)/obj/addToPotionBag.o\
		 $(ITEM_DIR)/obj/loadItemBag.o $(ITEM_DIR)/obj/loadPotionBag.o\
		 $(ITEM_DIR)/obj/setPotionData.o

MY_CHARACTER_CREATION_DIR=menu/character_creation
MY_MAIN_MENU_DIR=menu/main_menu
MY_MENU_OBJ=$(MY_MAIN_MENU_DIR)/obj/useMainMenu.o\
			$(MY_MAIN_MENU_DIR)/obj/putTitleScreen.o\
			$(MY_MAIN_MENU_DIR)/obj/putMainChoices.o\
			$(MY_MAIN_MENU_DIR)/obj/moveMainCursor.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putCCMBoxes.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putCharacterPreview.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putConfirm.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putGender.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putName.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putRace.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putTeamInfo.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putUserInfo.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/useCharacterCreationMenu.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/hightlightInfo.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/chooseRace.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/writeName.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/confirmCharacterCreation.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/showRaceDescription.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putRaces.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/useRaceMenu.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putYesNo.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putCharacterInfo.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/prepareConfirmScreen.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/chooseConfirm.o\
			$(MY_CHARACTER_CREATION_DIR)/obj/putRaceInfo.o

IFLAGS=-iquote includes\
	   -iquote includes/config\
	   -iquote config_parser/includes\
	   -iquote $(ENGINE_DIR)/includes\
	   -iquote $(CHARACTER_DIR)/includes\
	   -iquote $(DISPLAY_DIR)/includes\
	   -iquote $(FONT_DIR)/includes\
	   -iquote $(HITBOX_DIR)/includes\
	   -iquote $(ITEM_DIR)/includes\
	   -iquote $(LOCATION_DIR)/includes\
	   -iquote $(MAP_DIR)/includes\
	   -iquote $(MENU_DIR)/includes\
	   -iquote $(MOVE_DIR)/includes\
	   -iquote $(MUSIC_DIR)/includes\
	   -iquote $(PLAY_DIR)/includes\
	   -iquote $(SAVE_DIR)/includes\
	   -iquote $(LIBMY_STRING_DIR)/includes\
	   -iquote $(LIBMY_INT_DIR)/includes\
	   -iquote $(LIBMY_ARRAY_DIR)/includes\
	   -iquote $(LIBMY_FILE_DIR)/includes
OBJ=obj/main.o $(ENGINE_OBJ) $(MY_MENU_OBJ)

obj/main.o : src/main.c includes/main.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(EXEC) : $(OBJ)
	$(CC) $(CC_FLAGS) $(IFLAGS) $^ -o $@ $(LD_FLAGS)

$(LIBMY_STRING_DIR)/obj/MY_str_len.o : $(LIBMY_STRING_DIR)/src/MY_str_len.c $(LIBMY_STRING_DIR)/includes/MY_str_len.h
$(LIBMY_STRING_DIR)/obj/MY_str_append.o : $(LIBMY_STRING_DIR)/src/MY_str_append.c $(LIBMY_STRING_DIR)/includes/MY_str_append.h
$(LIBMY_STRING_DIR)/obj/MY_str_substr.o : $(LIBMY_STRING_DIR)/src/MY_str_substr.c $(LIBMY_STRING_DIR)/includes/MY_str_substr.h
$(LIBMY_STRING_DIR)/obj/MY_str_ncopy.o : $(LIBMY_STRING_DIR)/src/MY_str_ncopy.c $(LIBMY_STRING_DIR)/includes/MY_str_ncopy.h
$(LIBMY_STRING_DIR)/obj/MY_str_split.o : $(LIBMY_STRING_DIR)/src/MY_str_split.c $(LIBMY_STRING_DIR)/includes/MY_str_split.h
$(LIBMY_STRING_DIR)/obj/MY_str_compare.o : $(LIBMY_STRING_DIR)/src/MY_str_compare.c $(LIBMY_STRING_DIR)/includes/MY_str_compare.h
$(LIBMY_STRING_DIR)/obj/MY_str_to_upper.o : $(LIBMY_STRING_DIR)/src/MY_str_to_upper.c $(LIBMY_STRING_DIR)/includes/MY_str_to_upper.h
$(LIBMY_STRING_DIR)/obj/MY_remove_char.o : $(LIBMY_STRING_DIR)/src/MY_remove_char.c $(LIBMY_STRING_DIR)/includes/MY_remove_char.h
$(LIBMY_STRING_DIR)/obj/MY_replace_char.o : $(LIBMY_STRING_DIR)/src/MY_replace_char.c $(LIBMY_STRING_DIR)/includes/MY_replace_char.h
$(LIBMY_STRING_DIR)/obj/MY_clear_string.o : $(LIBMY_STRING_DIR)/src/MY_clear_string.c $(LIBMY_STRING_DIR)/includes/MY_clear_string.h
$(LIBMY_STRING_DIR)/obj/MY_str_capitalize.o : $(LIBMY_STRING_DIR)/src/MY_str_capitalize.c $(LIBMY_STRING_DIR)/includes/MY_str_capitalize.h
$(LIBMY_STRING_DIR)/obj/MY_dec2str.o : $(LIBMY_STRING_DIR)/src/MY_dec2str.c $(LIBMY_STRING_DIR)/includes/MY_dec2str.h
$(LIBMY_STRING_DIR)/obj/%.o : $(LIBMY_STRING_DIR)/src/%.c $(LIBMY_STRING_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

lib/libMY/libMY_string.a : $(LIBMY_STRING_OBJ)
	ar rc $@ $^
	ranlib $@

$(LIBMY_ARRAY_DIR)/obj/MY_free_2d_char.o : $(LIBMY_ARRAY_DIR)/src/MY_free_2d_char.c $(LIBMY_ARRAY_DIR)/includes/MY_free_2d_char.h

$(LIBMY_ARRAY_DIR)/obj/%.o : $(LIBMY_ARRAY_DIR)/src/%.c $(LIBMY_ARRAY_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

lib/libMY/libMY_array.a : $(LIBMY_ARRAY_OBJ)
	ar rc $@ $^
	ranlib $@

$(LIBMY_INT_DIR)/obj/MY_hex2dec.o : $(LIBMY_INT_DIR)/src/MY_hex2dec.c $(LIBMY_INT_DIR)/includes/MY_hex2dec.h
$(LIBMY_INT_DIR)/obj/MY_hex2char.o : $(LIBMY_INT_DIR)/src/MY_hex2char.c $(LIBMY_INT_DIR)/includes/MY_hex2char.h
$(LIBMY_INT_DIR)/obj/MY_str2int.o : $(LIBMY_INT_DIR)/src/MY_str2int.c $(LIBMY_INT_DIR)/includes/MY_str2int.h
$(LIBMY_INT_DIR)/obj/MY_pow.o : $(LIBMY_INT_DIR)/src/MY_pow.c $(LIBMY_INT_DIR)/includes/MY_pow.h
$(LIBMY_INT_DIR)/obj/MY_is_pair.o : $(LIBMY_INT_DIR)/src/MY_is_pair.c $(LIBMY_INT_DIR)/includes/MY_is_pair.h
$(LIBMY_INT_DIR)/obj/MY_abs.o : $(LIBMY_INT_DIR)/src/MY_abs.c $(LIBMY_INT_DIR)/includes/MY_abs.h
$(LIBMY_INT_DIR)/obj/MY_str2hex.o : $(LIBMY_INT_DIR)/src/MY_str2hex.c $(LIBMY_INT_DIR)/includes/MY_str2hex.h

$(LIBMY_INT_DIR)/obj/%.o : $(LIBMY_INT_DIR)/src/%.c $(LIBMY_INT_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

lib/libMY/libMY_int.a : $(LIBMY_INT_OBJ)
	ar rc $@ $^
	ranlib $@

$(LIBMY_FILE_DIR)/obj/MY_go_to_next_line.o : $(LIBMY_FILE_DIR)/src/MY_go_to_next_line.c $(LIBMY_FILE_DIR)/includes/MY_go_to_next_line.h

$(LIBMY_FILE_DIR)/obj/%.o : $(LIBMY_FILE_DIR)/src/%.c $(LIBMY_FILE_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

lib/libMY/libMY_file.a : $(LIBMY_FILE_OBJ)
	ar rc $@ $^
	ranlib $@

$(PARSER_DIR)/obj/loadConfFile.o : $(PARSER_DIR)/src/loadConfFile.c $(PARSER_DIR)/includes/loadConfFile.h
$(PARSER_DIR)/obj/parseFile.o : $(PARSER_DIR)/src/parseFile.c $(PARSER_DIR)/includes/parseFile.h
$(PARSER_DIR)/obj/extendAttributeName.o : $(PARSER_DIR)/src/extendAttributeName.c $(PARSER_DIR)/includes/extendAttributeName.h
$(PARSER_DIR)/obj/writeConfigFile.o : $(PARSER_DIR)/src/writeConfigFile.c $(PARSER_DIR)/includes/writeConfigFile.h
$(PARSER_DIR)/obj/%.o : $(PARSER_DIR)/src/%.c $(PARSER_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@ -Llib/libMY -lMY_string

$(ENGINE_DIR)/obj/initEngine.o : $(ENGINE_DIR)/src/initEngine.c $(ENGINE_DIR)/includes/initEngine.h
$(ENGINE_DIR)/obj/endSDL.o : $(ENGINE_DIR)/src/endSDL.c $(ENGINE_DIR)/includes/endSDL.h
$(ENGINE_DIR)/obj/%.o : $(ENGINE_DIR)/src/%.c $(ENGINE_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(FONT_DIR)/obj/putFontCenter.o : $(FONT_DIR)/src/putFontCenter.c $(FONT_DIR)/includes/putFontCenter.h
$(FONT_DIR)/obj/putFont.o : $(FONT_DIR)/src/putFont.c $(FONT_DIR)/includes/putFont.h
$(FONT_DIR)/obj/putFontColumn.o : $(FONT_DIR)/src/putFontColumn.c $(FONT_DIR)/includes/putFontColumn.h
$(FONT_DIR)/obj/%.o : $(FONT_DIR)/src/%.c $(FONT_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(MUSIC_DIR)/obj/startPlayingMusic.o : $(MUSIC_DIR)/src/startPlayingMusic.c $(MUSIC_DIR)/includes/startPlayingMusic.h
$(MUSIC_DIR)/obj/stopPlayingMusic.o : $(MUSIC_DIR)/src/stopPlayingMusic.c $(MUSIC_DIR)/includes/stopPlayingMusic.h
$(MUSIC_DIR)/obj/%.o : $(MUSIC_DIR)/src/%.c $(MUSIC_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(SAVE_DIR)/obj/saveTeam.o : $(SAVE_DIR)/src/saveTeam.c $(SAVE_DIR)/includes/saveTeam.h
$(SAVE_DIR)/obj/saveCharacter.o : $(SAVE_DIR)/src/saveCharacter.c $(SAVE_DIR)/includes/saveCharacter.h
$(SAVE_DIR)/obj/loadTeam.o : $(SAVE_DIR)/src/loadTeam.c $(SAVE_DIR)/includes/loadTeam.h
$(SAVE_DIR)/obj/loadCharacter.o : $(SAVE_DIR)/src/loadCharacter.c $(SAVE_DIR)/includes/loadCharacter.h
$(SAVE_DIR)/obj/%.o : $(SAVE_DIR)/src/%.c $(SAVE_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(DISPLAY_DIR)/obj/displayMap.o : $(DISPLAY_DIR)/src/displayMap.c $(DISPLAY_DIR)/includes/displayMap.h
$(DISPLAY_DIR)/obj/displayCharacter.o : $(DISPLAY_DIR)/src/displayCharacter.c $(DISPLAY_DIR)/includes/displayCharacter.h
$(DISPLAY_DIR)/obj/fillRect.o : $(DISPLAY_DIR)/src/fillRect.c $(DISPLAY_DIR)/includes/fillRect.h
$(DISPLAY_DIR)/obj/displayHitbox.o : $(DISPLAY_DIR)/src/displayHitbox.c $(DISPLAY_DIR)/includes/displayHitbox.h
$(DISPLAY_DIR)/obj/displayMapItems.o : $(DISPLAY_DIR)/src/displayMapItems.c $(DISPLAY_DIR)/includes/displayMapItems.h
$(DISPLAY_DIR)/obj/sortGroundItems.o : $(DISPLAY_DIR)/src/sortGroundItems.c $(DISPLAY_DIR)/includes/sortGroundItems.h
$(DISPLAY_DIR)/obj/initSpriteList.o : $(DISPLAY_DIR)/src/initSpriteList.c $(DISPLAY_DIR)/includes/initSpriteList.h
$(DISPLAY_DIR)/obj/addToSpriteList.o : $(DISPLAY_DIR)/src/addToSpriteList.c $(DISPLAY_DIR)/includes/addToSpriteList.h
$(DISPLAY_DIR)/obj/deleteFromSpriteList.o : $(DISPLAY_DIR)/src/deleteFromSpriteList.c $(DISPLAY_DIR)/includes/deleteFromSpriteList.h
$(DISPLAY_DIR)/obj/deleteSpriteList.o : $(DISPLAY_DIR)/src/deleteSpriteList.c $(DISPLAY_DIR)/includes/deleteSpriteList.h
$(DISPLAY_DIR)/obj/displaySpriteList.o : $(DISPLAY_DIR)/src/displaySpriteList.c $(DISPLAY_DIR)/includes/displaySpriteList.h
$(DISPLAY_DIR)/obj/applyRGBA.o : $(DISPLAY_DIR)/src/applyRGBA.c $(DISPLAY_DIR)/includes/applyRGBA.h
$(DISPLAY_DIR)/obj/blitOnCenter.o : $(DISPLAY_DIR)/src/blitOnCenter.c $(DISPLAY_DIR)/includes/blitOnCenter.h
$(DISPLAY_DIR)/obj/putPixel.o : $(DISPLAY_DIR)/src/putPixel.c $(DISPLAY_DIR)/includes/putPixel.h
$(DISPLAY_DIR)/obj/drawBresenhamCircle.o : $(DISPLAY_DIR)/src/drawBresenhamCircle.c $(DISPLAY_DIR)/includes/drawBresenhamCircle.h
$(DISPLAY_DIR)/obj/drawThickCircle.o : $(DISPLAY_DIR)/src/drawThickCircle.c $(DISPLAY_DIR)/includes/drawThickCircle.h
$(DISPLAY_DIR)/obj/fillHoles.o : $(DISPLAY_DIR)/src/fillHoles.c $(DISPLAY_DIR)/includes/fillHoles.h
$(DISPLAY_DIR)/obj/%.o : $(DISPLAY_DIR)/src/%.c $(DISPLAY_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(MAP_DIR)/obj/loadMap.o : $(MAP_DIR)/src/loadMap.c $(MAP_DIR)/includes/loadMap.h
$(MAP_DIR)/obj/loadYMap.o : $(MAP_DIR)/src/loadYMap.c $(MAP_DIR)/includes/loadYMap.h
$(MAP_DIR)/obj/loadMapLine.o : $(MAP_DIR)/src/loadMapLine.c $(MAP_DIR)/includes/loadMapLine.h
$(MAP_DIR)/obj/loadMapTexture.o : $(MAP_DIR)/src/loadMapTexture.c $(MAP_DIR)/includes/loadMapTexture.h
$(MAP_DIR)/obj/useMapByte.o : $(MAP_DIR)/src/useMapByte.c $(MAP_DIR)/includes/useMapByte.h
$(MAP_DIR)/obj/initMap.o : $(MAP_DIR)/src/initMap.c $(MAP_DIR)/includes/initMap.h
$(MAP_DIR)/obj/addToMapBag.o : $(MAP_DIR)/src/addToMapBag.c $(MAP_DIR)/includes/addToMapBag.h
$(MAP_DIR)/obj/deleteMap.o : $(MAP_DIR)/src/deleteMap.c $(MAP_DIR)/includes/deleteMap.h
$(MAP_DIR)/obj/initMapBag.o : $(MAP_DIR)/src/initMapBag.c $(MAP_DIR)/includes/initMapBag.h
$(MAP_DIR)/obj/initMapItem.o : $(MAP_DIR)/src/initMapItem.c $(MAP_DIR)/includes/initMapItem.h
$(MAP_DIR)/obj/deleteFromMapBag.o : $(MAP_DIR)/src/deleteFromMapBag.c $(MAP_DIR)/includes/deleteFromMapBag.h
$(MAP_DIR)/obj/deleteMapBag.o : $(MAP_DIR)/src/deleteMapBag.c $(MAP_DIR)/includes/deleteMapBag.h
$(MAP_DIR)/obj/deleteMapItem.o : $(MAP_DIR)/src/deleteMapItem.c $(MAP_DIR)/includes/deleteMapItem.h
$(MAP_DIR)/obj/loadMapStructures.o : $(MAP_DIR)/src/loadMapStructures.c $(MAP_DIR)/includes/loadMapStructures.h
$(MAP_DIR)/obj/loadStructureSprite.o : $(MAP_DIR)/src/loadStructureSprite.c $(MAP_DIR)/includes/loadStructureSprite.h
$(MAP_DIR)/obj/loadMapBag.o : $(MAP_DIR)/src/loadMapBag.c $(MAP_DIR)/includes/loadMapBag.h
$(MAP_DIR)/obj/loadMapItem.o : $(MAP_DIR)/src/loadMapItem.c $(MAP_DIR)/includes/loadMapItem.h
$(MAP_DIR)/obj/chooseMapItemAction.o : $(MAP_DIR)/src/chooseMapItemAction.c $(MAP_DIR)/includes/chooseMapItemAction.h
$(MAP_DIR)/obj/loadMapItem.o : $(MAP_DIR)/src/loadMapItem.c $(MAP_DIR)/includes/loadMapItem.h
$(MAP_DIR)/obj/copyToMapBag.o : $(MAP_DIR)/src/copyToMapBag.c $(MAP_DIR)/includes/copyToMapBag.h
$(MAP_DIR)/obj/openMapItemList.o : $(MAP_DIR)/src/openMapItemList.c $(MAP_DIR)/includes/openMapItemList.h
$(MAP_DIR)/obj/searchItemInList.o : $(MAP_DIR)/src/searchItemInList.c $(MAP_DIR)/includes/searchItemInList.h
$(MAP_DIR)/obj/isSameMapItem.o : $(MAP_DIR)/src/isSameMapItem.c $(MAP_DIR)/includes/isSameMapItem.h
$(MAP_DIR)/obj/isItemContainer.o : $(MAP_DIR)/src/isItemContainer.c $(MAP_DIR)/includes/isItemContainer.h
$(MAP_DIR)/obj/%.o : $(MAP_DIR)/src/%.c $(MAP_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(MAP_ITEM_DIR)/obj/sleep.o : $(MAP_ITEM_DIR)/src/sleep.c $(MAP_ITEM_DIR)/includes/sleep.h
$(MAP_ITEM_DIR)/obj/sitOnChair.o : $(MAP_ITEM_DIR)/src/sitOnChair.c $(MAP_ITEM_DIR)/includes/sitOnChair.h
$(MAP_ITEM_DIR)/obj/openItemContainer.o : $(MAP_ITEM_DIR)/src/openItemContainer.c $(MAP_ITEM_DIR)/includes/openItemContainer.h
$(MAP_ITEM_DIR)/obj/%.o : $(MAP_ITEM_DIR)/src/%.c $(MAP_ITEM_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(PLAY_DIR)/obj/triggerKeyUp.o : $(PLAY_DIR)/src/triggerKeyUp.c $(PLAY_DIR)/includes/triggerKeyUp.h
$(PLAY_DIR)/obj/triggerKeyDown.o : $(PLAY_DIR)/src/triggerKeyDown.c $(PLAY_DIR)/includes/triggerKeyDown.h
$(PLAY_DIR)/obj/playGame.o : $(PLAY_DIR)/src/playGame.c $(PLAY_DIR)/includes/playGame.h
$(PLAY_DIR)/obj/triggerAction.o : $(PLAY_DIR)/src/triggerAction.c $(PLAY_DIR)/includes/triggerAction.h
$(PLAY_DIR)/obj/handleMovement.o : $(PLAY_DIR)/src/handleMovement.c $(PLAY_DIR)/includes/handleMovement.h
$(PLAY_DIR)/obj/%.o : $(PLAY_DIR)/src/%.c $(PLAY_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(MOVE_DIR)/obj/go.o : $(MOVE_DIR)/src/go.c $(MOVE_DIR)/includes/go.h
$(MOVE_DIR)/obj/checkAllowedMoves.o : $(MOVE_DIR)/src/checkAllowedMoves.c $(MOVE_DIR)/includes/checkAllowedMoves.h
$(MOVE_DIR)/obj/handlePressedKeys.o : $(MOVE_DIR)/src/handlePressedKeys.c $(MOVE_DIR)/includes/handlePressedKeys.h
$(MOVE_DIR)/obj/checkAllowedMovesOmmit.o : $(MOVE_DIR)/src/checkAllowedMovesOmmit.c $(MOVE_DIR)/includes/checkAllowedMovesOmmit.h
$(MOVE_DIR)/obj/%.o : $(MOVE_DIR)/src/%.c $(MOVE_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(HITBOX_DIR)/obj/initHitbox.o : $(HITBOX_DIR)/src/initHitbox.c $(HITBOX_DIR)/includes/initHitbox.h
$(HITBOX_DIR)/obj/addToHitbox.o : $(HITBOX_DIR)/src/addToHitbox.c $(HITBOX_DIR)/includes/addToHitbox.h
$(HITBOX_DIR)/obj/deleteFromHitbox.o : $(HITBOX_DIR)/src/deleteFromHitbox.c $(HITBOX_DIR)/includes/deleteFromHitbox.h
$(HITBOX_DIR)/obj/deleteHitbox.o : $(HITBOX_DIR)/src/deleteHitbox.c $(HITBOX_DIR)/includes/deleteHitbox.h
$(HITBOX_DIR)/obj/loadHitbox.o : $(HITBOX_DIR)/src/loadHitbox.c $(HITBOX_DIR)/includes/loadHitbox.h
$(HITBOX_DIR)/obj/checkRectIntersection.o : $(HITBOX_DIR)/src/checkRectIntersection.c $(HITBOX_DIR)/includes/checkRectIntersection.h
$(HITBOX_DIR)/obj/getCollisionOrigin.o : $(HITBOX_DIR)/src/getCollisionOrigin.c $(HITBOX_DIR)/includes/getCollisionOrigin.h
$(HITBOX_DIR)/obj/scanIntersection.o : $(HITBOX_DIR)/src/scanIntersection.c $(HITBOX_DIR)/includes/scanIntersection.h
$(HITBOX_DIR)/obj/copyToHitbox.o : $(HITBOX_DIR)/src/copyToHitbox.c $(HITBOX_DIR)/includes/copyToHitbox.h
$(HITBOX_DIR)/obj/isInRect.o : $(HITBOX_DIR)/src/isInRect.c $(HITBOX_DIR)/includes/isInRect.h
$(HITBOX_DIR)/obj/mergeHitboxes.o : $(HITBOX_DIR)/src/mergeHitboxes.c $(HITBOX_DIR)/includes/mergeHitboxes.h
$(HITBOX_DIR)/obj/getHibtoxDimensions.o : $(HITBOX_DIR)/src/getHibtoxDimensions.c $(HITBOX_DIR)/includes/getHibtoxDimensions.h
$(HITBOX_DIR)/obj/getMapHitbox.o : $(HITBOX_DIR)/src/getMapHitbox.c $(HITBOX_DIR)/includes/getMapHitbox.h
$(HITBOX_DIR)/obj/%.o : $(HITBOX_DIR)/src/%.c $(HITBOX_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(LOCATION_DIR)/obj/initLocation.o : $(LOCATION_DIR)/src/initLocation.c $(LOCATION_DIR)/includes/initLocation.h
$(LOCATION_DIR)/obj/setLocationMap.o : $(LOCATION_DIR)/src/setLocationMap.c $(LOCATION_DIR)/includes/setLocationMap.h
$(LOCATION_DIR)/obj/deleteLocation.o : $(LOCATION_DIR)/src/deleteLocation.c $(LOCATION_DIR)/includes/deleteLocation.h
$(LOCATION_DIR)/obj/%.o : $(LOCATION_DIR)/src/%.c $(LOCATION_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(CHARACTER_DIR)/obj/initCharacter.o : $(CHARACTER_DIR)/src/initCharacter.c $(CHARACTER_DIR)/includes/initCharacter.h
$(CHARACTER_DIR)/obj/initTeam.o : $(CHARACTER_DIR)/src/initTeam.c $(CHARACTER_DIR)/includes/initTeam.h
$(CHARACTER_DIR)/obj/deleteCharacter.o : $(CHARACTER_DIR)/src/deleteCharacter.c $(CHARACTER_DIR)/includes/deleteCharacter.h
$(CHARACTER_DIR)/obj/deleteTeam.o : $(CHARACTER_DIR)/src/deleteTeam.c $(CHARACTER_DIR)/includes/deleteTeam.h
$(CHARACTER_DIR)/obj/createTeam.o : $(CHARACTER_DIR)/src/createTeam.c $(CHARACTER_DIR)/includes/createTeam.h
$(CHARACTER_DIR)/obj/loadBaseStats.o : $(CHARACTER_DIR)/src/loadBaseStats.c $(CHARACTER_DIR)/includes/loadBaseStats.h
$(CHARACTER_DIR)/obj/enterMap.o : $(CHARACTER_DIR)/src/enterMap.c $(CHARACTER_DIR)/includes/enterMap.h
$(CHARACTER_DIR)/obj/loadCharacterSprite.o : $(CHARACTER_DIR)/src/loadCharacterSprite.c $(CHARACTER_DIR)/includes/loadCharacterSprite.h
$(CHARACTER_DIR)/obj/updateTeam.o : $(CHARACTER_DIR)/src/updateTeam.c $(CHARACTER_DIR)/includes/updateTeam.h
$(CHARACTER_DIR)/obj/isFacingMapItem.o : $(CHARACTER_DIR)/src/isFacingMapItem.c $(CHARACTER_DIR)/includes/isFacingMapItem.h
$(CHARACTER_DIR)/obj/maxCureTeam.o : $(CHARACTER_DIR)/src/maxCureTeam.c $(CHARACTER_DIR)/includes/maxCureTeam.h
$(CHARACTER_DIR)/obj/putClosedEyes.o : $(CHARACTER_DIR)/src/putClosedEyes.c $(CHARACTER_DIR)/includes/putClosedEyes.h
$(CHARACTER_DIR)/obj/handleStateChange.o : $(CHARACTER_DIR)/src/handleStateChange.c $(CHARACTER_DIR)/includes/handleStateChange.h
$(CHARACTER_DIR)/obj/changeTeamState.o : $(CHARACTER_DIR)/src/changeTeamState.c $(CHARACTER_DIR)/includes/changeTeamState.h
$(CHARACTER_DIR)/obj/standUp.o : $(CHARACTER_DIR)/src/standUp.c $(CHARACTER_DIR)/includes/standUp.h
$(CHARACTER_DIR)/obj/searchStandUpPos.o : $(CHARACTER_DIR)/src/searchStandUpPos.c $(CHARACTER_DIR)/includes/searchStandUpPos.h
$(CHARACTER_DIR)/obj/%.o : $(CHARACTER_DIR)/src/%.c $(CHARACTER_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(MENU_DIR)/obj/prepareExchangeScreen.o : $(MENU_DIR)/src/prepareExchangeScreen.c $(MENU_DIR)/includes/prepareExchangeScreen.h
$(MENU_DIR)/obj/initTabMenu.o : $(MENU_DIR)/src/initTabMenu.c $(MENU_DIR)/includes/initTabMenu.h
$(MENU_DIR)/obj/initTabList.o : $(MENU_DIR)/src/initTabList.c $(MENU_DIR)/includes/initTabList.h
$(MENU_DIR)/obj/initTab.o : $(MENU_DIR)/src/initTab.c $(MENU_DIR)/includes/initTab.h
$(MENU_DIR)/obj/deleteTabMenu.o : $(MENU_DIR)/src/deleteTabMenu.c $(MENU_DIR)/includes/deleteTabMenu.h
$(MENU_DIR)/obj/deleteTabList.o : $(MENU_DIR)/src/deleteTabList.c $(MENU_DIR)/includes/deleteTabList.h
$(MENU_DIR)/obj/deleteTab.o : $(MENU_DIR)/src/deleteTab.c $(MENU_DIR)/includes/deleteTab.h
$(MENU_DIR)/obj/deleteTabEntry.o : $(MENU_DIR)/src/deleteTabEntry.c $(MENU_DIR)/includes/deleteTabEntry.h
$(MENU_DIR)/obj/setTabMenuWidth.o : $(MENU_DIR)/src/setTabMenuWidth.c $(MENU_DIR)/includes/setTabMenuWidth.h
$(MENU_DIR)/obj/setTabMenuHeight.o : $(MENU_DIR)/src/setTabMenuHeight.c $(MENU_DIR)/includes/setTabMenuHeight.h
$(MENU_DIR)/obj/setTabMenuHeaderHeight.o : $(MENU_DIR)/src/setTabMenuHeaderHeight.c $(MENU_DIR)/includes/setTabMenuHeaderHeight.h
$(MENU_DIR)/obj/setTabsPreviewHeight.o : $(MENU_DIR)/src/setTabsPreviewHeight.c $(MENU_DIR)/includes/setTabsPreviewHeight.h
$(MENU_DIR)/obj/putTabMenuBorders.o : $(MENU_DIR)/src/putTabMenuBorders.c $(MENU_DIR)/includes/putTabMenuBorders.h
$(MENU_DIR)/obj/updateItemExchangeHeader.o : $(MENU_DIR)/src/updateItemExchangeHeader.c $(MENU_DIR)/includes/updateItemExchangeHeader.h
$(MENU_DIR)/obj/putTabMenuHeaderBackground.o : $(MENU_DIR)/src/putTabMenuHeaderBackground.c $(MENU_DIR)/includes/putTabMenuHeaderBackground.h
$(MENU_DIR)/obj/updateItemExchangeTabsPreview.o : $(MENU_DIR)/src/updateItemExchangeTabsPreview.c $(MENU_DIR)/includes/updateItemExchangeTabsPreview.h
$(MENU_DIR)/obj/putTabsPreviewSeparation.o : $(MENU_DIR)/src/putTabsPreviewSeparation.c $(MENU_DIR)/includes/putTabsPreviewSeparation.h
$(MENU_DIR)/obj/loadTabPreviewIcon.o : $(MENU_DIR)/src/loadTabPreviewIcon.c $(MENU_DIR)/includes/loadTabPreviewIcon.h
$(MENU_DIR)/obj/putTabContentBackground.o : $(MENU_DIR)/src/putTabContentBackground.c $(MENU_DIR)/includes/putTabContentBackground.h
$(MENU_DIR)/obj/createItemExchangeTabs.o : $(MENU_DIR)/src/createItemExchangeTabs.c $(MENU_DIR)/includes/createItemExchangeTabs.h
$(MENU_DIR)/obj/loadItemExchangeMenuContent.o : $(MENU_DIR)/src/loadItemExchangeMenuContent.c $(MENU_DIR)/includes/loadItemExchangeMenuContent.h
$(MENU_DIR)/obj/loadPotionTab.o : $(MENU_DIR)/src/loadPotionTab.c $(MENU_DIR)/includes/loadPotionTab.h
$(MENU_DIR)/obj/addPotionDataToTab.o : $(MENU_DIR)/src/addPotionDataToTab.c $(MENU_DIR)/includes/addPotionDataToTab.h
$(MENU_DIR)/obj/initTabEntry.o : $(MENU_DIR)/src/initTabEntry.c $(MENU_DIR)/includes/initTabEntry.h
$(MENU_DIR)/obj/addEntryToTab.o : $(MENU_DIR)/src/addEntryToTab.c $(MENU_DIR)/includes/addEntryToTab.h
$(MENU_DIR)/obj/updateTabContent.o : $(MENU_DIR)/src/updateTabContent.c $(MENU_DIR)/includes/updateTabContent.h
$(MENU_DIR)/obj/sortTabDefaultOrder.o : $(MENU_DIR)/src/sortTabDefaultOrder.c $(MENU_DIR)/includes/sortTabDefaultOrder.h
$(MENU_DIR)/obj/getDisplayTabEntry.o : $(MENU_DIR)/src/getDisplayTabEntry.c $(MENU_DIR)/includes/getDisplayTabEntry.h
$(MENU_DIR)/obj/updateItemExchangeMenu.o : $(MENU_DIR)/src/updateItemExchangeMenu.c $(MENU_DIR)/includes/updateItemExchangeMenu.h
$(MENU_DIR)/obj/handleTabMenuEvent.o : $(MENU_DIR)/src/handleTabMenuEvent.c $(MENU_DIR)/includes/handleTabMenuEvent.h
$(MENU_DIR)/obj/gatActiveTab.o : $(MENU_DIR)/src/gatActiveTab.c $(MENU_DIR)/includes/gatActiveTab.h
$(MENU_DIR)/obj/putNoEntryMessage.o : $(MENU_DIR)/src/putNoEntryMessage.c $(MENU_DIR)/includes/putNoEntryMessage.h
$(MENU_DIR)/obj/putItemPreview.o : $(MENU_DIR)/src/putItemPreview.c $(MENU_DIR)/includes/putItemPreview.h
$(MENU_DIR)/obj/loadItemDescription.o : $(MENU_DIR)/src/loadItemDescription.c $(MENU_DIR)/includes/loadItemDescription.h
$(MENU_DIR)/obj/loadArmorTab.o : $(MENU_DIR)/src/loadArmorTab.c $(MENU_DIR)/includes/loadArmorTab.h
$(MENU_DIR)/obj/addBookDataToTab.o : $(MENU_DIR)/src/addBookDataToTab.c $(MENU_DIR)/includes/addBookDataToTab.h
$(MENU_DIR)/obj/loadBookTab.o : $(MENU_DIR)/src/loadBookTab.c $(MENU_DIR)/includes/loadBookTab.h
$(MENU_DIR)/obj/loadWeaponTab.o : $(MENU_DIR)/src/loadWeaponTab.c $(MENU_DIR)/includes/loadWeaponTab.h
$(MENU_DIR)/obj/addWeaponDataToTab.o : $(MENU_DIR)/src/addWeaponDataToTab.c $(MENU_DIR)/includes/addWeaponDataToTab.h
$(MENU_DIR)/obj/%.o : $(MENU_DIR)/src/%.c $(MENU_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(ITEM_DIR)/obj/initItemBag.o : $(ITEM_DIR)/src/initItemBag.c $(ITEM_DIR)/includes/initItemBag.h
$(ITEM_DIR)/obj/deleteItemBag.o : $(ITEM_DIR)/src/deleteItemBag.c $(ITEM_DIR)/includes/deleteItemBag.h
$(ITEM_DIR)/obj/initPotionBag.o : $(ITEM_DIR)/src/initPotionBag.c $(ITEM_DIR)/includes/initPotionBag.h
$(ITEM_DIR)/obj/initPotion.o : $(ITEM_DIR)/src/initPotion.c $(ITEM_DIR)/includes/initPotion.h
$(ITEM_DIR)/obj/deletePotion.o : $(ITEM_DIR)/src/deletePotion.c $(ITEM_DIR)/includes/deletePotion.h
$(ITEM_DIR)/obj/deletePotionBag.o : $(ITEM_DIR)/src/deletePotionBag.c $(ITEM_DIR)/includes/deletePotionBag.h
$(ITEM_DIR)/obj/initArmor.o : $(ITEM_DIR)/src/initArmor.c $(ITEM_DIR)/includes/initArmor.h
$(ITEM_DIR)/obj/deleteArmor.o : $(ITEM_DIR)/src/deleteArmor.c $(ITEM_DIR)/includes/deleteArmor.h
$(ITEM_DIR)/obj/initArmorBag.o : $(ITEM_DIR)/src/initArmorBag.c $(ITEM_DIR)/includes/initArmorBag.h
$(ITEM_DIR)/obj/deleteArmorBag.o : $(ITEM_DIR)/src/deleteArmorBag.c $(ITEM_DIR)/includes/deleteArmorBag.h
$(ITEM_DIR)/obj/initWeapon.o : $(ITEM_DIR)/src/initWeapon.c $(ITEM_DIR)/includes/initWeapon.h
$(ITEM_DIR)/obj/deleteWeapon.o : $(ITEM_DIR)/src/deleteWeapon.c $(ITEM_DIR)/includes/deleteWeapon.h
$(ITEM_DIR)/obj/initWeaponBag.o : $(ITEM_DIR)/src/initWeaponBag.c $(ITEM_DIR)/includes/initWeaponBag.h
$(ITEM_DIR)/obj/deleteWeaponBag.o : $(ITEM_DIR)/src/deleteWeaponBag.c $(ITEM_DIR)/includes/deleteWeaponBag.h
$(ITEM_DIR)/obj/initBook.o : $(ITEM_DIR)/src/initBook.c $(ITEM_DIR)/includes/initBook.h
$(ITEM_DIR)/obj/deleteBook.o : $(ITEM_DIR)/src/deleteBook.c $(ITEM_DIR)/includes/deleteBook.h
$(ITEM_DIR)/obj/initBookBag.o : $(ITEM_DIR)/src/initBookBag.c $(ITEM_DIR)/includes/initBookBag.h
$(ITEM_DIR)/obj/deleteBookBag.o : $(ITEM_DIR)/src/deleteBookBag.c $(ITEM_DIR)/includes/deleteBookBag.h
$(ITEM_DIR)/obj/initMiscItem.o : $(ITEM_DIR)/src/initMiscItem.c $(ITEM_DIR)/includes/initMiscItem.h
$(ITEM_DIR)/obj/deleteMiscItem.o : $(ITEM_DIR)/src/deleteMiscItem.c $(ITEM_DIR)/includes/deleteMiscItem.h
$(ITEM_DIR)/obj/initMiscBag.o : $(ITEM_DIR)/src/initMiscBag.c $(ITEM_DIR)/includes/initMiscBag.h
$(ITEM_DIR)/obj/deleteMiscBag.o : $(ITEM_DIR)/src/deleteMiscBag.c $(ITEM_DIR)/includes/deleteMiscBag.h
$(ITEM_DIR)/obj/loadItemContainerItems.o : $(ITEM_DIR)/src/loadItemContainerItems.c $(ITEM_DIR)/includes/loadItemContainerItems.h
$(ITEM_DIR)/obj/applyHealthPotion.o : $(ITEM_DIR)/src/applyHealthPotion.c $(ITEM_DIR)/includes/applyHealthPotion.h
$(ITEM_DIR)/obj/applyStaminaPotion.o : $(ITEM_DIR)/src/applyStaminaPotion.c $(ITEM_DIR)/includes/applyStaminaPotion.h
$(ITEM_DIR)/obj/applyDurableStaminaPotion.o : $(ITEM_DIR)/src/applyDurableStaminaPotion.c $(ITEM_DIR)/includes/applyDurableStaminaPotion.h
$(ITEM_DIR)/obj/applyDurableHealthPotion.o : $(ITEM_DIR)/src/applyDurableHealthPotion.c $(ITEM_DIR)/includes/applyDurableHealthPotion.h
$(ITEM_DIR)/obj/addToPotionBag.o : $(ITEM_DIR)/src/addToPotionBag.c $(ITEM_DIR)/includes/addToPotionBag.h
$(ITEM_DIR)/obj/addCopyToPotionBag.o : $(ITEM_DIR)/src/addCopyToPotionBag.c $(ITEM_DIR)/includes/addCopyToPotionBag.h
$(ITEM_DIR)/obj/linkPotionAction.o : $(ITEM_DIR)/src/linkPotionAction.c $(ITEM_DIR)/includes/linkPotionAction.h
$(ITEM_DIR)/obj/loadItemBag.o : $(ITEM_DIR)/src/loadItemBag.c $(ITEM_DIR)/includes/loadItemBag.h
$(ITEM_DIR)/obj/loadPotionBag.o : $(ITEM_DIR)/src/loadPotionBag.c $(ITEM_DIR)/includes/loadPotionBag.h
$(ITEM_DIR)/obj/loadPotionData.o : $(ITEM_DIR)/src/loadPotionData.c $(ITEM_DIR)/includes/loadPotionData.h
$(ITEM_DIR)/obj/%.o : $(ITEM_DIR)/src/%.c $(ITEM_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) $(IFLAGS) -c $< -o $@

$(MY_MAIN_MENU_DIR)/obj/putTitleScreen.o : $(MY_MAIN_MENU_DIR)/src/putTitleScreen.c $(MY_MAIN_MENU_DIR)/includes/putTitleScreen.h
$(MY_MAIN_MENU_DIR)/obj/putMainChoices.o : $(MY_MAIN_MENU_DIR)/src/putMainChoices.c $(MY_MAIN_MENU_DIR)/includes/putMainChoices.h
$(MY_MAIN_MENU_DIR)/obj/useMainMenu.o : $(MY_MAIN_MENU_DIR)/src/useMainMenu.c $(MY_MAIN_MENU_DIR)/includes/useMainMenu.h
$(MY_MAIN_MENU_DIR)/obj/moveMainCursor.o : $(MY_MAIN_MENU_DIR)/src/moveMainCursor.c $(MY_MAIN_MENU_DIR)/includes/moveMainCursor.h
$(MY_MAIN_MENU_DIR)/obj/%.o : $(MY_MAIN_MENU_DIR)/src/%.c $(MY_MAIN_MENU_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) -c $< -o $@

$(MY_CHARACTER_CREATION_DIR)/obj/putCCMBoxes.o : $(MY_CHARACTER_CREATION_DIR)/src/putCCMBoxes.c $(MY_CHARACTER_CREATION_DIR)/includes/putCCMBoxes.h
$(MY_CHARACTER_CREATION_DIR)/obj/putCharacterPreview.o : $(MY_CHARACTER_CREATION_DIR)/src/putCharacterPreview.c $(MY_CHARACTER_CREATION_DIR)/includes/putCharacterPreview.h
$(MY_CHARACTER_CREATION_DIR)/obj/putConfirm.o : $(MY_CHARACTER_CREATION_DIR)/src/putConfirm.c $(MY_CHARACTER_CREATION_DIR)/includes/putConfirm.h
$(MY_CHARACTER_CREATION_DIR)/obj/putGender.o : $(MY_CHARACTER_CREATION_DIR)/src/putGender.c $(MY_CHARACTER_CREATION_DIR)/includes/putGender.h
$(MY_CHARACTER_CREATION_DIR)/obj/putName.o : $(MY_CHARACTER_CREATION_DIR)/src/putName.c $(MY_CHARACTER_CREATION_DIR)/includes/putName.h
$(MY_CHARACTER_CREATION_DIR)/obj/putRace.o : $(MY_CHARACTER_CREATION_DIR)/src/putRace.c $(MY_CHARACTER_CREATION_DIR)/includes/putRace.h
$(MY_CHARACTER_CREATION_DIR)/obj/putTeamInfo.o : $(MY_CHARACTER_CREATION_DIR)/src/putTeamInfo.c $(MY_CHARACTER_CREATION_DIR)/includes/putTeamInfo.h
$(MY_CHARACTER_CREATION_DIR)/obj/putUserInfo.o : $(MY_CHARACTER_CREATION_DIR)/src/putUserInfo.c $(MY_CHARACTER_CREATION_DIR)/includes/putUserInfo.h
$(MY_CHARACTER_CREATION_DIR)/obj/useCharacterCreationMenu.o : $(MY_CHARACTER_CREATION_DIR)/src/useCharacterCreationMenu.c $(MY_CHARACTER_CREATION_DIR)/includes/useCharacterCreationMenu.h
$(MY_CHARACTER_CREATION_DIR)/obj/hightlightInfo.o : $(MY_CHARACTER_CREATION_DIR)/src/hightlightInfo.c $(MY_CHARACTER_CREATION_DIR)/includes/hightlightInfo.h
$(MY_CHARACTER_CREATION_DIR)/obj/chooseRace.o : $(MY_CHARACTER_CREATION_DIR)/src/chooseRace.c $(MY_CHARACTER_CREATION_DIR)/includes/chooseRace.h
$(MY_CHARACTER_CREATION_DIR)/obj/chooseConfirm.o : $(MY_CHARACTER_CREATION_DIR)/src/chooseConfirm.c $(MY_CHARACTER_CREATION_DIR)/includes/chooseConfirm.h
$(MY_CHARACTER_CREATION_DIR)/obj/putRaceInfo.o : $(MY_CHARACTER_CREATION_DIR)/src/putRaceInfo.c $(MY_CHARACTER_CREATION_DIR)/includes/putRaceInfo.h
$(MY_CHARACTER_CREATION_DIR)/obj/useRaceMenu.o : $(MY_CHARACTER_CREATION_DIR)/src/useRaceMenu.c $(MY_CHARACTER_CREATION_DIR)/includes/useRaceMenu.h
$(MY_CHARACTER_CREATION_DIR)/obj/putRaces.o : $(MY_CHARACTER_CREATION_DIR)/src/putRaces.c $(MY_CHARACTER_CREATION_DIR)/includes/putRaces.h
$(MY_CHARACTER_CREATION_DIR)/obj/writeName.o : $(MY_CHARACTER_CREATION_DIR)/src/writeName.c $(MY_CHARACTER_CREATION_DIR)/includes/writeName.h
$(MY_CHARACTER_CREATION_DIR)/obj/putConfirm.o : $(MY_CHARACTER_CREATION_DIR)/src/putConfirm.c $(MY_CHARACTER_CREATION_DIR)/includes/putConfirm.h
$(MY_CHARACTER_CREATION_DIR)/obj/prepareConfirmScreen.o : $(MY_CHARACTER_CREATION_DIR)/src/prepareConfirmScreen.c $(MY_CHARACTER_CREATION_DIR)/includes/prepareConfirmScreen.h
$(MY_CHARACTER_CREATION_DIR)/obj/putYesNo.o : $(MY_CHARACTER_CREATION_DIR)/src/putYesNo.c $(MY_CHARACTER_CREATION_DIR)/includes/putYesNo.h
$(MY_CHARACTER_CREATION_DIR)/obj/putCharacterInfo.o : $(MY_CHARACTER_CREATION_DIR)/src/putCharacterInfo.c $(MY_CHARACTER_CREATION_DIR)/includes/putCharacterInfo.h
$(MY_CHARACTER_CREATION_DIR)/obj/confirmCharacterCreation.o : $(MY_CHARACTER_CREATION_DIR)/src/confirmCharacterCreation.c $(MY_CHARACTER_CREATION_DIR)/includes/confirmCharacterCreation.h
$(MY_CHARACTER_CREATION_DIR)/obj/showRaceDescription.o : $(MY_CHARACTER_CREATION_DIR)/src/showRaceDescription.c $(MY_CHARACTER_CREATION_DIR)/includes/showRaceDescription.h
$(MY_CHARACTER_CREATION_DIR)/obj/%.o : $(MY_CHARACTER_CREATION_DIR)/src/%.c $(MY_CHARACTER_CREATION_DIR)/includes/%.h
	$(CC) $(CC_FLAGS) -c $< -o $@

parseFiles : config_parser/src/parse.c $(PARSER_OBJ)
	$(CC) $(CC_FLAGS) $(IFLAGS) $^ -o $@ $(LD_FLAGS)

all : $(EXEC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXEC)

re : fclean all
