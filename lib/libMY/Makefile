CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c
GEN_HEADERS_EXEC=genHeaders.sh
ALL_LIBS=libMY_array\
				 libMY_convert\
				 libMY_file\
				 libMY_int\
				 libMY_string

all: $(ALL_LIBS)

clean:
	rm -f $(ARRAY_OBJ)\
		$(CONVERT_OBJ)\
		$(FILE_OBJ)\
		$(INT_OBJ)\
		$(STRING_OBJ)

fclean: clean
	rm -f libMY_array.a MY_array.h\
		libMY_convert.a MY_convert.h\
		libMY_file.a MY_file.h\
		libMY_int.a MY_int.h\
		libMY_string.a MY_string.h

re: fclean $(ALL_LIBS)

# Make libMY_array
ARRAY_DIR=libMY_array
ARRAY_OBJ=$(ARRAY_DIR)/MY_free_2d_char.o

libMY_array: libMY_array.a MY_array.h
libMY_array.a: $(ARRAY_OBJ)
	ar rc $@ $(ARRAY_OBJ)
	ranlib $@
MY_array.h:
	/bin/bash $(GEN_HEADERS_EXEC) $(ARRAY_DIR) $@ LIB_MY_ARRAY

$(ARRAY_DIR)/MY_free_2d_char.o: $(ARRAY_DIR)/srcs/MY_free_2d_char.c\
	$(ARRAY_DIR)/includes/MY_free_2d_char.h
	$(CC) $(CC_FLAGS) $< -o $@

# Make libMY_convert
CONVERT_DIR=libMY_convert
CONVERT_OBJ=$(CONVERT_DIR)/MY_dec2str.o\
						$(CONVERT_DIR)/MY_hex2str.o\
						$(CONVERT_DIR)/MY_hex2dec.o\
						$(CONVERT_DIR)/MY_str2hex.o\
						$(CONVERT_DIR)/MY_str2int.o

libMY_convert: libMY_int libMY_convert.a MY_convert.h
libMY_convert.a: $(CONVERT_OBJ)
	ar rc $@ libMY_int/MY_pow.o $(CONVERT_OBJ)
	ranlib $@
MY_convert.h:
	/bin/bash $(GEN_HEADERS_EXEC) $(CONVERT_DIR) $@ LIB_MY_CONVERT

$(CONVERT_DIR)/MY_dec2str.o: $(CONVERT_DIR)/srcs/MY_dec2str.c\
	$(CONVERT_DIR)/includes/MY_dec2str.h
	$(CC) $(CC_FLAGS) $< -o $@
$(CONVERT_DIR)/MY_hex2str.o: $(CONVERT_DIR)/srcs/MY_hex2str.c\
	$(CONVERT_DIR)/includes/MY_hex2str.h
	$(CC) $(CC_FLAGS) $< -o $@
$(CONVERT_DIR)/MY_hex2dec.o: $(CONVERT_DIR)/srcs/MY_hex2dec.c\
	$(CONVERT_DIR)/includes/MY_hex2dec.h
	$(CC) $(CC_FLAGS) $< -o $@
$(CONVERT_DIR)/MY_str2hex.o: $(CONVERT_DIR)/srcs/MY_str2hex.c\
	$(CONVERT_DIR)/includes/MY_str2hex.h
	$(CC) $(CC_FLAGS) $< -o $@
$(CONVERT_DIR)/MY_str2int.o: $(CONVERT_DIR)/srcs/MY_str2int.c\
	$(CONVERT_DIR)/includes/MY_str2int.h
	$(CC) $(CC_FLAGS) $< -o $@

# Make libMY_file
FILE_DIR=libMY_file
FILE_OBJ=$(FILE_DIR)/MY_go_to_next_line.o

libMY_file: libMY_file.a MY_file.h
libMY_file.a: $(FILE_OBJ)
	ar rc $@ $(FILE_OBJ)
	ranlib $@
MY_file.h:
	/bin/bash $(GEN_HEADERS_EXEC) $(FILE_DIR) $@ LIB_MY_FILE

$(FILE_DIR)/MY_go_to_next_line.o: $(FILE_DIR)/srcs/MY_go_to_next_line.c\
	$(FILE_DIR)/includes/MY_go_to_next_line.h
	$(CC) $(CC_FLAGS) $< -o $@

# Make libMY_int
INT_DIR=libMY_int
INT_OBJ=$(INT_DIR)/MY_abs.o\
				$(INT_DIR)/MY_is_pair.o\
				$(INT_DIR)/MY_pow.o

libMY_int: libMY_int.a MY_int.h
libMY_int.a: $(INT_OBJ)
	ar rc $@ $(INT_OBJ)
	ranlib $@
MY_int.h:
	/bin/bash $(GEN_HEADERS_EXEC) $(INT_DIR) $@ LIB_MY_INT

$(INT_DIR)/MY_abs.o: $(INT_DIR)/srcs/MY_abs.c\
	$(INT_DIR)/includes/MY_abs.h
	$(CC) $(CC_FLAGS) $< -o $@
$(INT_DIR)/MY_is_pair.o: $(INT_DIR)/srcs/MY_is_pair.c\
	$(INT_DIR)/includes/MY_is_pair.h
	$(CC) $(CC_FLAGS) $< -o $@
$(INT_DIR)/MY_pow.o: $(INT_DIR)/srcs/MY_pow.c\
	$(INT_DIR)/includes/MY_abs.h
	$(CC) $(CC_FLAGS) $< -o $@

# Make libMY_string
STRING_DIR=libMY_string
STRING_OBJ=$(STRING_DIR)/MY_clear_string.o\
					 $(STRING_DIR)/MY_remove_char.o\
					 $(STRING_DIR)/MY_replace_char.o\
					 $(STRING_DIR)/MY_str_append.o\
					 $(STRING_DIR)/MY_str_capitalize.o\
					 $(STRING_DIR)/MY_str_compare.o\
					 $(STRING_DIR)/MY_str_len.o\
					 $(STRING_DIR)/MY_str_ncopy.o\
					 $(STRING_DIR)/MY_str_replace.o\
					 $(STRING_DIR)/MY_str_split.o\
					 $(STRING_DIR)/MY_str_substr.o\
					 $(STRING_DIR)/MY_str_to_upper.o

libMY_string: libMY_string.a MY_string.h
libMY_string.a: $(STRING_OBJ)
	ar rc $@ $(STRING_OBJ)
	ranlib $@
MY_string.h:
	/bin/bash $(GEN_HEADERS_EXEC) $(STRING_DIR) $@ LIB_MY_STRING

$(STRING_DIR)/MY_clear_string.o: $(STRING_DIR)/srcs/MY_clear_string.c\
	$(STRING_DIR)/includes/MY_clear_string.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_remove_char.o: $(STRING_DIR)/srcs/MY_remove_char.c\
	$(STRING_DIR)/includes/MY_remove_char.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_replace_char.o: $(STRING_DIR)/srcs/MY_replace_char.c\
	$(STRING_DIR)/includes/MY_replace_char.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_append.o: $(STRING_DIR)/srcs/MY_str_append.c\
	$(STRING_DIR)/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_capitalize.o: $(STRING_DIR)/srcs/MY_str_capitalize.c\
	$(STRING_DIR)/includes/MY_str_capitalize.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_compare.o: $(STRING_DIR)/srcs/MY_str_compare.c\
	$(STRING_DIR)/includes/MY_str_compare.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_len.o: $(STRING_DIR)/srcs/MY_str_len.c\
	$(STRING_DIR)/includes/MY_str_len.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_ncopy.o: $(STRING_DIR)/srcs/MY_str_ncopy.c\
	$(STRING_DIR)/includes/MY_str_ncopy.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_replace.o: $(STRING_DIR)/srcs/MY_str_replace.c\
	$(STRING_DIR)/includes/MY_str_replace.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_split.o: $(STRING_DIR)/srcs/MY_str_split.c\
	$(STRING_DIR)/includes/MY_str_split.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_substr.o: $(STRING_DIR)/srcs/MY_str_substr.c\
	$(STRING_DIR)/includes/MY_str_substr.h
	$(CC) $(CC_FLAGS) $< -o $@
$(STRING_DIR)/MY_str_to_upper.o: $(STRING_DIR)/srcs/MY_str_to_upper.c\
	$(STRING_DIR)/includes/MY_str_to_upper.h
	$(CC) $(CC_FLAGS) $< -o $@
