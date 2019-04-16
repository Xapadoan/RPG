#include "../includes/MY_pow.h"

int	MY_pow(int val, int pow){
	int i = 0;
	int res = 1;

	while (++i < pow)
		res *= val;

	return (res);
}
