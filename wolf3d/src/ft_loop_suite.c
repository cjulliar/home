/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 01:15:45 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/09 01:32:42 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		ft_avancons(t_wolf3d *w)
{
	if (w->keys[SDL_SCANCODE_UP])
	{
		if (ft_mouvements(w, 1) >= 2)
			return (1);
		if (w->keys[SDL_SCANCODE_RIGHT])
		{
			w->orientation += 5;
			if (w->orientation > 360)
				w->orientation -= 360;
		}
		else if (w->keys[SDL_SCANCODE_LEFT])
		{
			w->orientation -= 5;
			if (w->orientation < 0)
				w->orientation += 360;
		}
		return (1);
	}
	return (0);
}

int		ft_reculons(t_wolf3d *w)
{
	if (w->keys[SDL_SCANCODE_DOWN])
	{
		ft_mouvements(w, -1);
		if (w->keys[SDL_SCANCODE_RIGHT])
		{
			w->orientation += 5;
			if (w->orientation > 360)
				w->orientation -= 360;
		}
		else if (w->keys[SDL_SCANCODE_LEFT])
		{
			w->orientation -= 5;
			if (w->orientation < 0)
				w->orientation += 360;
		}
		return (1);
	}
	return (0);
}

int		ft_tournicoti(t_wolf3d *w)
{
	if (w->keys[SDL_SCANCODE_LEFT])
	{
		w->orientation -= 5;
		if (w->orientation < 360)
			w->orientation += 360;
		if (w->keys[SDL_SCANCODE_UP])
			ft_mouvements(w, 1);
		else if (w->keys[SDL_SCANCODE_DOWN])
			ft_mouvements(w, -1);
		return (1);
	}
	else if (w->keys[SDL_SCANCODE_RIGHT])
	{
		w->orientation += 5;
		if (w->orientation > 360)
			w->orientation -= 360;
		if (w->keys[SDL_SCANCODE_UP])
			ft_mouvements(w, 1);
		else if (w->keys[SDL_SCANCODE_DOWN])
			ft_mouvements(w, -1);
		return (1);
	}
	return (0);
}

int		ft_loop_suite(t_wolf3d *w)
{
	if (ft_tournicoti(w) == 1 || ft_avancons(w) == 1 || ft_reculons(w) == 1)
		return (1);
	return (0);
}
