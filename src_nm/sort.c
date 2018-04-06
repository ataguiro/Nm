/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:43:21 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/06 18:06:53 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#define NOT_BAD(a, b) (((size_t)a != 0xcafebabe) && ((size_t)b != 0xcafebabe))


static int	compare(t_symbols a, t_symbols b)
{
	int		ret;
	int		num_mode;

	num_mode = ISON(g_options, N);
	if (num_mode)
		ret = (a.value > b.value);
	else
		ret = NOT_BAD(a.name, b.name) ? ft_strcmp(a.name, b.name) : 0;
	if (!ret)
		ret = (a.value > b.value);
	if (ISON(g_options, R))
		ret = (num_mode || !ret) ? !ret : -ret;
	return (ret);
}

void		sort(size_t n)
{
	size_t				i;
	size_t				j;
	t_symbols			tmp;

	if (!g_symbols)
		return ;
	if (ISON(g_options, P))
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
