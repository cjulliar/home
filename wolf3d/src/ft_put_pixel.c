/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:13:30 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/01 06:56:34 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_put_pixel(int x, int y, int color, t_wolf3d *w)
{
	Uint32	*pixels;
	int		cr;
	int		cg;
	int		cb;

	cr = color / 1000000;
	cg = (color % 1000000) / 1000;
	cb = color % 1000;
	pixels = w->surface->pixels + y * w->surface->pitch +
		x * w->surface->format->BytesPerPixel;
	*pixels = SDL_MapRGB(w->surface->format, cr, cg, cb);
}
