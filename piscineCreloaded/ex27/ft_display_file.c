/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:52:16 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/05 12:37:07 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_display_file(char *src)
{
	int		fd;
	char	test[4096];
	int		i;

	fd = open(src, O_RDONLY);
	i = read(fd, test, 4096);
	write(1, test, i);
	close(fd);
}

int		ft_gestion_erreurs(int argc)
{
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	else if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else
		return (1);
}

int		main(int argc, char **argv)
{
	if (ft_gestion_erreurs(argc) == 1)
		ft_display_file(argv[1]);
	return (0);
}
