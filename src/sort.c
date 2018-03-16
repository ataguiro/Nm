/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:43:21 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/16 16:43:05 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int	compare(t_symbols a, t_symbols b)
{
	int		ret;

	if (ISON(options, N))
		ret = (a.value > b.value);
	else
		ret = ft_strcmp(a.name, b.name);
	if (!ret)
		ret = (a.value > b.value);

	if (ISON(options, R))
		ret = !ret;
	return (ret);
}

void		sort(size_t n)
{
	size_t				i;
	size_t				j;
	t_symbols			tmp;

	if (ISON(options, P))
		return ;
	i = 1;
	while (i <= n - 1)
	{
		j = i;
		while (j > 0 && (compare(g_symbols[j - 1], g_symbols[j]) > 0))
		{
			tmp = g_symbols[j];
			g_symbols[j] = g_symbols[j - 1];
			g_symbols[j - 1] = tmp;
			j--;
		}
		i++;
	}
}
