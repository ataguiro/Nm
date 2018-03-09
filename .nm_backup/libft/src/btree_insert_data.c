/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:28:53 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/28 17:22:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item, int bin)
{
	if (!(*root))
		*root = btree_create_node(item);
	else
	{
		if (!bin)
			btree_insert_data(&((*root)->left), item, bin);
		else
			btree_insert_data(&((*root)->right), item, bin);
	}
}
