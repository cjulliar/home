#include "libft.h"

char *ft_attribution(char *rep, char *str, int ts, int tr)
{
	rep[tr] = '\0';
	tr = 0;
	while (str[ts] != '\0')
	{
		if (ft_isspace(str[ts]) == 0)
		{
			rep[tr] = str[ts];
			tr++;
		}
		ts++;
	}
	return (rep);
}

char *ft_nospace(char *str)
{
	char	*rep;
	int		ts;
	int		tr;

	ts = 0;
	tr = 0;
	while (str[ts] != '\0')
	{
		if (ft_isspace(str[ts]) == 0 && ft_isdigit(str[ts]) == 0 
			&& ft_ismath(str[ts]) == 0)
			return ("");
		if (ft_isspace(str[ts]) == 0)
			tr++;
		ts++;
	}
	if ((rep = (char *)malloc(sizeof(char) * (tr + 1))) == NULL)
		return (0);
	ft_attribution(rep, str, 0, tr);
	return (rep);
}