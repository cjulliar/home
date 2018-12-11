/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:46:45 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/04 16:12:14 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		main(int argc, char **argv)
{
	t_wolf3d	*w;

	if ((w = (t_wolf3d *)malloc(sizeof(t_wolf3d))) == NULL ||
			ft_initialisation(w) == 0)
		if (w == NULL || ft_initialisation(w) == 0)
		{
			ft_putendl("Invalid file");
			return (2);
		}
	if (argc >= 1)
		ft_putendl(argv[1]);
	ft_fenetre(w);
	return (0);
}
