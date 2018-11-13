#include "libft.h"

double	ft_sqrtdouble(double n)
{
	double x = 1;
	double y = 0.5*(1+n);
	while (ft_absdouble(y-x) > 0.0001)
	{
		x = y;
		y = 0.5 * (x+n/x);
	}
	return (y);
}