#include "../include/ft_ssl.h"
#include <fcntl.h>

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

int 	ft_flags(char **argv, int i, t_env *env)
{
	if (argv[i][1] == 'p')
	{
		env->p += 1;
	}
	else if (argv[i][1] == 'q')
	{
		env->q += 1;
	}
	else if (argv[i][1] == 'r')
	{
		env->r += 1;
	}
	else if (argv[i][1] == 's')
	{
		env->s += 1;
	}
	else if (argv[i - 1][1] != 's')
	{
		return (0);
	}
	return (1);
}

int		ft_parser(char **argv, int argc, t_env *env)
{
	int i;

	i = 0;
	while(i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_flags(argv, i, env) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_init(t_env *env)
{
	env->p = 0;
	env->q = 0;
	env->r = 0;
	env->s = 0;

}

int		main(int argc, char **argv)
{
	t_env	env;
	char	*r;

	if (argc < 2)
	{	
		write(1, "usage: ft_ssl command [command opts] [command args]\n", 52);
		return (-1);
	}

	ft_init(&env);
	if (ft_parser(argv, argc, &env) == 0)
	{
		printf("error a mieux dev\n"); // pas fini !
		return (0);
	}
	if (env.p || env.q || env.r)
		ft_read(&r, 0);


	// if (ft_strcmp(ft_lower(argv[1]), "md5") == 0 && argv[2] != NULL)
	// 	ft_md5(argv[2], &env);
	// else if (ft_strcmp(ft_lower(argv[1]), "sha256") == 0 && argv[2] != NULL)
	// 	ft_sha256(argv[2], &env);
	// else
	// {
	// 	write(1, "\n", 1); //error a gere ici
	// }

	return (0);
}