#include "../include/ft_ssl.h"

void	ft_md5(char *str, t_env *env)
{
	printf("%s\n",str);
	env->i = 3;
}

void	ft_sha256(char *str, t_env *env)
{
	printf("%s\n",str);
	env->i = 3;
}

int		main(int argc, char **argv)
{
	t_env	env;
	if (argc < 2)
	{	
		write(1, "usage: ft_ssl command [command opts] [command args]\n", 52);
		return (-1);
	}
	if (ft_strcmp(ft_lower(argv[1]), "md5") == 0 && argv[2] != NULL)
		ft_md5(argv[2], &env);
	else if (ft_strcmp(ft_lower(argv[1]), "sha256") == 0 && argv[2] != NULL)
		ft_sha256(argv[2], &env);
	else
	{
		write(1, "\n", 1); //error a gere ici
	}

	return (0);
}