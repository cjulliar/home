/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:14:24 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/12 11:25:44 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_puissancedouble(double i, int p)
{
	double	r;

	r = 1;
	while (p > 0)
	{
		r *= i;
		p--;
	}
	return (r);
}