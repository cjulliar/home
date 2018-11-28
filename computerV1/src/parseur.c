/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:40:07 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/28 09:24:49 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <stdio.h>
int		isnumber(char *str, int i, int y, char *n)
{
	if (str[i] == '.')
	{
		i++;
		n[y] = '.';
		y++;
		while (ft_isdigit(str[i]))
		{
			n[y] = str[i];
			y++;
			i++;
		}
		if (str[i] == '.')
		{
			free(n);
			return (-1);
		}
	}
	return (i);
}

int		analyse(char *str, int i, t_values *v)
{
	int		y;
	char	*n;

	if ((n = (char *)malloc(sizeof(char) * (ft_strlen(str)))) == NULL)
		return (0);
	y = 0;
	while (n[y] != '\0')
	{
		n[y] = '\0';
		y++;
	}
	y = 0;
	while (ft_isdigit(str[i]) || (str[i] == '-' && y == 0))
	{
		n[y] = str[i];
		y++;
		i++;
	}
	i = isnumber(str, i, y, n);
	if (i < 0)
		return (i);
	i = isolation(str, i, ft_atoidouble(n), v);
	free(n);
	return (i);
}

int		xalone(char *str, int i, t_values *v) // normer si les if/else devient des if, ca enelve les accolade
{
	int		y;

// printf(" .c%d:%c",i,str[i]);
	if (str[i] == '-')
		i++;
	y = i;
	if (str[i + 1] == '^')
	{
		i += 2;
		while (str[i] == '0' && ft_isnumeric(str[i + 1]) == 1)
			i++;
		if ((str[i] != '1' && str[i] != '0' && str[i] != '2') || ft_isnumeric(str[i + 1]) == 1)
			return (-1);
		if (str[i] == '2')
		{
			if (str[y - 1] == '-')
				v->a -= 1;
			else
				v->a += 1;
		}
		else if (str[i] == '1')
		{
			if (str[y - 1] == '-')
				v->b -= 1;
			else
				v->b += 1;
		}
		else if (str[i] == '0')
		{
			if (str[y - 1] == '-')
				v->c -= 1;
			else
				v->c += 1;
		}
		i++;
	}
	else
	{
		if (str[y - 1] == '-')
			v->b -= 1;
		else
			v->b += 1;
		i++;
	}
// printf(" - c%d:%c. ",i,str[i]);
	return (i - 1);
}

int		firstpart(char *str, int i, t_values *v)
{
	if (str[0] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
// printf(" (%c) ",str[i]);
		if (str[i] == '\0')
			return (0);
		if (str[i] == 'X' || (str[i] == '-' && str[i + 1] == 'X'))
		{
			if ((i = xalone(str, i, v)) == -1)
			{printf("error parseur 6\n");return (-1);}//return (-1);
		}
		else if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str, i, v) - 1;
			if (i < 0)
			{printf("error parseur 7\n");return (i);}//return (i);
		}
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

int		secondpart(char *str, int i, t_values *v)
{
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		//if (str[i] == 'X') delete it si le if apres est comem ca sur firstpart
		if (str[i] == 'X' || (str[i] == '-' && str[i + 1] == 'X'))
		{
			if ((i = xalone(str, i, v)) == -1)
			{printf("error parseur 9\n");return (-1);}//return (-1);
		}
		else if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str, i, v) - 1;
			if (i < 0)
				return (i);
		}
		i++;
	}
	return (i);
}

int		parseur(char *st, t_values *v, t_values *r)
{
	char	*str;
	int		i;

	str = ft_nospace(st);
	i = firstpart(str, 0, v);
	if (i <= 0)
		{printf("\nerror 1er partie parseur\n");return(i);}//return (i);
	i = secondpart(str, i + 1, r);
	if (i <= 0)
		{printf("\nerror 2nd partie parseur\n");return(i);}//return (i);
	free(str);
	return (1);
}
