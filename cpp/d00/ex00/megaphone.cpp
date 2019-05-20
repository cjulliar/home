#include <iostream>

void	ft_strup(char *str)
{
	int		i;
	char	c;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			c = str[i] - 32;
		else
			c = str[i];
		std::cout << c;
		i++;
	}
}

void	megaphone(int ac, char **ag)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_strup(ag[i]);
		i++;
	}
	std::cout << std::endl;
}

int		main(int ac, char **ag)
{
	if (ac > 1)
		megaphone(ac, ag);
	else
    	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
