CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../includes

OBJ=endSDL.o\
		initEngine.o

all: $(OBJ)
	$(MAKE) -C character all
	$(MAKE) -C display all
	$(MAKE) -C font all
	$(MAKE) -C hitbox all
	$(MAKE) -C item all
	$(MAKE) -C location all
	$(MAKE) -C map all
	$(MAKE) -C menu all
	$(MAKE) -C move all
	$(MAKE) -C music all
	$(MAKE) -C play all
	$(MAKE) -C save all

clean:
	rm -f $(OBJ)
	$(MAKE) -C character clean
	$(MAKE) -C display clean
	$(MAKE) -C font clean
	$(MAKE) -C hitbox clean
	$(MAKE) -C item clean
	$(MAKE) -C location clean
	$(MAKE) -C map clean
	$(MAKE) -C menu clean
	$(MAKE) -C move clean
	$(MAKE) -C music clean
	$(MAKE) -C play clean
	$(MAKE) -C save clean

re: clean $(OBJ)
	$(MAKE) -C character re
	$(MAKE) -C display re
	$(MAKE) -C font re
	$(MAKE) -C hitbox re
	$(MAKE) -C item re
	$(MAKE) -C location re
	$(MAKE) -C map re
	$(MAKE) -C menu re
	$(MAKE) -C move re
	$(MAKE) -C music re
	$(MAKE) -C play re
	$(MAKE) -C save re

endSDL.o: src/endSDL.c\
	includes/endSDL.h
	$(CC) $(CC_FLAGS) $< -o $@
initEngine.o: src/initEngine.c\
	includes/initEngine.h\
	../includes/config/engine.h
	$(CC) $(CC_FLAGS) $< -o $@
