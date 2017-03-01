/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:07:20 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 18:00:35 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (first == NULL)
		return (NULL);
	tmp = first;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (first);
}
