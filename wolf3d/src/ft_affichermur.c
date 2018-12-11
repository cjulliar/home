/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichermur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:25:42 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 02:23:06 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_carre(t_wolf3d *w, int color, int px, int py)
{
	int		x;
	int		y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_put_pixel(px * 9 + x + 10, py * 9 + y + 10, color, w);
			y++;
		}
		x++;
	}
	px = py;
}

void	ft_affichermap2(t_wolf3d *w, int x, int y)
{
	int		c;

	c = w->map[(int)(w->xposjoueur / HBLOC)][(int)(w->yposjoueur / HBLOC)];
	while (x < w->xmamax)
	{
		y = 0;
		while (y < w->ymamax)
		{
			if (x == (int)(w->xposjoueur / HBLOC) &&
					y == (int)(w->yposjoueur / HBLOC))
				ft_carre(w, 255255255, x, y);
			else if (w->map[x][y] == 1)
				ft_carre(w, 0, x, y);
			else if (w->map[x][y] > 7 && w->tcheat == 1)
				ft_carre(w, 255069000, x, y);
			else if (w->map[x][y] > 1 && w->tcheat == 1)
				ft_carre(w, 255000255, x, y);
			y++;
		}
		x++;
	}
}

void	ft_affichermur(int x, int color, t_wolf3d *w)
{
	int		res;
	int		i;
	int		j;

	res = (int)((HBLOC / w->truedistance) *
			w->f->largeur / 2 * (tan(ft_radian(30))));
	i = w->f->largeur / 2 - res / 2;
	j = w->f->largeur / 2 + res / 2;
	if (i < 0)
		i = 0;
	else if (i > w->f->largeur)
		i = w->f->largeur;
	if (j < 0)
		j = 0;
	else if (j > w->f->largeur)
		j = w->f->largeur;
	while (i < j)
	{
		ft_put_pixel(x, i, color, w);
		i++;
	}
	if (x - w->f->largeur / 2 == 200 && w->hardcord == 0)
		ft_affichermap2(w, 0, 0);
}
