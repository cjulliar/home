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

	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] == '/' || s[i] == '%')
			return (0);
		else if (s[i] == '*' && (s[i - 1] < '0' || s[i - 1] > '9'))
			return (0);
		else if ((s[i] == 'x' || s[i] == 'X') && (s[i - 1] == '*' ||
					(s[i - 1] >= '0' && s[i - 1] <= '9')))
			i++;
		else if (s[i] == '^' && (s[i - 1] != 'X' || s[i - 1] != 'x'))
			return (0);
		else if (ft_ismath(s[i]) == 1 && ft_ismath(s[i - 1]) == 1)
			return (0);
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
			return ("");
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
		return ("");
	}
	return (rep);
}
