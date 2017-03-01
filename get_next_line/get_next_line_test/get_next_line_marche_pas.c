/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/08 22:30:07 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t buff = BUFF_SIZE;

int		ft_lecture(int fd, size_t buf, char *txt)
{
	size_t	k;
	size_t	y;
	size_t	i;
	char	*temp;

	k = 0;
	y = 0;
	temp = (char*)malloc(sizeof(char) * 1);
	while (y < buf)
	{
		i = read(fd, temp, BUFF_SIZE);
		if (i == 0)
			return (0);
		txt[y] = temp[0];
		if (txt[y] == '\n' || txt[y] == '\0')
		{
			free(temp);
			return (1);
		}
		y = y + 1;
	}
	free(temp);
	return (-1);
}

char	*ft_realloc_line(char *lect, char *txt)
{
	size_t	i;
	size_t	y;
	char	*tmp;

	i = 0;
	y = 0;
	tmp = (char*)malloc(sizeof(char) * (buff));
	ft_strcpy(tmp, lect);
	ft_strdel(&lect);
	lect = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(txt)));
	while (i < ft_strlen(tmp))
	{
		lect[i] = tmp[i];
		i = i + 1;
	}
	while (y < ft_strlen(txt))
	{
		lect[i] = txt[y];
		i = i + 1;
		y = y + 1;
	}
	return (lect);
}

int		get_next_line(int fd, char **line)
{
	char	*txt;
	size_t	buf;
	int		rep;
	char	*lect;

	lect = (char*)malloc(sizeof(char) * buff);
	buf = BUFF_SIZE;
	rep = -2;
	while (rep != 1)
	{
		txt = (char*)malloc(sizeof(char) * buff);
		rep = ft_lecture(fd, buff, txt);
		lect = ft_realloc_line(lect, txt);
		if (rep == 0)
		{
			*line = "\0";
			return (0);
		}
		else if (rep == -1)
			buff = buff + 1000;
	}
	*line = lect;
	return (1);
}
