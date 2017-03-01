/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/20 10:20:08 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strndel_beg(char *texte, size_t y)
{
	char	*rep;
	size_t	i;
	size_t	yy;

	yy = y;				//malloc surrement trop grand
	if ((rep = ft_strnew(ft_strlen(texte) - y - 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(texte) - yy - 1)/* && texte[y] != '\0'*/)
	{
		y = y + 1;
		rep[i] = texte[y];
		i = i + 1;
	}
	ft_strdel(&texte);
	texte = ft_strnew(i);
	ft_strncpy(texte, rep, i);
	ft_strdel(&rep);
//	texte = ft_strdup(rep);
//	ft_strdel(&rep);
	return (texte);
}
//faut gere les \0 seul
static int		ft_lecture(int fd, char **line, char **texte, size_t y)
{
	int		b;
	char	*lecture;

	lecture = ft_strnew(BUFF_SIZE);
	b = read(fd, lecture, BUFF_SIZE);
//	ft_putnbr(b);
//	if ((b = read(fd, lecture, BUFF_SIZE)) < 1)
//		return (b);
	*texte = ft_strjoin(*texte, lecture);
	while (y < ft_strlen(*texte))
	{
		if ((*texte)[y] == '\n' || (*texte)[y] == '\0')
		{
//	ft_putstr("[");
//	ft_putnbr(b);
//	ft_putchar((*texte)[y]);
//	ft_putendl("]");
			*line = ft_strnew(y);
			ft_strncpy(*line, *texte, y);
			if ((*texte)[y] != '\0')
			{
				if ((*texte = ft_strndel_beg(*texte, y)) == NULL)
					return (-1);
			}
			ft_strdel(&lecture);
			return (1);
		}
		y = y + 1;
	}
/*	if (b > 0)
	{
		*line = ft_strnew(y);
		ft_strncpy(*line, *texte, y);
		b = 1;
	}
*/
	//ft_putendl(*texte);
	ft_strdel(&lecture);
	return (b);
}

int				get_next_line(int fd, char **line)
{
	static char		*texte = NULL;
	int				rep;

	if (texte == NULL || fd < 0)
	{
		if ((texte = ft_strnew(0)) == NULL || fd < 0)
			return (-1);
	}
	if (*line != NULL)
		ft_strdel(line);
	rep = ft_lecture(fd, line, &texte, 0);
	while (*line == NULL && rep > 0)
		rep = ft_lecture(fd, line, &texte, 0);
	if (rep == 0 && texte[0] != '\0')
	{
		*line = ft_strnew(ft_strlen(texte));
		ft_strncpy(*line, texte, ft_strlen(texte));
		rep = 1;
		ft_strdel(&texte);
//	ft_putchar('[');
//	ft_putstr(texte);
//	ft_putendl("]");
	}
	return (rep);
}
