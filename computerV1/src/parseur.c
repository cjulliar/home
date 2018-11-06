/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:40:07 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/06 09:49:17 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <stdio.h>

int		is_num(char c)
{
	printf("test [%c]\t",c);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		parseur(char *str, t_values *v)
{
	int		i;
	int		ib;
	int		y;
	char	*n;
	n = (char *)malloc(sizeof(char) * (ft_strlen(str)));
printf("%s\n",str);v->a=0;
	i = 0;
	while(str[i] != '\0')
	{
		printf("%d - %c\t",i,str[i]);
		if (is_num(str[i]) == 0)
		{
			printf("%d - %c\t",i,str[i]);
			ib = i;
			y = 0;
			while(is_num(str[ib]) == 1)
			{
				n[y] = str[ib];
				y++;
				ib++;
			}
			printf("%s\t",n);
			
		}
		
		printf("\n");
		i++;
	}

	return (1);
}
