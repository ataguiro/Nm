/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 15:38:36 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:09:22 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree != NULL)
	{
		tree->right = NULL;
		tree->left = NULL;
		tree->item = item;
	}
	return (tree);
}
