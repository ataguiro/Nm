/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:12:37 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:14:00 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabremove(char ***tab, char *str, char *by)
{
	size_t	i;
	char	**cleaner;

	i = 0;
	while ((*tab)[i])
	{
		if (!ft_strcmp((*tab)[i], str))
		{
			if (by)
			{
				(*tab)[i] ? free((*tab)[i]) : 0;
				(*tab)[i] = ft_strdup(by);
			}
			else
				(*tab)[i][0] = 0;
			break ;
		}
		i++;
	}
	cleaner = *tab;
	*tab = ft_tabdup(*tab);
	ft_tabdel(&cleaner);
	return (i);
}
