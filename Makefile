CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -iquote includes\
				 -iquote includes/config\
				 -iquote engine/character/includes\
				 -iquote engine/includes\
				 -iquote engine/music/includes\
				 -iquote engine/save/includes\
				 -iquote engine/play/includes\
				 -iquote engine/location/includes\
				 -iquote engine/map/includes\
				 -iquote engine/move/includes\
				 -iquote engine/menu/includes\
				 -iquote engine/map/map_item_action/includes\
				 -iquote engine/hitbox/includes\
				 -iquote engine/item/includes\
				 -iquote engine/font/includes\
				 -iquote engine/display/includes\
				 -iquote menu/main_menu/includes\
				 -iquote lib/libMY\
				 -iquote menu/character_creation/includes

LD_FLAGS=-Llib/libMY\
				 -lSDL\
				 -lSDL_image\
				 -lSDL_ttf\
				 -lSDL_mixer\
				 -lSDL_gfx\
				 -lMY_string\
				 -lMY_int\
				 -lMY_convert\
				 -lMY_array\
				 -lMY_file

VERSION=v0.0.4

EXEC=myRPG-$(VERSION)

all: $(EXEC)

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C menu clean
	$(MAKE) -C engine clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C lib fclean
	rm -f $(EXEC)

re: fclean $(EXEC)

libs:
	$(MAKE) -C lib all

menu: libs
	$(MAKE) -C menu all

engine: libs menu
	$(MAKE) -C engine all

$(EXEC): objFiles\
	src/main.c\
	includes/main.h
	$(CC) $(CC_FLAGS) src/main.c -o $(EXEC) lib/libMY/libMY_int.a $(MENU_OBJ) $(ENGINE_OBJ) $(LD_FLAGS)

objFiles: libs menu engine

ENGINE_CHARACTER_OBJ=engine/character/changeTeamState.o\
		engine/character/createTeam.o\
		engine/character/deleteCharacter.o\
		engine/character/deleteTeam.o\
		engine/character/enterMap.o\
		engine/character/handleStateChange.o\
		engine/character/initCharacter.o\
		engine/character/initTeam.o\
		engine/character/isFacingMapItem.o\
		engine/character/loadBaseStats.o\
		engine/character/loadCharacterSprite.o\
		engine/character/maxCureTeam.o\
		engine/character/putClosedEyes.o\
		engine/character/searchStandUpPos.o\
		engine/character/standUp.o\
		engine/character/updateTeam.o

ENGINE_DISPLAY_OBJ=engine/display/addToSpriteList.o\
		engine/display/applyRGBA.o\
		engine/display/blitOnCenter.o\
		engine/display/deleteFromSpriteList.o\
		engine/display/deleteSpriteList.o\
		engine/display/displayCharacter.o\
		engine/display/displayHitbox.o\
		engine/display/displayMap.o\
		engine/display/displayMapItems.o\
		engine/display/displaySpriteList.o\
		engine/display/drawBresenhamCircle.o\
		engine/display/drawThickCircle.o\
		engine/display/fillHoles.o\
		engine/display/fillRect.o\
		engine/display/initSpriteList.o\
		engine/display/putPixel.o\
		engine/display/sortGroundItems.o

ENGINE_FONT_OBJ=engine/font/putFont.o\
		engine/font/putFontCenter.o\
		engine/font/putFontColumn.o

ENGINE_HITBOX_OBJ=engine/hitbox/addToHitbox.o\
		engine/hitbox/checkRectIntersection.o\
		engine/hitbox/copyToHitbox.o\
		engine/hitbox/deleteFromHitbox.o\
		engine/hitbox/deleteHitbox.o\
		engine/hitbox/getCollisionOrigin.o\
		engine/hitbox/getHitboxDimensions.o\
		engine/hitbox/getMapHitbox.o\
		engine/hitbox/initHitbox.o\
		engine/hitbox/isInRect.o\
		engine/hitbox/loadHitbox.o\
		engine/hitbox/mergeHitboxes.o\
		engine/hitbox/restrictMovements.o\
		engine/hitbox/scanIntersection.o

ENGINE_ITEM_OBJ=engine/item/addCopyToPotionBag.o\
		engine/item/addToPotionBag.o\
		engine/item/applyDurableHealthPotion.o\
		engine/item/applyDurableStaminaPotion.o\
		engine/item/applyHealthPotion.o\
		engine/item/applyStaminaPotion.o\
		engine/item/deleteArmor.o\
		engine/item/deleteArmorBag.o\
		engine/item/deleteBook.o\
		engine/item/deleteBookBag.o\
		engine/item/deleteItemBag.o\
		engine/item/deleteMiscItem.o\
		engine/item/deleteMiscBag.o\
		engine/item/deletePotion.o\
		engine/item/deletePotionBag.o\
		engine/item/deleteWeapon.o\
		engine/item/deleteWeaponBag.o\
		engine/item/exchangePotion.o\
		engine/item/initArmor.o\
		engine/item/initArmorBag.o\
		engine/item/initBook.o\
		engine/item/initBookBag.o\
		engine/item/initItemBag.o\
		engine/item/initMiscBag.o\
		engine/item/initMiscItem.o\
		engine/item/initPotion.o\
		engine/item/initPotionBag.o\
		engine/item/initWeapon.o\
		engine/item/initWeaponBag.o\
		engine/item/linkPotionAction.o\
		engine/item/loadItemBag.o\
		engine/item/loadItemContainerItems.o\
		engine/item/loadPotionBag.o\
		engine/item/setPotionData.o

ENGINE_LOCATION_OBJ=engine/location/deleteLocation.o\
	engine/location/initLocation.o\
	engine/location/setLocationMap.o

ENGINE_MAP_ITEM_ACTION_OBJ=engine/map/map_item_action/openItemContainer.o\
	engine/map/map_item_action/sitOnChair.o\
	engine/map/map_item_action/sleepInBed.o

ENGINE_MAP_OBJ=engine/map/addToMapBag.o\
		engine/map/chooseMapItemAction.o\
		engine/map/copyToMapBag.o\
		engine/map/deleteFromMapBag.o\
		engine/map/deleteMap.o\
		engine/map/deleteMapBag.o\
		engine/map/deleteMapItem.o\
		engine/map/initMap.o\
		engine/map/initMapBag.o\
		engine/map/initMapItem.o\
		engine/map/isItemContainer.o\
		engine/map/isSameMapItem.o\
		engine/map/loadMap.o\
		engine/map/loadMapBag.o\
		engine/map/loadMapItem.o\
		engine/map/loadMapLine.o\
		engine/map/loadMapStructures.o\
		engine/map/loadMapTexture.o\
		engine/map/loadStructureSprite.o\
		engine/map/loadYMap.o\
		engine/map/openMapItemList.o\
		engine/map/searchItemInList.o\
		engine/map/useMapByte.o

ENGINE_MENU_OBJ=engine/menu/addArmorDataToTab.o\
		engine/menu/addBookDataToTab.o\
		engine/menu/addEntryToTab.o\
		engine/menu/addMiscItemDataToTab.o\
		engine/menu/addPotionDataToTab.o\
		engine/menu/addWeaponDataToTab.o\
		engine/menu/createItemExchangeTabs.o\
		engine/menu/deleteTab.o\
		engine/menu/deleteTabEntry.o\
		engine/menu/deleteTabList.o\
		engine/menu/deleteTabMenu.o\
		engine/menu/getActiveTab.o\
		engine/menu/getDisplayTabEntry.o\
		engine/menu/handleTabMenuEvent.o\
		engine/menu/handleItemExchangeMenuEvent.o\
		engine/menu/initTab.o\
		engine/menu/initTabEntry.o\
		engine/menu/initTabList.o\
		engine/menu/initTabMenu.o\
		engine/menu/loadArmorTab.o\
		engine/menu/loadBookTab.o\
		engine/menu/loadItemDescription.o\
		engine/menu/loadItemExchangeMenuContent.o\
		engine/menu/loadMiscItemTab.o\
		engine/menu/loadPotionTab.o\
		engine/menu/loadTabPreviewIcon.o\
		engine/menu/loadWeaponTab.o\
		engine/menu/prepareExchangeScreen.o\
		engine/menu/putItemPreview.o\
		engine/menu/putNoEntryMessage.o\
		engine/menu/putTabContentBackground.o\
		engine/menu/putTabMenuBorders.o\
		engine/menu/putTabMenuHeaderBackground.o\
		engine/menu/putTabsPreviewSeparation.o\
		engine/menu/setTabMenuHeaderHeight.o\
		engine/menu/setTabMenuHeight.o\
		engine/menu/setTabMenuWidth.o\
		engine/menu/setTabsPreviewHeight.o\
		engine/menu/sortTabDefaultOrder.o\
		engine/menu/updateItemExchangeHeader.o\
		engine/menu/updateItemExchangeMenu.o\
		engine/menu/updateItemExchangeTabsPreview.o\
		engine/menu/updateTabContent.o

ENGINE_MOVE_OBJ=engine/move/checkAllowedMoves.o\
		engine/move/checkAllowedMovesOmmit.o\
		engine/move/go.o\
		engine/move/handlePressedKeys.o

ENGINE_MUSIC_OBJ=engine/music/startPlayingMusic.o\
		engine/music/stopPlayingMusic.o

ENGINE_PLAY_OBJ=engine/play/handleMovement.o\
		engine/play/playGame.o\
		engine/play/triggerAction.o\
		engine/play/triggerKeyDown.o\
		engine/play/triggerKeyUp.o

ENGINE_SAVE_OBJ=engine/save/loadCharacter.o\
		engine/save/loadTeam.o\
		engine/save/saveCharacter.o\
		engine/save/saveTeam.o

ENGINE_OBJ=engine/endSDL.o\
		engine/initEngine.o\
		$(ENGINE_CHARACTER_OBJ)\
		$(ENGINE_DISPLAY_OBJ)\
		$(ENGINE_FONT_OBJ)\
		$(ENGINE_HITBOX_OBJ)\
		$(ENGINE_ITEM_OBJ)\
		$(ENGINE_LOCATION_OBJ)\
		$(ENGINE_MAP_ITEM_ACTION_OBJ)\
		$(ENGINE_MAP_OBJ)\
		$(ENGINE_MENU_OBJ)\
		$(ENGINE_MOVE_OBJ)\
		$(ENGINE_MUSIC_OBJ)\
		$(ENGINE_PLAY_OBJ)\
		$(ENGINE_SAVE_OBJ)

MENU_CHARACTER_CREATION_OBJ=menu/character_creation/chooseConfirm.o\
		menu/character_creation/chooseRace.o\
		menu/character_creation/confirmCharacterCreation.o\
		menu/character_creation/hightlightInfo.o\
		menu/character_creation/prepareConfirmScreen.o\
		menu/character_creation/putCCMBoxes.o\
		menu/character_creation/putCharacterInfo.o\
		menu/character_creation/putCharacterPreview.o\
		menu/character_creation/putConfirm.o\
		menu/character_creation/putGender.o\
		menu/character_creation/putName.o\
		menu/character_creation/putRace.o\
		menu/character_creation/putRaceInfo.o\
		menu/character_creation/putRaces.o\
		menu/character_creation/putTeamInfo.o\
		menu/character_creation/putUserInfo.o\
		menu/character_creation/putYesNo.o\
		menu/character_creation/showRaceDescription.o\
		menu/character_creation/useCharacterCreationMenu.o\
		menu/character_creation/useRaceMenu.o\
		menu/character_creation/writeName.o

MENU_MAIN_MENU_OBJ=menu/main_menu/moveMainCursor.o\
		menu/main_menu/putMainChoices.o\
		menu/main_menu/putTitleScreen.o\
		menu/main_menu/useMainMenu.o

MENU_OBJ=$(MENU_CHARACTER_CREATION_OBJ)\
				 $(MENU_MAIN_MENU_OBJ)
