/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itabremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:42:43 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/14 14:53:27 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_itabdup(int *tab, int len)
{
	int	i;
	int	j;
	int	*new;

	i = 0;
	j = 0;
	new = (int *)ft_memalloc(sizeof(int) * len);
	while (i < len)
	{
		if (tab[i] != (int)0xdeadbeef)
		{
			new[j] = tab[i];
			j++;
		}
		i++;
	}
	return (new);
}

void		ft_itabremove(int **tab, int index, int len)
{
	int	*cleaner;

	(*tab)[index] = (int)0xdeadbeef;
	cleaner = *tab;
	*tab = ft_itabdup(*tab, len);
	cleaner ? free(cleaner) : 0;
}
