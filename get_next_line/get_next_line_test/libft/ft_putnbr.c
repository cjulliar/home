/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:19:49 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 15:50:59 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int n)
{
	int		pow;

	pow = ft_findpowpos(n, 10);
	if (n < 0)
		ft_putchar('-');
	while (pow > 0)
	{
		ft_putchar(ft_abs(n / ft_pow(10, pow)) + '0');
		n %= ft_pow(10, pow);
		pow--;
	}
	ft_putchar(ft_abs(n) + '0');
}
