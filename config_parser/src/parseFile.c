#include "../includes/parseFile.h"

int	parseFile(FILE *src_file, FILE *dest_file, const char *file_name)
{
	char *attribute_name;
	char line[81];
	char **array_line;
	char *dest_line;

	attribute_name = NULL;
	array_line = NULL;
	dest_line = NULL;

	putIntro(dest_file, file_name);

	attribute_name = (char *)calloc(1, (MY_str_len(file_name) + 2) * sizeof(char));
	if (!attribute_name) {
		fputs("Memory Error : Malloc failed\n", stderr);
		return (0);
	}
	MY_str_append(attribute_name, file_name);
	MY_str_append(attribute_name, "_");

	while (fgets(line, 80, src_file)) {
		array_line = MY_str_split(line, ": ");
		if (line[0] == '\n') {
			free(attribute_name);
			attribute_name = NULL;
			attribute_name = (char *)calloc(1, (MY_str_len(file_name) + 2) * sizeof(char));
			if (!attribute_name) {
				fputs("Memory Error : Malloc failed\n", stderr);
				return (0);
			}
			MY_str_append(attribute_name, file_name);
			MY_str_to_upper(attribute_name);
			MY_str_append(attribute_name, "_");
		} else if (array_line[1] == '\0' && array_line[0][MY_str_len(array_line[0]) - 2] == ':') {
			//If line is like "attribute_details:\n"
			attribute_name = extendAttributeName(attribute_name, array_line[0]);
		} else {
			//If line is like "attribute_final_details: attribute_value\n"
			dest_line = (char *)calloc(1, (MY_str_len(attribute_name) + MY_str_len(array_line[0]) + MY_str_len(array_line[1]) + 3) * sizeof(char));
			MY_str_append(dest_line, attribute_name);
			array_line[0] = MY_remove_char(array_line[0], '\t', 1);
			MY_str_append(dest_line, array_line[0]);
			MY_str_to_upper(dest_line);
			MY_str_append(dest_line, " ");
			MY_str_append(dest_line, array_line[1]);
			writeConfigFile(dest_file, dest_line);
			free(dest_line);
			dest_line = NULL;
		}
		MY_free_2d_char(array_line);
	}
	free(attribute_name);

	fputs("\n", dest_file);
	fputs("#endif", dest_file);

	return (0);
}

void	putIntro(FILE *file, const char *file_name)
{
	char *dest_line;
	char *attribute;

	dest_line = NULL;
	attribute = NULL;

	attribute = (char *)calloc(1, (MY_str_len(file_name) + 2) * sizeof(char));
	MY_str_append(attribute, file_name);
	MY_str_to_upper(attribute);
	MY_str_append(attribute, "\n");

	//Will contain "#ifndef DEF_CST_FILE_NAME\n"
	dest_line = (char *)calloc(1, (MY_str_len(file_name) + 18) * sizeof(char));
	MY_str_append(dest_line, "#ifndef DEF_CST_");
	MY_str_append(dest_line, attribute);
	fputs(dest_line, file);

	free(dest_line);
	dest_line = NULL;
	dest_line = (char *)calloc(1, (MY_str_len(file_name) + 18) * sizeof(char));
	MY_str_append(dest_line, "#define DEF_CST_");
	MY_str_append(dest_line, attribute);
	fputs(dest_line, file);
	free(dest_line);
	dest_line = NULL;
	free(attribute);

	fputs("\n", file);
}
