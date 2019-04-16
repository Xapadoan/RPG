#include "../includes/MY_abs.h"

unsigned int	MY_abs(int nb) {
	if (nb > 0)
		return (nb);
	else
		return ((-1) * nb);
}
