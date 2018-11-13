#include "libft.h"

int		ft_ismath(char c)
{
	if (c != '-' && c != '+' && c != '*' && c != '/' && c != '%' 
		&& c != 'x' && c != 'X' && c != '.' && c != '^' && c != '=')
		return (0);
	return (1);
}