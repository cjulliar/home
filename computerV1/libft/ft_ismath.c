/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:47:31 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 14:49:55 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ismath(char c)
{
	if (c != '-' && c != '+' && c != '*' && c != '/' && c != '%'
		&& c != 'x' && c != 'X' && c != '.' && c != '^' && c != '=')
		return (0);
	return (1);
}
