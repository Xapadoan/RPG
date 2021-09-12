CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../item/includes\
				 -iquote ../menu/includes

OBJ=printPotion.o\
		printPotionBag.o\
		printTab.o\
		printTabEntry.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

printPotion.o: src/printPotion.c\
	includes/printPotion.h\
	../item/includes/Potion.h
	$(CC) $(CC_FLAGS) $< -o $@
printPotionBag.o: src/printPotionBag.c\
	includes/printPotionBag.h\
	includes/printPotion.h\
	../item/includes/Potion.h
	$(CC) $(CC_FLAGS) $< -o $@
printTab.o: src/printTab.c\
	includes/printTab.h\
	includes/printTabEntry.h\
	../menu/includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
printTabEntry.o: src/printTabEntry.c\
	includes/printTabEntry.h\
	../menu/includes/TabMenu.h
	$(CC) $(CC_FLAGS) $< -o $@
