/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:20:44 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/20 17:06:03 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	tmp = *alst;
	while (tmp->next != NULL)
	{
		new = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = new;
	}
	ft_lstdelone(&tmp, del);
	*alst = NULL;
}
