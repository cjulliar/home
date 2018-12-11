/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:24:37 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/21 14:29:54 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rep;
	t_list	*debutrep;

	if (!lst || !f)
		return (NULL);
	debutrep = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (debutrep == NULL)
		return (NULL);
	rep = debutrep;
	while (lst->next)
	{
		lst = lst->next;
		rep->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (rep == NULL)
			return (NULL);
		rep = rep->next;
	}
	return (debutrep);
}
