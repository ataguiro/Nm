/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:43:21 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/14 17:55:40 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int	compare(t_symbols a, t_symbols b)
{
	int		ret;
	ret = ft_strcmp(a.name, b.name);
	if (!ret)
		ret = (a.value > b.value);

	return (ret);
}

void		sort(void)
{
	int					i;
	int					j;
	t_symbols			tmp;

	i = 0;
	while (g_symbols[i].name)
	{
		j = i + 1;
		while (g_symbols[j].name)
		{
			if (compare(g_symbols[i], g_symbols[j]) > 0)
			{
				tmp = g_symbols[i];
				g_symbols[i] = g_symbols[j];
				g_symbols[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
