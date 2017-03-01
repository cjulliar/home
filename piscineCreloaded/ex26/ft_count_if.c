/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:24:02 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/04 13:54:55 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		res;
	int		i;
	int		total;
	int		y;

	y = 0;
	i = 0;
	total = 0;
	res = 0;
	while (tab[y] != '\0')
		y = y + 1;
	while (i < y)
	{
		res = f(tab[i]);
		i = i + 1;
		if (res == 1)
			total = total + 1;
	}
	return (total);
}
