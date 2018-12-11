/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:13:37 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 02:07:07 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_fond(t_wolf3d *w)
{
	int i;
	int y;

	i = 0;
	while (i < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			if (y < 500)
				ft_put_pixel(i, y, 204255, w);
			else
				ft_put_pixel(i, y, 139069019, w);
			y++;
		}
		i++;
	}
}

int		ft_looplevel2(t_wolf3d *w)
{
	if (w->keys[SDL_SCANCODE_3])
	{
		w->level = 3;
		ft_lectmap(w);
		return (1);
	}
	else if (w->keys[SDL_SCANCODE_4])
	{
		w->level = 4;
		ft_lectmap(w);
		return (1);
	}
	return (0);
}

int		ft_looplevel(t_wolf3d *w)
{
	if (w->keys[SDL_SCANCODE_1])
	{
		w->level = 1;
		ft_lectmap(w);
		return (1);
	}
	else if (w->keys[SDL_SCANCODE_2])
	{
		w->level = 2;
		ft_lectmap(w);
		return (1);
	}
	if (ft_looplevel2(w) == 1)
		return (1);
	return (0);
}

int		ft_optiontouche(t_wolf3d *w)
{
	if (w->event.type == SDL_KEYDOWN && w->event.key.keysym.sym == SDLK_t)
	{
		if (w->tcheat == 0)
			w->tcheat = 1;
		else
			w->tcheat = 0;
		return (1);
	}
	if (w->event.type == SDL_KEYDOWN && w->event.key.keysym.sym == SDLK_h)
	{
		if (w->hardcord == 0)
			w->hardcord = 1;
		else
			w->hardcord = 0;
		return (1);
	}
	return (0);
}

void	ft_loop_event(t_wolf3d *w)
{
	SDL_LockSurface(w->surface);
	ft_fond(w);
	ft_premieraffichage(w);
	w->keys = SDL_GetKeyboardState(NULL);
	while (1)
	{
		SDL_WaitEvent(&(w->event));
		if ((w->event.type == SDL_WINDOWEVENT &&
				w->event.window.event == SDL_WINDOWEVENT_CLOSE) ||
				w->keys[SDL_SCANCODE_ESCAPE])
			break ;
		else if (ft_loop_suite(w) == 1 || ft_looplevel(w) == 1 ||
				ft_optiontouche(w) == 1)
		{
			ft_fond(w);
			ft_premieraffichage(w);
		}
		SDL_UnlockSurface(w->surface);
		SDL_UpdateWindowSurface(w->window);
	}
}
