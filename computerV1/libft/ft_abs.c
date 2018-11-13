#include "libft.h"

int		ft_abs(int i)
{
	if (i == -2147483648)
		return(2147483647);
	if (i < 0)
		i *= -1;
	return (i);
}