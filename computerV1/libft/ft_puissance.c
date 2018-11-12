/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:14:24 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/12 11:14:53 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_puissance(int i, int p)
{
	int		r;

	r = 1;
	while (p > 0)
	{
		r *= i;
		p--;
	}
	return (r);
}
