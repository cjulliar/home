/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mhori.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:18:40 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/07 10:21:15 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_mhori(int x, int y, int xmax, t_wolf3d *w)
{
	while (x <= xmax)
	{
		w->map[x][y] = 1;
		x++;
	}
}
