/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:14:09 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:14:21 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabstr(char **tab, char *str)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], str, ft_strlen(str)))
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
