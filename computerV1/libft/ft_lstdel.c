/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:01:12 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 15:21:39 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	size_t	i;
	t_list	*tempo;

	i = 0;
	while (*alst != NULL)
	{
		tempo = *alst;
		del(tempo->content, tempo->content_size);
		*alst = (*alst)->next;
		free(tempo);
	}
	*alst = NULL;
}
