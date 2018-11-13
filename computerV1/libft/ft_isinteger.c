#include "libft.h"

int		ft_isinteger(double n, int v)
{
	if (n < 0)
		n *= -1;
	if (((int)(n * 1000000) % (1000000 / (ft_puissance(10,v)))) > 0)
		return (0);
	return (1);
}