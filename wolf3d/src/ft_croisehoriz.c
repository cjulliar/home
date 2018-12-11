/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_croisehoriz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:41:25 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 01:27:55 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

double	ft_exceptiona(t_wolf3d *w, double orientation, double y)
{
	if (orientation == 270)
	{
		w->ax = w->xposjoueur;
		w->ay = (int)(w->yposjoueur / HBLOC) * HBLOC + HBLOC;
	}
	else if (orientation == 0 || orientation == 360)
	{
		w->distancehoriz = -1;
		return (y);
	}
	else if (orientation == 180)
	{
		w->distancehoriz = -1;
		return (y);
	}
	else
		ft_putendl("error horizontal");
	return (y);
}

double	ft_pointa(t_wolf3d *w, double orientation, double y)
{
	if (orientation < 180.0 && orientation > 0.0)
	{
		w->ay = ((int)w->yposjoueur / (int)HBLOC) * HBLOC - 0.0001;
		w->ax = w->xposjoueur + (w->yposjoueur - w->ay) /
			tan(ft_radian(orientation));
		y = y * -1;
	}
	else if (orientation > 180.0 && orientation < 360 && orientation != 270.0)
	{
		w->ay = ((int)w->yposjoueur / (int)HBLOC) * HBLOC + HBLOC;
		w->ax = w->xposjoueur + (w->yposjoueur - w->ay) /
			tan(ft_radian(orientation));
	}
	else
		ft_exceptiona(w, orientation, y);
	return (y);
}

void	ft_pointc(t_wolf3d *w, double x, double y)
{
	double	px;
	double	py;
	double	cx;
	double	cy;

	px = w->xposjoueur;
	py = w->yposjoueur;
	cx = w->ax;
	cy = w->ay;
	w->distancehoriz = -2;
	while (cx > 0 && cx < w->xmapmax && cy > 0 && cy < w->ymapmax &&
			w->map[(int)(cx / HBLOC)][(int)(cy / HBLOC)] != 1)
	{
		if (w->map[(int)(cx / HBLOC)][(int)(cy / HBLOC)] >= 2)
			w->tunel10 = w->map[(int)(cx / HBLOC)][(int)(cy / HBLOC)] * 10;
		cx += x;
		cy += y;
	}
	if (cx < 0 || cx > w->xmapmax || cy < 0 || cy > w->ymapmax)
		w->distancehoriz = -1;
	else
		w->distancehoriz = sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));
}

void	ft_croisehoriz(t_wolf3d *w, double orientation)
{
	double	x;
	double	y;

	y = HBLOC;
	if (orientation != 90 && orientation != 270)
		x = (HBLOC / fabs(tan(ft_radian(orientation))));
	else
		x = 0;
	if (orientation > 90 && orientation < 270)
		x *= -1;
	y = ft_pointa(w, orientation, y);
	ft_pointc(w, x, y);
}
