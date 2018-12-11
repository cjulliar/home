/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divinf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:49:06 by cjulliar          #+#    #+#             */
/*   Updated: 2017/08/17 20:17:15 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

double	ft_divinf(int val, int div)
{
	int res;

	res = val / div;
	if (val % div <= (double)div / 2)
		return ((double)res);
	else
		return ((double)(res + 1));
}
