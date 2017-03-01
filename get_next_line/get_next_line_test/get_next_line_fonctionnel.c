/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/14 08:01:09 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_miche(char *tmp, char *lect, char **line, int *rep)
{
	size_t	y;
	size_t	i;
	char	*txt;

	if ((txt = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)) == NULL)
		return (NULL);
	y = 0;
	while (y < ft_strlen(tmp))
	{
		txt[y] = tmp[y];
		y = y + 1;
	}
	i = 0;
	while (i < BUFF_SIZE)
	{
		txt[y++] = lect[i];
		if (lect[i] == '\0')
		{
			*line = ft_strdup(txt);
			if (ft_strcmp(*line, "\0") != 0 && (*rep = 1))
				return (txt);
		}
		i = i + 1;
	}
	return (txt);
}

int		ft_bob(int fd, char **line)
{
	char	*txt;
	char	*tmp;
	char	*lect;
	int		*rep;

	lect = ft_strnew(BUFF_SIZE);
	txt = ft_strdup("\0");
	if ((rep = (int*)malloc(sizeof(int))) == NULL)
		return (-1);
	*rep = 2;
	while (read(fd, lect, BUFF_SIZE) != -1)
	{
		tmp = ft_strdup(txt);
		ft_strclr(txt);
		ft_strdel(&txt);
		if ((txt = ft_miche(tmp, lect, line, rep)) == NULL)
			return (-1);
		if (*rep == 1 || *rep == 0)
			return (*rep);
		ft_strclr(tmp);
		ft_strdel(&tmp);
		ft_strclr(lect);
	}
	return (-1);
}

int		ft_marcus(char **line, char **texte, size_t t, size_t i)
{
	char	*tmp;
	char	*text;

	if ((text = ft_strdup(*texte)) == NULL)
		return (-1);
	while (text[t] != '\n' && text[t] != '\0')
		t = t + 1;
	*line = ft_strsub(text, 0, t);
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(text) - t));
	if (tmp == NULL)
		return (-1);
	if (t != 0)
	{
		t = t + 1;
		while ((i + t) < ft_strlen(text))
		{
			tmp[i] = text[t + i];
			i = i + 1;
		}
		if ((*texte = (char*)malloc(sizeof(char) * ft_strlen(tmp))) == NULL)
			return (-1);
		*texte = tmp;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				st;
	int				sm;
	size_t			i;
	static char		**texte = NULL;

	if (texte == NULL)
	{
		st = ft_bob(fd, line);
		i = 0;
		texte = (char**)malloc(sizeof(char*));
		if (texte == NULL)
			return (-1);
		*texte = ft_strdup(*line);
	}
	else if (ft_strlen(*texte) != 0)
		st = 1;
	else
		st = 0;
	sm = ft_marcus(line, texte, 0, 0);
	if (sm != 1)
		return (sm);
	else if (st != 1)
		return (st);
	return (1);
}
