/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:48:25 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/03 11:24:42 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		res;

	if (nb >= 0 && nb < 13)
	{
		res = 1;
		while (nb > 0)
		{
			res = res * nb;
			nb = nb - 1;
		}
	}
	else
		res = 0;
	return (res);
}
