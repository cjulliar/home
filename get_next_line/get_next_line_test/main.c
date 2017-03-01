/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:27:49 by cjulliar          #+#    #+#             *//*   Updated: 2016/12/02 13:56:58 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <assert.h>

int		get_next_line(int fd, char **line);

int		main(int argc, char **argv)
{

	char	*line;
//	int		out;
//	int		p[2];
	int		fd1;
//	int		fd2;
	int		rep;

	fd1 = argv[1] ?  open(argv[1], O_RDONLY) : 1;
//	fd2 = argv[2] ?  open(argv[2], O_RDONLY) : 1;
/*	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	dup2(out, fd);
	close(p[1]);
*/


//	fd2 = dup(fd1);
//	close (fd1);
//	argv[1] = "lol";
//	fd = open(argv[1], O_RDONLY);
/*	rep = get_next_line(fd1, &line);
	assert(rep == 1);
	assert(ft_strcmp(line, "abc") == 0);
	rep = get_next_line(fd1, &line);
	assert(rep == 1);
	assert(line == NULL || *line == '\0');
	rep = get_next_line(fd1, &line);
	assert(rep == 0);
	assert(line == NULL || *line == '\0');
	rep = get_next_line(fd1, &line);
	assert(rep == 0);
	assert(line == NULL || *line == '\0');*/

int o;
o = 0;
	while ((rep = get_next_line(fd1, &line)) > 0)
	{
		ft_putchar('"');
		ft_putstr(line);
		ft_putstr("' ");
		ft_putnbr(rep);
o = o + 1;
		ft_putchar('\n');
		free(line);
	}
		ft_putnbr(o);
//		free(line);

	/*
	rep = get_next_line(p[0], &line);
	assert(ft_strcmp(line, "aaa") == 0);
	assert(rep == 0 || rep == 1);
	*/

//	rep = get_next_line(fd2, &line);
//	printf("l1: %d\n'%s'\n",rep ,line);
/*
	get_next_line(fd1, &line);
	printf("l2:\n'%s'\n",line);
	get_next_line(fd2, &line);
	printf("l3:\n'%s'\n",line);
	get_next_line(fd1, &line);
	printf("l4:\n'%s'\n",line);
	*/
	argc = 1;
	return (0);
}
