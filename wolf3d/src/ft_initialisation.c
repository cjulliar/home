/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:11:36 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 03:48:25 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		ft_initjoueur(t_wolf3d *w)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (w->xmamax > 0)
	{
		while (x < w->xmamax && w->map[x][y] == 1)
		{
			x++;
			while (y < w->ymamax && w->map[x][y] == 1)
				y++;
		}
		w->xposjoueur = (double)(x) * HBLOC + 0.4 * HBLOC;
		w->yposjoueur = (double)(y) * HBLOC + 0.4 * HBLOC;
	}
	else
	{
		w->xposjoueur = 200;
		w->yposjoueur = 500;
	}
	w->orientation = 0;
	return (1);
}

int		ft_initialisation(t_wolf3d *w)
{
	if ((w->f = (t_fenetre *)malloc(sizeof(t_fenetre))) == NULL)
		return (0);
	w->hardcord = 0;
	w->tcheat = 0;
	w->level = 1;
	if (ft_lectmap(w) == 0)
		return (0);
	w->f->hauteur = 1000;
	w->f->largeur = 1000;
	w->xmapmax = w->ymamax * HBLOC;
	w->ymapmax = w->ymamax * HBLOC;
	if (ft_initjoueur(w) == 0)
		return (0);
	return (1);
}
