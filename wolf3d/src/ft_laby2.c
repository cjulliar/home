/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_laby2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:24:09 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 01:29:29 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_laby2p3(t_wolf3d *w)
{
	ft_mhori(4, 12, 9, w);
	ft_mhori(12, 13, 14, w);
	ft_mhori(1, 14, 4, w);
	ft_mhori(7, 15, 10, w);
	ft_mhori(12, 15, 14, w);
	ft_mhori(2, 16, 5, w);
	ft_mhori(5, 17, 10, w);
	w->map[13][16] = 3;
	w->map[9][14] = 8;
	w->map[17][1] = 9;
}

void	ft_laby2p2(t_wolf3d *w)
{
	ft_mhori(12, 17, 16, w);
	ft_mhori(16, 16, 18, w);
	ft_mhori(14, 5, 16, w);
	ft_mhori(16, 4, 18, w);
	ft_mhori(6, 14, 7, w);
	w->map[17][2] = 1;
	w->map[16][4] = 1;
	ft_mverti(16, 10, 13, w);
	w->map[17][13] = 1;
	w->map[17][10] = 1;
	ft_mverti(18, 9, 10, w);
	ft_mhori(6, 2, 12, w);
	ft_mhori(8, 4, 10, w);
	ft_mhori(2, 5, 8, w);
	ft_mhori(12, 6, 14, w);
	ft_mhori(2, 7, 5, w);
	ft_mhori(16, 7, 18, w);
	ft_mhori(14, 8, 16, w);
	ft_mhori(9, 9, 12, w);
	ft_mhori(2, 10, 7, w);
	ft_laby2p3(w);
}

void	ft_laby2(t_wolf3d *w)
{
	w->map[1][3] = 1;
	w->map[2][3] = 1;
	ft_mverti(4, 1, 3, w);
	ft_mverti(2, 5, 7, w);
	ft_mverti(2, 9, 12, w);
	ft_mverti(3, 16, 18, w);
	ft_mverti(4, 12, 14, w);
	w->map[5][8] = 1;
	ft_mverti(6, 2, 5, w);
	ft_mverti(7, 5, 10, w);
	ft_mverti(9, 7, 9, w);
	ft_mverti(9, 11, 13, w);
	ft_mverti(10, 4, 7, w);
	ft_mverti(10, 13, 15, w);
	ft_mverti(12, 2, 4, w);
	ft_mverti(12, 6, 9, w);
	ft_mverti(12, 11, 13, w);
	ft_mverti(12, 15, 17, w);
	ft_mverti(14, 1, 3, w);
	ft_mverti(14, 8, 11, w);
	ft_mverti(14, 13, 15, w);
	ft_mverti(16, 1, 2, w);
	ft_laby2p2(w);
}
