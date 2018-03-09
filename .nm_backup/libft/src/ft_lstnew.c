/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:45:21 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/30 16:22:12 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * (content_size + 1));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void *)malloc(content_size);
		if (!(new->content))
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		((char *)(new->content))[content_size] = 0;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
