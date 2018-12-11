/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lectprincipal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:26:31 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/07 16:28:55 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_murenu(t_wolf3d *w)
{
	ft_mverti(0, 0, 19, w);
	ft_mhori(0, 0, 19, w);
	ft_mverti(19, 0, 19, w);
	ft_mhori(0, 19, 19, w);
	if (w->level == 1)
		ft_laby1(w);
	else if (w->level == 2)
		ft_laby2(w);
	else if (w->level == 3)
		ft_laby3(w);
	else if (w->level == 4)
		ft_laby4(w);
	else if (w->level == 5)
		ft_laby1(w);
}

int		ft_lectprincipal(t_wolf3d *w)
{
	int		x;
	int		y;
	int		lim;

	w->ymamax = 20;
	w->xmamax = 20;
	lim = 20;
	if ((w->map = (int **)malloc(sizeof(int *) * lim)) == NULL)
		return (0);
	x = 0;
	while (x < lim)
	{
		if ((w->map[x] = (int *)malloc(sizeof(int) * lim)) == NULL)
			return (0);
		y = 0;
		while (y < lim)
		{
			w->map[x][y] = 0;
			y++;
		}
		x++;
	}
	ft_murenu(w);
	return (1);
}
