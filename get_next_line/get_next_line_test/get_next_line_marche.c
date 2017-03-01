/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/14 00:30:30 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include <unistd.h>
//#include <stdlib.h>
//#include <stdio.h>
//#define BUFF_SIZE = 10000; //	376 -> ligne 1
#include "get_next_line.h"

int		ft_bob(int fd, char **line)
{
	char	*txt;
	char	*tmp;
	char	*lect;
	size_t	i;
	size_t	y;
	size_t	o;

	lect = ft_strnew(BUFF_SIZE);
	txt = ft_strdup("\0");
	o = 0;
	while(o != 5)
	{
		o = read(fd, lect, BUFF_SIZE);
		tmp = ft_strdup(txt);
		ft_strclr(txt);
		ft_strdel(&txt);
		txt = ft_strnew(ft_strlen(tmp) + BUFF_SIZE);
		y = 0;
		while (y < ft_strlen(tmp))
		{
			txt[y] = tmp[y];
			y = y + 1;
		}
		i = 0;
		while (i < BUFF_SIZE)
		{
			txt[y] = lect[i];
			if (lect[i] == '\0')
			{
				*line = ft_strdup(txt);
				if (ft_strcmp(*line, "\0") != 0)
				{
					return (1);
				}
				else
				{
					return (0);
				}
			}
			i = i + 1;
			y = y + 1;
		}
		ft_strclr(tmp);
		ft_strdel(&tmp);
		ft_strclr(lect);
	}
	return (-1);
}

int		ft_marcus(char **line, char **texte)
{
	size_t	t;
	size_t	i;
	char	*tmp;
	char	*text;

	ft_putendl("");
	t = 0;
	text = ft_strdup(*texte);
	if (text == NULL)
		return (-1);
	while (text[t] != '\n' && text[t] != '\0')
	{
		t = t + 1;
	}
	*line = ft_strsub(text, 0, t);
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(text) - t));
//	ft_putendl("passe par la");
//	ft_putnbr(t);
//	if(t == 0)
//		ft_putchar('\n');
	if (t != 0)
	{
		i = 0;
//		ft_putnbr(t);
//		ft_putchar('\t');
//		ft_putnbr(ft_strlen(text));
		t = t  +1;
		while ((i + t) < ft_strlen(text))
		{
			tmp[i] = text[t + i];
			i = i + 1;
		}
//		ft_putchar('\t');
//		ft_putnbr(i);
		*texte = (char*)malloc(sizeof(char) * ft_strlen(tmp));
		*texte = tmp;
//		ft_putendl(*texte);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int		st;
	int		sm;
	size_t	i;
	static char		**texte = NULL;

	if (texte == NULL)
	{
		st = ft_bob(fd, line);
		i = 0;
		texte = (char**)malloc(sizeof(char*));
		*texte = ft_strdup(*line);
	}
	else if (ft_strlen(*texte) != 0)
		st = 1;
	else
		st = 0;
	sm = ft_marcus(line, texte);
//	printf("sm: %d\tst: %d\n",sm,st);
	if (sm != 1)
		return (sm);
	else if (st != 1)
		return(st);
	return (1);
}






/*
void	ft_remplir_struct(int fd)
{
	t_struc		structure;

}




int		get_next_line(int fd, char **line)
{
	char	*lec;
	char	*temp;
	char	*chocolat;
	size_t	i;
	size_t	y;
	size_t	p;
	size_t	z;
	y = 0;
	p = 0;
	z = 0;
	lec = (char*)malloc(sizeof(char) * BUFF_SIZE);
	temp = malloc(sizeof(char) * BUFF_SIZE);

		i = read(fd, temp, BUFF_SIZE);
		



//	lec = temp;
	*line = chocolat;
	return (1);
}
*/
