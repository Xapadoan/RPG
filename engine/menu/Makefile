CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../lib/libMY\
				 -iquote ../../includes/config\
				 -iquote ../item/includes\
				 -iquote ../character/includes\
				 -iquote ../font/includes\
				 -iquote ../display/includes\
				 -iquote ../map/includes\
				 -iquote ../location/includes\
				 -iquote ../hitbox/includes\
				 -iquote ../includes

OBJ=addArmorDataToTab.o\
		addBookDataToTab.o\
		addEntryToTab.o\
		addMiscItemDataToTab.o\
		addPotionDataToTab.o\
		addWeaponDataToTab.o\
		createItemExchangeTabs.o\
		deleteTab.o\
		deleteTabEntry.o\
		deleteTabList.o\
		deleteTabMenu.o\
		getActiveTab.o\
		getDisplayTabEntry.o\
		handleTabMenuEvent.o\
		handleItemExchangeMenuEvent.o\
		initTab.o\
		initTabEntry.o\
		initTabList.o\
		initTabMenu.o\
		loadArmorTab.o\
		loadBookTab.o\
		loadItemDescription.o\
		loadMiscItemTab.o\
		loadPotionTab.o\
		loadTabPreviewIcon.o\
		loadWeaponTab.o\
		prepareExchangeScreen.o\
		putItemPreview.o\
		putNoEntryMessage.o\
		putTabContentBackground.o\
		putTabMenuBorders.o\
		putTabMenuHeaderBackground.o\
		putTabsPreviewSeparation.o\
		setTabMenuHeaderHeight.o\
		setTabMenuHeight.o\
		setTabMenuWidth.o\
		setTabsPreviewHeight.o\
		sortTabDefaultOrder.o\
		updateItemExchangeHeader.o\
		updateItemExchangeMenu.o\
		updateItemExchangeTabsPreview.o\
		loadItemExchangeMenuContent.o\
		updateTabContent.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

addArmorDataToTab.o: src/addArmorDataToTab.c\
	includes/addArmorDataToTab.h\
	includes/TabMenu.h\
	includes/tab_ids.h\
	includes/addEntryToTab.h\
	includes/initTabEntry.h\
	includes/loadItemDescription.h\
	../item/includes/item_categories.h\
	../item/includes/Armor.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../font/includes/putFont.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h
	$(CC) $(CC_FLAGS) $< -o $@
addBookDataToTab.o: src/addBookDataToTab.c\
	includes/addBookDataToTab.h\
	includes/TabMenu.h\
	includes/tab_ids.h\
	includes/addEntryToTab.h\
	includes/initTabEntry.h\
	includes/loadItemDescription.h\
	../item/includes/Book.h\
	../item/includes/item_categories.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../font/includes/putFont.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h
	$(CC) $(CC_FLAGS) $< -o $@
addEntryToTab.o: src/addEntryToTab.c\
	includes/addEntryToTab.h\
	includes/TabMenu.h\
	includes/sortTabDefaultOrder.h
	$(CC) $(CC_FLAGS) $< -o $@
addMiscItemDataToTab.o: src/addMiscItemDataToTab.c\
	includes/addMiscItemDataToTab.h\
	includes/TabMenu.h\
	includes/tab_ids.h\
	includes/addEntryToTab.h\
	includes/initTabEntry.h\
	includes/loadItemDescription.h\
	../item/includes/MiscItem.h\
	../item/includes/item_categories.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../font/includes/putFont.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h
	$(CC) $(CC_FLAGS) $< -o $@
addPotionDataToTab.o: src/addPotionDataToTab.c\
	includes/addPotionDataToTab.h\
	includes/TabMenu.h\
	includes/tab_ids.h\
	includes/addEntryToTab.h\
	includes/initTabEntry.h\
	includes/loadItemDescription.h\
	../item/includes/Potion.h\
	../item/includes/exchangePotion.h\
	../item/includes/item_categories.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../font/includes/putFont.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h\
	../includes/FnctPtr.h
	$(CC) $(CC_FLAGS) $< -o $@
addWeaponDataToTab.o: src/addWeaponDataToTab.c\
	includes/addWeaponDataToTab.h\
	includes/TabMenu.h\
	includes/tab_ids.h\
	includes/addEntryToTab.h\
	includes/initTabEntry.h\
	includes/loadItemDescription.h\
	../item/includes/Weapon.h\
	../item/includes/item_categories.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../font/includes/putFont.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h
	$(CC) $(CC_FLAGS) $< -o $@
createItemExchangeTabs.o: src/createItemExchangeTabs.c\
	includes/createItemExchangeTabs.h\
	includes/tab_ids.h\
	includes/TabMenu.h\
	includes/initTab.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteTab.o: src/deleteTab.c\
	includes/deleteTab.h\
	includes/tab_ids.h\
	includes/TabMenu.h\
	includes/deleteTabEntry.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteTabEntry.o: src/deleteTabEntry.c\
	includes/deleteTabEntry.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteTabList.o: src/deleteTabList.c\
	includes/deleteTabList.h\
	includes/TabMenu.h\
	includes/deleteTab.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteTabMenu.o: src/deleteTabMenu.c\
	includes/deleteTabMenu.h\
	includes/TabMenu.h\
	includes/deleteTabList.h
	$(CC) $(CC_FLAGS) $< -o $@
getActiveTab.o: src/getActiveTab.c\
	includes/getActiveTab.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
getDisplayTabEntry.o: src/getDisplayTabEntry.c\
	includes/getDisplayTabEntry.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
handleTabMenuEvent.o: src/handleTabMenuEvent.c\
	includes/handleTabMenuEvent.h\
	includes/TabMenu.h\
	includes/getActiveTab.h\
	includes/getDisplayTabEntry.h\
	../../includes/config/controls.h
	$(CC) $(CC_FLAGS) $< -o $@
handleItemExchangeMenuEvent.o: src/handleItemExchangeMenuEvent.c\
	includes/handleItemExchangeMenuEvent.h\
	includes/TabMenu.h\
	includes/getActiveTab.h\
	includes/getDisplayTabEntry.h\
	../item/includes/item_categories.h\
	../item/includes/Potion.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h
	$(CC) $(CC_FLAGS) $< -o $@
initTab.o: src/initTab.c\
	includes/initTab.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
initTabEntry.o: src/initTabEntry.c\
	includes/initTabEntry.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
initTabList.o: src/initTabList.c\
	includes/initTabList.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
initTabMenu.o: src/initTabMenu.c\
	includes/initTabMenu.h\
	includes/TabMenu.h\
	includes/initTabList.h
	$(CC) $(CC_FLAGS) $< -o $@
loadArmorTab.o: src/loadArmorTab.c\
	includes/loadArmorTab.h\
	includes/TabMenu.h\
	includes/addArmorDataToTab.h\
	../item/includes/Armor.h
	$(CC) $(CC_FLAGS) $< -o $@
loadBookTab.o: src/loadBookTab.c\
	includes/loadBookTab.h\
	includes/TabMenu.h\
	includes/addBookDataToTab.h\
	../item/includes/Book.h
	$(CC) $(CC_FLAGS) $< -o $@
loadItemDescription.o: src/loadItemDescription.c\
	includes/loadItemDescription.h\
	includes/TabMenu.h\
	includes/putItemPreview.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_array.h\
	../font/includes/putFontCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
loadItemExchangeMenuContent.o: src/loadItemExchangeMenuContent.c\
	includes/loadItemExchangeMenuContent.h\
	includes/TabMenu.h\
	includes/loadPotionTab.h\
	includes/loadArmorTab.h\
	includes/loadBookTab.h\
	includes/loadMiscItemTab.h\
	includes/loadWeaponTab.h\
	../item/includes/ItemBag.h
	$(CC) $(CC_FLAGS) $< -o $@
loadMiscItemTab.o: src/loadMiscItemTab.c\
	includes/loadMiscItemTab.h\
	includes/TabMenu.h\
	includes/addMiscItemDataToTab.h\
	../item/includes/MiscItem.h
	$(CC) $(CC_FLAGS) $< -o $@
loadPotionTab.o: src/loadPotionTab.c\
	includes/loadPotionTab.h\
	includes/TabMenu.h\
	includes/addPotionDataToTab.h\
	../item/includes/Potion.h
	$(CC) $(CC_FLAGS) $< -o $@
loadTabPreviewIcon.o: src/loadTabPreviewIcon.c\
	includes/loadTabPreviewIcon.h\
	../../includes/config/menu.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
loadWeaponTab.o: src/loadWeaponTab.c\
	includes/loadWeaponTab.h\
	includes/TabMenu.h\
	includes/addWeaponDataToTab.h\
	../item/includes/Weapon.h
	$(CC) $(CC_FLAGS) $< -o $@
prepareExchangeScreen.o: src/prepareExchangeScreen.c\
	includes/prepareExchangeScreen.h\
	../../includes/config/map_item.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h\
	../map/includes/Map.h\
	../display/includes/applyRGBA.h\
	../display/includes/blitOnCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
putItemPreview.o: src/putItemPreview.c\
	includes/putItemPreview.h\
	../../includes/config/menu.h\
	../../includes/config/item.h\
	../item/includes/item_categories.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_int.h\
	../../lib/libMY/MY_convert.h\
	../../lib/libMY/MY_array.h
	$(CC) $(CC_FLAGS) $< -o $@
putNoEntryMessage.o: src/putNoEntryMessage.c\
	includes/putNoEntryMessage.h\
	includes/TabMenu.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../font/includes/putFontCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
putTabContentBackground.o: src/putTabContentBackground.c\
	includes/putTabContentBackground.h\
	includes/TabMenu.h\
	../../includes/config/menu.h\
	../display/includes/drawThickCircle.h\
	../display/includes/circle_portions.h
	$(CC) $(CC_FLAGS) $< -o $@
putTabMenuBorders.o: src/putTabMenuBorders.c\
	includes/putTabMenuBorders.h\
	includes/TabMenu.h\
	../../includes/config/menu.h\
	../display/includes/drawThickCircle.h\
	../display/includes/circle_portions.h
	$(CC) $(CC_FLAGS) $< -o $@
putTabMenuHeaderBackground.o: src/putTabMenuHeaderBackground.c\
	includes/putTabMenuHeaderBackground.h\
	includes/TabMenu.h\
	../../includes/config/menu.h\
	../display/includes/drawThickCircle.h
	$(CC) $(CC_FLAGS) $< -o $@
putTabsPreviewSeparation.o: src/putTabsPreviewSeparation.c\
	includes/putTabsPreviewSeparation.h\
	includes/TabMenu.h\
	../../includes/config/menu.h\
	../display/includes/drawBresenhamCircle.h
	$(CC) $(CC_FLAGS) $< -o $@
setTabMenuHeaderHeight.o: src/setTabMenuHeaderHeight.c\
	includes/setTabMenuHeaderHeight.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
setTabMenuHeight.o: src/setTabMenuHeight.c\
	includes/setTabMenuHeight.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
setTabMenuWidth.o: src/setTabMenuWidth.c\
	includes/setTabMenuWidth.h\
	includes/TabMenu.h\
	../../includes/config/menu.h
	$(CC) $(CC_FLAGS) $< -o $@
setTabsPreviewHeight.o: src/setTabsPreviewHeight.c\
	includes/setTabsPreviewHeight.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
sortTabDefaultOrder.o: src/sortTabDefaultOrder.c\
	includes/sortTabDefaultOrder.h\
	includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
updateItemExchangeHeader.o: src/updateItemExchangeHeader.c\
	includes/updateItemExchangeHeader.h\
	includes/TabMenu.h\
	includes/putTabMenuHeaderBackground.h\
	../../includes/config/menu.h\
	../../includes/config/font.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h\
	../item/includes/ItemBag.h\
	../font/includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
updateItemExchangeMenu.o: src/updateItemExchangeMenu.c\
	includes/updateItemExchangeMenu.h\
	includes/TabMenu.h\
	includes/putTabMenuBorders.h\
	includes/updateItemExchangeHeader.h\
	includes/updateItemExchangeTabsPreview.h\
	includes/updateTabContent.h\
	../map/includes/Map.h
	$(CC) $(CC_FLAGS) $< -o $@
updateItemExchangeTabsPreview.o: src/updateItemExchangeTabsPreview.c\
	includes/updateItemExchangeTabsPreview.h\
	includes/tab_ids.h\
	includes/TabMenu.h\
	includes/putTabsPreviewSeparation.h\
	includes/loadTabPreviewIcon.h\
	../../includes/config/menu.h
	$(CC) $(CC_FLAGS) $< -o $@
updateTabContent.o: src/updateTabContent.c\
	includes/updateTabContent.h\
	includes/TabMenu.h\
	includes/putTabContentBackground.h\
	includes/getDisplayTabEntry.h\
	includes/getActiveTab.h\
	includes/putNoEntryMessage.h\
	../../includes/config/menu.h
	$(CC) $(CC_FLAGS) $< -o $@
