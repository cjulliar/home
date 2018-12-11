/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_premieraffichage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:04:05 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 03:19:25 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_couleurpassage2(t_wolf3d *w)
{
	if (w->tunel == 1 || w->tunel == 5)
		w->color = 255215000;
	else if (w->tunel == 2)
		w->color = 220020060;
	else if (w->tunel == 3)
		w->color = 128000;
	else if (w->tunel == 4)
		w->color = 199021133;
	else
		w->color = 0;
}

void	ft_couleurpassage(t_wolf3d *w)
{
	if (w->tunel10 > 0 && w->distancehoriz == w->truedistance)
	{
		if (w->tunel10 / 10 == 1 || w->tunel10 / 10 == 5)
			w->color = 255215000;
		else if (w->tunel10 / 10 == 2)
			w->color = 220020060;
		else if (w->tunel10 / 10 == 3)
			w->color = 128000;
		else if (w->tunel10 / 10 == 4)
			w->color = 199021133;
		else
			w->color = 0;
	}
	else if (w->tunel > 0 && w->distanceverti == w->truedistance)
		ft_couleurpassage2(w);
}

void	ft_choixcouleur(t_wolf3d *w, double ori)
{
	if ((w->distancehoriz < w->distanceverti && w->distancehoriz != -1) ||
			(w->distanceverti == -1 && w->distancehoriz != -1))
	{
		if (ori > 180)
			w->color = ft_palette(w, 1);
		else
			w->color = ft_palette(w, 2);
		w->truedistance = w->distancehoriz;
	}
	else if ((w->distancehoriz > w->distanceverti && w->distanceverti != -1) ||
			(w->distancehoriz == -1 && w->distanceverti != -1) ||
			(w->distanceverti == w->distanceverti && w->distancehoriz != -1))
	{
		if (ori > 270 || ori < 90)
			w->color = ft_palette(w, 3);
		else
			w->color = ft_palette(w, 4);
		w->truedistance = w->distanceverti;
	}
}

double	ft_gestionangle(double orientation)
{
	while (orientation < 0 || orientation >= 360)
	{
		if (orientation < 0)
			orientation += 360;
		else
			orientation -= 360;
	}
	if (orientation == 360)
		orientation = 0;
	return (orientation);
}

void	ft_premieraffichage(t_wolf3d *w)
{
	double	i;
	double	orientation;
	int		res;

	i = w->f->largeur / -2;
	while (i < w->f->largeur / 2)
	{
		w->tunel = 0;
		w->tunel10 = 0;
		orientation = w->orientation + (30 * i) / (w->f->largeur / 2);
		orientation = ft_gestionangle(orientation);
		ft_croisehoriz(w, orientation);
		ft_croiseverti(w, orientation);
		ft_choixcouleur(w, orientation);
		ft_couleurpassage(w);
		res = (int)((HBLOC / w->truedistance) * (w->f->largeur / 2 /
					(tan(ft_radian(30)))));
		w->truedistance = w->truedistance * cos(ft_radian((30 * i) /
					(w->f->largeur / 2)));
		ft_affichermur(i + w->f->largeur / 2, w->color, w);
		i++;
	}
}
