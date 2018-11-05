/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:35:43 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 16:10:20 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newpara;

	newpara = (t_list*)malloc(sizeof(*newpara));
	if (newpara == NULL)
		return (NULL);
	if (content == NULL)
	{
		newpara->content_size = 0;
		newpara->content = NULL;
	}
	else
	{
		newpara->content = malloc(sizeof(content_size));
		if (content == NULL)
		{
			free(newpara);
			return (NULL);
		}
		ft_memcpy(newpara->content, content, content_size);
		newpara->content_size = content_size;
	}
	newpara->next = NULL;
	return (newpara);
}
