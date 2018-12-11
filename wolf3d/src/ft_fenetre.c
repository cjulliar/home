/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fenetre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:59:48 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/07 16:40:02 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_fenetre(t_wolf3d *w)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(0);
	w->window = SDL_CreateWindow("wolf3d",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, w->f->hauteur, w->f->largeur,
			SDL_WINDOW_SHOWN);
	if (w->window < 0)
		exit(0);
	w->surface = SDL_GetWindowSurface(w->window);
	ft_loop_event(w);
	SDL_DestroyWindow(w->window);
	SDL_Quit();
}
