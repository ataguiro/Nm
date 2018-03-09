/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:18:37 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/06 10:21:11 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmplst;

	new = f(lst);
	tmplst = new;
	if (!new)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmplst->next = f(lst)))
			return (NULL);
		tmplst = tmplst->next;
	}
	return (new);
}
