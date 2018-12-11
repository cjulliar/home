/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_laby3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:24:09 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/07 11:10:17 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_lab3fin(t_wolf3d *w)
{
	ft_mverti(15, 8, 10, w);
	ft_mverti(15, 12, 15, w);
	w->map[15][6] = 1;
	ft_mhori(4, 5, 7, w);
	ft_mhori(9, 5, 15, w);
	w->map[11][6] = 1;
	w->map[16][9] = 1;
	ft_mhori(6, 7, 13, w);
	w->map[6][8] = 1;
	ft_mverti(13, 7, 13, w);
	ft_mhori(9, 13, 13, w);
	w->map[7][13] = 1;
	ft_mverti(6, 10, 13, w);
	w->map[7][10] = 1;
	ft_mhori(8, 9, 11, w);
	w->map[8][10] = 1;
	w->map[8][11] = 1;
	ft_mverti(9, 11, 13, w);
	ft_mverti(11, 9, 11, w);
}

void	ft_laby3(t_wolf3d *w)
{
	ft_mverti(2, 3, 7, w);
	ft_mverti(2, 10, 17, w);
	w->map[1][16] = 1;
	ft_mhori(2, 17, 6, w);
	ft_mhori(8, 17, 17, w);
	w->map[8][16] = 1;
	ft_mverti(17, 3, 14, w);
	ft_mverti(17, 12, 17, w);
	w->map[18][16] = 1;
	ft_mhori(2, 3, 17, w);
	w->map[4][1] = 1;
	w->map[5][1] = 1;
	w->map[8][2] = 1;
	w->map[13][1] = 1;
	ft_mverti(4, 5, 15, w);
	w->map[5][8] = 1;
	ft_mhori(4, 15, 9, w);
	ft_mhori(11, 15, 15, w);
	w->map[12][14] = 1;
	ft_lab3fin(w);
	w->map[9][10] = 4;
}
