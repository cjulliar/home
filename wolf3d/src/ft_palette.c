/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:27:43 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/07 16:42:16 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		ft_lacouleur2(int orientation)
{
	if (orientation == 1)
		return (255);
	else if (orientation == 2)
		return (255000);
	else if (orientation == 3)
		return (255000);
	else if (orientation == 4)
		return (255255000);
	return (0);
}

int		ft_lacouleur(t_wolf3d *w, int orientation)
{
	if (w->level == 3)
	{
		if (orientation == 1)
			return (255000);
		else if (orientation == 2)
			return (152251152);
		else if (orientation == 3)
			return (17325547);
		else if (orientation == 4)
			return (34139087);
	}
	else if (w->level == 4)
	{
		if (orientation == 1)
			return (211211211);
		else if (orientation == 2)
			return (192192192);
		else if (orientation == 3)
			return (105105105);
		else if (orientation == 4)
			return (60060060);
	}
	else
		ft_lacouleur2(orientation);
	return (0);
}

int		ft_palette(t_wolf3d *w, int orientation)
{
	if (w->level == 5 || w->level == 1)
	{
		if (orientation == 1)
			return (255255000);
		else if (orientation == 2)
			return (255215000);
		else if (orientation == 3)
			return (255140000);
		else if (orientation == 4)
			return (218165032);
	}
	else if (w->level == 2)
	{
		if (orientation == 1)
			return (255000000);
		else if (orientation == 2)
			return (178034034);
		else if (orientation == 3)
			return (139000000);
		else if (orientation == 4)
			return (220020060);
	}
	else
		return (ft_lacouleur(w, orientation));
	return (0);
}
