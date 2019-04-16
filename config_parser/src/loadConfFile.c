#include "../includes/loadConfFile.h"

int	loadConfFile(const char *file_name)
{
	char **file_info;
	FILE *src_file;
	FILE *dest_file;
	char *src_file_name;
	char *dest_file_name;

	file_info = NULL;
	src_file = NULL;
	dest_file = NULL;
	src_file_name = NULL;
	dest_file_name = NULL;

	file_info = MY_str_split(file_name, ".");
	if (!MY_str_compare(file_info[1], "config")) {
		fputs("Parse Error : Wrong file extension (.config needed), '", stderr);
		fputs(file_info[1], stderr);
		fputs("' given\n", stderr);
		return (0);
	}

	src_file_name = (char *)calloc(1, (MY_str_len(SRC_CONFIG_PATH) + MY_str_len(file_name) + 1) * sizeof(char));
	dest_file_name = (char *)calloc(1, (MY_str_len(DEST_CONFIG_PATH) + MY_str_len(file_name) + 1) * sizeof(char));
	if (!src_file_name || !dest_file_name) {
		fputs("Memory Error : Malloc failed\n", stderr);
		return (0);
	}
	MY_str_append(src_file_name, SRC_CONFIG_PATH);
	MY_str_append(src_file_name, file_name);

	MY_str_append(dest_file_name, DEST_CONFIG_PATH);
	MY_str_append(dest_file_name, file_info[0]);
	MY_str_append(dest_file_name, ".h");

	src_file = fopen(src_file_name, "r");
	if (!src_file) {
		fputs("File error : Can't open file for reading config\n", stderr);
		return (0);
	}
	dest_file = fopen(dest_file_name, "w");
	if (!dest_file) {
		fputs("File Error : Can't open file for writing config\n", stderr);
		return (0);
	}

	parseFile(src_file, dest_file, file_info[0]);

	free(file_info[0]);
	free(file_info[1]);
	free(file_info);
	free(src_file_name);
	free(dest_file_name);
	fclose(src_file);
	fclose(dest_file);
	return (1);
}
