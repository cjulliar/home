/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:42:11 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/28 11:05:45 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

void	resolution(t_values *v, t_values *r)
{
	double	a;
	double	b;
	double	c;

	a = (double)v->a - (double)r->a;
	b = (double)v->b - (double)r->b;
	c = (double)v->c - (double)r->c;
	if (a < 0 || (a == 0 && b < 0) || (a == 0 && b == 0 && c < 0))
	{
		a *= -1;
		b *= -1;
		c *= -1;
	}
	reduced_forme(a, b, c);
	reponse(a, b, c, v);
}
