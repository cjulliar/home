#include "libft.h"

void	ft_putdouble(double n)
{
	int		i;

	i = (int)n;
	ft_putnbr(i);
	n = n * 1000000;
	i = ft_abs((int)n % 1000000);
	if (i == 0)
		return ;
	while (i % 10 == 0)
	{
		i = i / 10;
	}
	ft_putchar('.');
	ft_putnbr(i);
}