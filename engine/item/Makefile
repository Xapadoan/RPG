CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../lib/libMY\
				 -iquote ../../includes/config\
				 -iquote ../display/includes\
				 -iquote ../character/includes\
				 -iquote ../map/includes\
				 -iquote ../location/includes\
				 -iquote ../hitbox/includes\

OBJ=addCopyToPotionBag.o\
		addToPotionBag.o\
		applyDurableHealthPotion.o\
		applyDurableStaminaPotion.o\
		applyHealthPotion.o\
		applyStaminaPotion.o\
		deleteArmor.o\
		deleteArmorBag.o\
		deleteBook.o\
		deleteBookBag.o\
		deleteItemBag.o\
		deleteMiscItem.o\
		deleteMiscBag.o\
		deletePotion.o\
		deletePotionBag.o\
		deleteWeapon.o\
		deleteWeaponBag.o\
		exchangePotion.o\
		initArmor.o\
		initArmorBag.o\
		initBook.o\
		initBookBag.o\
		initItemBag.o\
		initMiscBag.o\
		initMiscItem.o\
		initPotion.o\
		initPotionBag.o\
		initWeapon.o\
		initWeaponBag.o\
		linkPotionAction.o\
		loadItemBag.o\
		loadItemContainerItems.o\
		loadPotionBag.o\
		setPotionData.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

addCopyToPotionBag.o: src/addCopyToPotionBag.c\
	includes/addCopyToPotionBag.h\
	includes/Potion.h\
	includes/initPotion.h\
	includes/addToPotionBag.h\
	../../includes/config/item.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
addToPotionBag.o: src/addToPotionBag.c\
	includes/addToPotionBag.h\
	includes/Potion.h
	$(CC) $(CC_FLAGS) $< -o $@
applyDurableHealthPotion.o: src/applyDurableHealthPotion.c\
	includes/applyDurableHealthPotion.h\
	includes/Potion.h\
	../character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
applyDurableStaminaPotion.o: src/applyDurableStaminaPotion.c\
	includes/applyDurableStaminaPotion.h\
	includes/Potion.h\
	../character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
applyHealthPotion.o: src/applyHealthPotion.c\
	includes/applyHealthPotion.h\
	includes/Potion.h\
	../character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
applyStaminaPotion.o: src/applyStaminaPotion.c\
	includes/applyStaminaPotion.h\
	includes/Potion.h\
	../character/includes/Character.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteArmor.o: src/deleteArmor.c\
	includes/deleteArmor.h\
	../display/includes/deleteSpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteArmorBag.o: src/deleteArmorBag.c\
	includes/deleteArmorBag.h\
	includes/Armor.h\
	includes/deleteArmor.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteBook.o: src/deleteBook.c\
	includes/deleteBook.h\
	includes/Book.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteBookBag.o: src/deleteBookBag.c\
	includes/deleteBookBag.h\
	includes/Book.h\
	includes/deleteBook.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteItemBag.o: src/deleteItemBag.c\
	includes/deleteItemBag.h\
	includes/ItemBag.h\
	includes/deletePotionBag.h\
	includes/deleteArmorBag.h\
	includes/deleteWeaponBag.h\
	includes/deleteBookBag.h\
	includes/deleteMiscBag.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteMiscBag.o: src/deleteMiscBag.c\
	includes/deleteMiscBag.h\
	includes/MiscItem.h\
	includes/deleteMiscItem.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteMiscItem.o: src/deleteMiscItem.c\
	includes/deleteMiscItem.h\
	includes/MiscItem.h
	$(CC) $(CC_FLAGS) $< -o $@
deletePotion.o: src/deletePotion.c\
	includes/deletePotion.h\
	includes/Potion.h
	$(CC) $(CC_FLAGS) $< -o $@
deletePotionBag.o: src/deletePotionBag.c\
	includes/deletePotionBag.h\
	includes/Potion.h\
	includes/deletePotion.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteWeapon.o: src/deleteWeapon.c\
	includes/deleteWeapon.h\
	includes/Weapon.h\
	../display/includes/deleteSpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
deleteWeaponBag.o: src/deleteWeaponBag.c\
	includes/deleteWeaponBag.h\
	includes/Weapon.h\
	includes/deleteWeapon.h
	$(CC) $(CC_FLAGS) $< -o $@
exchangePotion.o: src/exchangePotion.c\
	includes/exchangePotion.h\
	includes/initPotionBag.h
	$(CC) $(CC_FLAGS) $< -o $@
initArmor.o: src/initArmor.c\
	includes/initArmor.h\
	includes/Armor.h\
	includes/deleteArmor.h\
	../display/includes/initSpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
initArmorBag.o: src/initArmorBag.c\
	includes/initArmorBag.h\
	includes/Armor.h\
	includes/initArmor.h\
	includes/deleteArmorBag.h
	$(CC) $(CC_FLAGS) $< -o $@
initBook.o: src/initBook.c\
	includes/initBook.h\
	includes/Book.h\
	includes/deleteBook.h\
	../../includes/config/item.h
	$(CC) $(CC_FLAGS) $< -o $@
initBookBag.o: src/initBookBag.c\
	includes/initBookBag.h\
	includes/Book.h\
	includes/deleteBookBag.h\
	includes/initBook.h
	$(CC) $(CC_FLAGS) $< -o $@
initItemBag.o: src/initItemBag.c\
	includes/initItemBag.h\
	includes/ItemBag.h\
	includes/initPotionBag.h\
	includes/initWeaponBag.h\
	includes/initArmorBag.h\
	includes/initBookBag.h\
	includes/initMiscBag.h\
	includes/deleteItemBag.h
	$(CC) $(CC_FLAGS) $< -o $@
initMiscBag.o: src/initMiscBag.c\
	includes/initMiscBag.h\
	includes/MiscItem.h\
	includes/deleteMiscBag.h\
	includes/initMiscItem.h
	$(CC) $(CC_FLAGS) $< -o $@
initMiscItem.o: src/initMiscItem.c\
	includes/initMiscItem.h\
	includes/MiscItem.h\
	includes/deleteMiscItem.h\
	../../includes/config/item.h
	$(CC) $(CC_FLAGS) $< -o $@
initPotion.o: src/initPotion.c\
	includes/initPotion.h\
	includes/Potion.h\
	includes/deletePotion.h\
	../../includes/config/item.h
	$(CC) $(CC_FLAGS) $< -o $@
initPotionBag.o: src/initPotionBag.c\
	includes/initPotionBag.h\
	includes/Potion.h\
	includes/deletePotionBag.h\
	includes/initPotion.h
	$(CC) $(CC_FLAGS) $< -o $@
initWeapon.o: src/initWeapon.c\
	includes/initWeapon.h\
	includes/Weapon.h\
	includes/deleteWeapon.h\
	../display/includes/initSpriteList.h
	$(CC) $(CC_FLAGS) $< -o $@
initWeaponBag.o: src/initWeaponBag.c\
	includes/initWeaponBag.h\
	includes/Weapon.h\
	includes/initWeapon.h\
	includes/deleteWeaponBag.h
	$(CC) $(CC_FLAGS) $< -o $@
linkPotionAction.o: src/linkPotionAction.c\
	includes/linkPotionAction.h\
	includes/potionEffects.h
	$(CC) $(CC_FLAGS) $< -o $@
loadItemBag.o: src/loadItemBag.c\
	includes/loadItemBag.h\
	includes/ItemBag.h\
	includes/initItemBag.h\
	includes/loadPotionBag.h\
	includes/item_categories.h\
	../../includes/config/item.h\
	../../lib/libMY/MY_file.h
	$(CC) $(CC_FLAGS) $< -o $@
loadItemContainerItems.o: src/loadItemContainerItems.c\
	includes/loadItemContainerItems.h\
	includes/loadItemBag.h\
	../../includes/config/map_item.h\
	../../includes/config/map.h\
	../../lib/libMY/MY_string.h\
	../../lib/libMY/MY_convert.h\
	../map/includes/Map.h\
	../map/includes/isItemContainer.h
	$(CC) $(CC_FLAGS) $< -o $@
loadPotionBag.o: src/loadPotionBag.c\
	includes/loadPotionBag.h\
	includes/initPotion.h\
	includes/setPotionData.h\
	includes/addCopyToPotionBag.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
setPotionData.o: src/setPotionData.c\
	includes/setPotionData.h\
	includes/potionEffects.h\
	includes/linkPotionAction.h\
	../../lib/libMY/MY_array.h\
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
