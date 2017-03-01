/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:02:29 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 13:58:20 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)ft_memalloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content_size = 0;
		list->content = NULL;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	return (list);
}
