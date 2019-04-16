#include "../includes/loadConfFile.h"

int	main(int argc, char **argv) {
	int i;

	i = 1;
	while (i < argc)
		loadConfFile(argv[i++]);
	return (0);
}
