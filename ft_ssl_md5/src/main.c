/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 10:59:14 by cjulliar          #+#    #+#             */
/*   Updated: 2019/04/22 10:59:18 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"
#include <fcntl.h>
#include <stdlib.h>
void	ft_read(char **rep, int fd)
{
	char	c[2];
	int		verif;
	char	*str;
	char	*tmp;

	c[1] = 0;
	verif = 1;
	str = ft_strdup("");
	while (verif > 0)
	{
		verif = read(fd, c, 1);
		if (verif == 0)
			break ;
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	rep[0] = str;
}

int 	ft_flags(int argc, char **argv, int *i, t_env *env)
{
	if (argv[*i][1] == 'p')
	{
		env->parser[0] = '1';
	}
	else if (argv[*i][1] == 'q')
	{
		env->parser[1] = '1';
	}
	else if (argv[*i][1] == 'r')
	{
		env->parser[2] = '1';
	}
	else if (argv[*i][1] == 's')
	{
		*i += 1;
		if (*i + 1 > argc)
		{
			env->parser[3] = '1';
			env->strS = argv[*i + 1];
			printf("%s\n", env->strS);
		}
		else
			return (0);
	}
	return (1);
}

int		ft_parser(int argc, char **argv, t_env *env)
{
	int i;

	i = 0;
	while(i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_flags(argc, argv, &i, env) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_init(t_env *env)
{
	int 	i;

	env->parser = (char*)malloc(sizeof(char)*6);
	i = 0;
	while (i < 4)
	{
		env->parser[i] = '0';
		i += 1;
	}

}

void	ft_md5(int argc, char **argv, t_env *env)
{
	if (ft_parser(argc, argv, env) == 0)
	{
		printf("error a mieux dev\n"); // pas fini !
	}
}

void	ft_sha256(int argc, char **argv, t_env *env)
{
	if (ft_parser(argc, argv, env) == 0)
	{
		printf("error a mieux dev\n"); // pas fini !
	}
}

int		main(int argc, char **argv)
{
	t_env	env;
	char	*r = NULL;

	if (argc < 2)
	{	
		write(1, "usage: ft_ssl command [command opts] [command args]\n", 52);
		return (0);
	}
	ft_init(&env);
	if (ft_strcmp(ft_lower(argv[1]), "md5") == 0)
		ft_md5(argc, argv, &env);
	else if (ft_strcmp(ft_lower(argv[1]), "sha256") == 0)
		ft_sha256(argc, argv, &env);
	else
	{
		write(1, "ft_ssl: Error: '", 16);
		ft_putstr(argv[1]);
		write(1, "' is an invalid command.\n\nStandard commands:\n\n", 46);
		write(1, "Message Digest commands:\nmd5\nsha256\n\nCipher commands:", 53);

	}
	printf("parser: %s\n", env.parser);

	char onlyS[4] = "0001";
	if (env.parser != onlyS)
		ft_read(&r, 0);

	//printf("%s\n", r);



	

	return (0);
}
