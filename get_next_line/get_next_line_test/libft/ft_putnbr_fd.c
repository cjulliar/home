/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:28:58 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 15:56:42 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		pow;

	pow = ft_findpowpos(n, 10);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (pow > 0)
	{
		ft_putchar_fd(ft_abs(n / ft_pow(10, pow)) + '0', fd);
		n %= ft_pow(10, pow);
		pow--;
	}
	ft_putchar_fd(ft_abs(n) + '0', fd);
}
