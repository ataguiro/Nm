/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:09:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:09:31 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	btree_del(t_btree *tree)
{
	if (!tree)
		return ;
	btree_del(tree->left);
	tree->item ? free(tree->item) : 0;
	btree_del(tree->right);
	free(tree);
}
