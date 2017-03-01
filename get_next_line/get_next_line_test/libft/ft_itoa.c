/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:13:41 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/19 18:51:09 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		pow;
	int		i;
	char	*str;

	i = 0;
	pow = ft_findpowpos(n, 10);
	if (n < 0)
		i++;
	str = ft_strnew(pow + 1 + i);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (pow > 0)
	{
		str[i] = ft_abs(n / ft_pow(10, pow)) + '0';
		n %= ft_pow(10, pow);
		pow--;
		i++;
	}
	str[i] = ft_abs(n) + '0';
	return (str);
}
