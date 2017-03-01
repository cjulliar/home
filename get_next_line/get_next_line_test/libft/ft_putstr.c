/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:18:33 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 19:06:21 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		ft_putchar(s[i]);
		i++;
	}
}
