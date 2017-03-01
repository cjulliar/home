/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:25:47 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 19:08:44 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
