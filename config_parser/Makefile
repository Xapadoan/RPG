CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -iquote includes\
				 -iquote ../lib/libMY/libMY_string/includes\
				 -iquote ../lib/libMY/libMY_array/includes
LD_FLAGS=-L../lib/libMY\
				 -lMY_string\
				 -lMY_array\

OBJ=extendAttributeName.o\
		loadConfFile.o\
		parseFile.o\
		writeConfigFile.o

EXEC=parseConfig

all: $(EXEC)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(EXEC)

re: clean $(EXEC)

$(EXEC): $(OBJ) src/parse.c
	$(CC) $(CC_FLAGS) src/parse.c $(OBJ) -o $@ $(LD_FLAGS)

extendAttributeName.o: src/extendAttributeName.c\
	includes/extendAttributeName.h\
	../lib/libMY/libMY_string/includes/MY_str_len.h\
	../lib/libMY/libMY_string/includes/MY_str_append.h\
	../lib/libMY/libMY_string/includes/MY_str_to_upper.h
	$(CC) $(CC_FLAGS) -c $< -o $@
loadConfFile.o: src/loadConfFile.c\
	includes/loadConfFile.h\
	includes/parseFile.h\
	../lib/libMY/libMY_string/includes/MY_str_compare.h\
	../lib/libMY/libMY_string/includes/MY_str_split.h\
	../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) -c $< -o $@
parseFile.o: src/parseFile.c\
	includes/parseFile.h\
	includes/extendAttributeName.h\
	includes/writeConfigFile.h\
	../lib/libMY/libMY_string/includes/MY_str_len.h\
	../lib/libMY/libMY_string/includes/MY_str_append.h\
	../lib/libMY/libMY_string/includes/MY_str_to_upper.h\
	../lib/libMY/libMY_string/includes/MY_str_split.h\
	../lib/libMY/libMY_string/includes/MY_remove_char.h\
	../lib/libMY/libMY_array/includes/MY_free_2d_char.h
	$(CC) $(CC_FLAGS) -c $< -o $@
writeConfigFile.o: src/writeConfigFile.c\
	includes/writeConfigFile.h\
	../lib/libMY/libMY_string/includes/MY_str_len.h\
	../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) -c $< -o $@
