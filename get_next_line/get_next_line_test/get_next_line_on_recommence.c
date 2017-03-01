/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/19 09:36:16 by cjulliar         ###   ########.fr       */
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

int		ft_lecture(int fd, char **line, int b, int rep)
{
	char	*txt;
	char	*tmp;
	char	*lect;

	lect = ft_strnew(BUFF_SIZE);
	txt = ft_strdup("\0");
	while ((b = read(fd, lect, BUFF_SIZE)) != -1)
	{
		if (lect == NULL)
			lect = ft_strnew(BUFF_SIZE);
		tmp = ft_strdup(txt);
		ft_strdel(&txt);
		if ((txt = ft_miche(tmp, lect, line, &rep)) == NULL)
			return (-1);
		if (rep == 1 || rep == 0)
		{
//			ft_strdel(&txt);
//			ft_strdel(&lect);
			return (rep);
		}
		ft_strclr(lect);
		ft_strdel(&tmp);
	}
//	ft_strdel(&lect);
//	ft_strdel(&txt);
	return (b);
}

int		ft_casparticulier(char **line, char **texte, char *text, size_t v)
{
	size_t	t;

	t = 0;
	if (v == 1)
	{
		*texte = ft_strsub(*texte, 1, ft_strlen(*texte));
		*line = "";
		return (1);
	}
	else if (v == 0)
	{
		*texte = (char*)malloc(sizeof(char) * 1);
		*texte[0] = '\0';
		*line = "";
		return (1);
	}
	else
	{
		while (text[t] != '\n' && text[t] != '\0')
			t = t + 1;
		*line = ft_strsub(text, 0, t);
		return (t);
	}
}

int		ft_attribution(char **line, char **texte, size_t t, size_t i)
{
	char	*tmp;
	char	*text;

	if ((text = ft_strdup(*texte)) == NULL)
		return (-1);
	if (text[0] == '\n' && text[1] != '\0')
		return (ft_casparticulier(line, texte, text, 1));
	else if (text[0] == '\n' && text[1] == '\0')
		return (ft_casparticulier(line, texte, text, 0));
	else
		t = ft_casparticulier(line, texte, text, 2);
	if ((tmp = (char*)malloc(sizeof(char) * (ft_strlen(text) - t))) == NULL)
		return (-1);
	if (t++ != 0)
	{
		while ((i + t) < ft_strlen(text))
		{
			tmp[i] = text[t + i];
			i = i + 1;
		}
		*texte = ft_strdup(tmp);
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

	if (fd < 0)
		return (-1);
	else if (texte == NULL)
	{
		st = ft_lecture(fd, line, 0, 2);
		if (st != 1)
			return (st);
		i = 0;
		if ((texte = (char**)malloc(sizeof(char*))) == NULL)
			return (-1);
		*texte = ft_strdup(*line);
	}
	else if (ft_strlen(*texte) != 0)
		st = 1;
	else
		st = 0;
	sm = ft_attribution(line, texte, 0, 0);
	if (sm != 1)
		return (sm);
	return (1);
}
