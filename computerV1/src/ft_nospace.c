/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nospace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:46:25 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 17:59:26 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
// #include <stdio.h>
char	*ft_attribution(char *rep, char *str, int ts, int tr)
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

int		verif(char *s)
{
	int		i;
	// printf("s: (%s)\n",s );
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] == 'X' && (s[i - 1] == '+' || s[i - 1] == '-'))
			i++;
		else if (s[i - 1] == 'X' && (s[i] == '+' || s[i] == '-'))
			i++;
		else if (s[i] == '=' && s[i - 1] == '=')
			return (0);
			// {printf("error 5 deux egals de suite\n");return (0);}
		else if (s[i] == '/' || s[i] == '%')
			return (0);
			// {printf("error 1 mauvais carac math\n");return (0);}
		else if (s[i] == '*' && (s[i - 1] < '0' || s[i - 1] > '9') &&
			s[i + 1] != 'X')
			return (0);
			// {printf("error 2\n");return (0);}
		
		else if (s[i] == '^' && s[i - 1] != 'X')
			return (0);
			// {printf("error 3\n");return (0);}
		else if (s[i] == 'X' && ft_isnumeric(s[i + 1]) == 1)
			return (0);
			// {printf("error 6\n");return (0);}
		else if (s[i] == 'X' && (s[i - 1] == '*' || // doit etre avant l erreur 4
					(s[i - 1] >= '0' && s[i - 1] <= '9')))
			i++;
		else if (ft_ismath(s[i]) == 1 && ft_ismath(s[i - 1]) == 1
			&& s[i - 1] != '=')
			return (0);
			// {printf("error4: [%c] [%c]\n",s[i-1],s[i]);printf("error 4\n");return (0);}
		
		i++;
	}
	return (1);
}

char	*test_space(char *str, int ts)
{
	if ((str[ts] == 'x' || str[ts] == 'X') && str[ts + 1] == '^' &&
			str[ts + 2] == '0' && ft_isdigit(str[ts + 3]) == 0)
	{
		if (str[ts - 1] == '*')
			str[ts - 1] = ' ';
		str[ts] = ' ';
		str[ts + 1] = ' ';
		str[ts + 2] = ' ';
	}
	return (str);
}

char	*ft_nospace(char *str)
{
	char	*rep;
	int		ts;
	int		tr;

	ts = 0;
	tr = 0;
	while (str[ts] != '\0')
	{
		str = test_space(str, ts);
		if (ft_isspace(str[ts]) == 0 && ft_isdigit(str[ts]) == 0
			&& ft_ismath(str[ts]) == 0)
			return ("\0");
		if (ft_isspace(str[ts]) == 0)
			tr++;
		ts++;
	}
	if ((rep = (char *)malloc(sizeof(char) * (tr + 1))) == NULL)
		return (0);
	ft_attribution(rep, str, 0, tr);
	if (verif(rep) == 0)
	{
		free(rep);
		return ("\0");
	}
	return (rep);
}
