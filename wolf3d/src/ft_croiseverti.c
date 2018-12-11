/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_croiseverti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:55:11 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 03:52:43 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

double	ft_exceptionb(t_wolf3d *w, double orientation, double x)
{
	if (orientation == 0)
	{
		w->by = w->yposjoueur;
		w->bx = (int)(w->xposjoueur / HBLOC) * HBLOC + HBLOC;
	}
	else if (orientation == 90 || orientation == 270)
	{
		w->distanceverti = -1;
		return (x);
	}
	else
		ft_putstr("error vertical\n");
	return (x);
}

double	ft_pointb(t_wolf3d *w, double orientation, double x)
{
	if (orientation < 270 && orientation > 90)
	{
		w->bx = ((int)w->xposjoueur / (int)HBLOC) * HBLOC - 0.0001;
		w->by = w->yposjoueur + (w->xposjoueur - w->bx) *
			tan(ft_radian(orientation));
		x = x * -1;
	}
	else if ((orientation > 270 || orientation < 90) && orientation != 0.0
			&& orientation != 360)
	{
		w->bx = ((int)w->xposjoueur / (int)HBLOC) * HBLOC + HBLOC;
		w->by = w->yposjoueur + (w->xposjoueur - w->bx) *
			tan(ft_radian(orientation));
	}
	return (x);
}

void	ft_pointd(t_wolf3d *w, double x, double y)
{
	double	dx;
	double	dy;
	double	px;
	double	py;

	px = w->xposjoueur;
	py = w->yposjoueur;
	w->distanceverti = -2;
	dx = w->bx;
	dy = w->by;
	while (dx > 0 && dx < w->xmapmax && dy > 0 && dy < w->ymapmax &&
			w->map[(int)(dx / HBLOC)][(int)(dy / HBLOC)] != 1)
	{
		if (w->map[(int)(dx / HBLOC)][(int)(dy / HBLOC)] >= 2)
			w->tunel = w->map[(int)(dx / HBLOC)][(int)(dy / HBLOC)];
		dx += x;
		dy += y;
	}
	if (dx <= 0 || dx >= w->xmapmax || dy <= 0 || dy >= w->ymapmax)
		w->distanceverti = -1;
	if (w->distanceverti != -1)
		w->distanceverti = sqrt((px - dx) * (px - dx) + (py - dy) * (py - dy));
}

void	ft_croiseverti(t_wolf3d *w, double orientation)
{
	double	x;
	double	y;

	x = HBLOC;
	if (orientation != 0 && orientation != 180)
		y = (HBLOC * fabs(tan(ft_radian(orientation))));
	else
		y = 0;
	if (orientation > 0 && orientation < 180)
		y *= -1;
	x = ft_pointb(w, orientation, x);
	ft_pointd(w, x, y);
}
