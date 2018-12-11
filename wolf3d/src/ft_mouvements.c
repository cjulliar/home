/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:42:29 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 03:50:24 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		ft_tunel(t_wolf3d *w, double jx, double jy)
{
	if (w->map[(int)((jx) / HBLOC)][(int)((jy) / HBLOC)] == 8)
	{
		w->xposjoueur = 1820;
		w->yposjoueur = 150;
		return (1);
	}
	else if (w->map[(int)((jx) / HBLOC)][(int)((jy) / HBLOC)] == 9)
	{
		w->xposjoueur = 880;
		w->yposjoueur = 1450;
		return (1);
	}
	return (0);
}

int		ft_lvlup(t_wolf3d *w, double jx, double jy)
{
	if (w->map[(int)((jx) / HBLOC)][(int)((jy) / HBLOC)] >= 2)
	{
		if (w->map[(int)((jx) / HBLOC)][(int)((jy) / HBLOC)] >= 8)
		{
			if (ft_tunel(w, jx, jy) == 0)
				return (0);
			return (1);
		}
		w->level = w->map[(int)((jx) / HBLOC)][(int)((jy) / HBLOC)];
		w->xposjoueur = 145;
		w->yposjoueur = 145;
		ft_lectmap(w);
		w->orientation = 0;
		return (w->map[(int)((jx) / HBLOC)][(int)((jy) / HBLOC)]);
	}
	return (1);
}

int		ft_mouvements(t_wolf3d *w, int sens)
{
	double	jx;
	double	jy;
	double	cosi;
	double	sinu;

	jx = w->xposjoueur;
	jy = w->yposjoueur;
	cosi = cos(ft_radian(w->orientation)) * sens * 12;
	sinu = sin(ft_radian(w->orientation)) * sens * 12;
	if (jx + cosi > 0 || jx + cosi < 1000)
	{
		if (w->map[(int)((jx + cosi) / HBLOC)][(int)(jy / HBLOC)] != 1)
			w->xposjoueur += cosi;
	}
	if (jy + sinu > 0 || jy + sinu < 1000)
	{
		if (w->map[(int)(jx / HBLOC)][(int)((jy - sinu) / HBLOC)] != 1)
			w->yposjoueur -= sinu;
	}
	return (ft_lvlup(w, w->xposjoueur, w->yposjoueur));
}
