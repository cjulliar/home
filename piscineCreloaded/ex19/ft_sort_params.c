/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:27:34 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/05 14:48:34 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i = i + 1;
	}
}

void	ft_swap_str(char **tab, int i)
{
	char	*str;

	str = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = str;
}

int		compare_mots(char *mot1, char *mot2)
{
	int		i;

	i = 0;
	while (mot1[i] != '\0' && mot2[i] != '\0')
	{
		if (mot1[i] == mot2[i])
			i++;
		else if (mot1[i] < mot2[i])
			return (1);
		else
			return (2);
	}
	if (mot1[i] > mot2[i])
		return (2);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc - 1)
	{
		if (compare_mots(argv[i], argv[i + 1]) == 2)
		{
			ft_swap_str(argv, i);
			i = 1;
		}
		else
			i = i + 1;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i = i + 1;
	}
	return (0);
}
