/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:49:52 by cjulliar          #+#    #+#             */
/*   Updated: 2017/10/01 06:51:09 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

double	ft_degre(double radian)
{
	int		res;

	res = (int)((radian * 180.0) / M_PI);
	return (res);
}
