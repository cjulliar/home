/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:26:54 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 16:56:09 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
// #include <stdio.h>
int		isolation2(char *str, int i, double n, t_values *v)
{
	i += 2;
	while (str[i] == '0' /*&& str[i] != '\0'*/ && ft_isnumeric(str[i + 1]) == 1)
		i++;
	if (ft_isdigit(str[i + 1]) == 1)
		return (-1);
	// printf("[%c] ",str[i]);
	if (str[i] == '2')
		v->a += n;
	else if (str[i] == '1')
		v->b += n;
	else if (str[i] == '0')
		v->c += n;
	else
		return (-1);
	return (i + 1);
}

int		isolation(char *str, int i, double n, t_values *v)
{
	// printf("(%.2f) ",n);
	// printf("[%c] ",str[i]);
	if (str[i] != '*' && str[i] != 'X')
	{
		v->c += n;
		return (i);
	}
	if (str[i] == '*')
		i++;
	// printf("[%c] ",str[i]);
	if (ft_isdigit(str[i]) == 1)
		return (-1);
	// printf("[%c] ",str[i+1]);
	if (str[i + 1] != '^')
	{
		// printf("(%.0f) ",n);
		v->b += n;
		return (i + 1);
	}
	i = isolation2(str, i, n, v);
	// printf(" id:%d ",i);
	// printf("\n");
	return (i);
}
