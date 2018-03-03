/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:14:35 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:14:55 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**dup;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_tablen(tab) + 1;
	i = 0;
	j = 0;
	if (!(dup = (char **)ft_memalloc(sizeof(char *) * size * size)))
		return (NULL);
	while (tab[i])
	{
		if (tab[i][0])
		{
			dup[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	return (dup);
}
