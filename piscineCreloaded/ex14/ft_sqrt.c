/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:28:48 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/03 11:49:57 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;
	int		res;
	int		mod;

	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		mod = nb % i;
		res = nb / i;
		if (res == i && mod == 0)
			return (res);
		i = i + 1;
	}
	return (0);
}
