/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_ntoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:46:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 13:35:00 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "ft_printf.h"
#define RANGE "0123456789"

static int	tl_nbrlen(unsigned long long x, int base, int tmp)
{
	int	len;

	len = !tmp && !x ? 0 : 1;
	while (x /= base)
		++len;
	fselect()->lenl[1] = fselect()->lenl[1] - len > 0 ?
	fselect()->lenl[1] - len : 0;
	fselect()->lenl[0] = fselect()->lenl[0] - (len + fselect()->lenl[1]) > 0 ?
	fselect()->lenl[0] - (len + fselect()->lenl[1]) : 0;
	len += fselect()->lenl[1] + fselect()->lenl[0];
	return (len);
}

static void	fill(int *i, char c, int range)
{
	int j;

	j = 0;
	while (j++ < range)
		fselect()->result[(*i)--] = c;
}

static void	inits(int *tmp)
{
	*tmp = fselect()->lenl[1];
	fselect()->lenl[1] != -1 ? fselect()->args &= ~(PMASK << ZERO) : 0;
	IS_ON(fselect()->args, MINUS) ? fselect()->args &= ~(PMASK << ZERO) : 0;
	if (IS_ON(fselect()->args, ZERO) && (fselect()->lenl[1] == -1))
	{
		fselect()->lenl[1] = fselect()->lenl[0];
		fselect()->lenl[0] = 0;
	}
	fselect()->lenl[1] == -1 ? fselect()->lenl[1] = 0 : 0;
}

char		*tl_ntoa_u(unsigned long long n, int base)
{
	int		i;
	int		tmp;

	inits(&tmp);
	i = tl_nbrlen(n, base, tmp) - 1;
	fselect()->result[i + 1] = 0;
	IS_ON(fselect()->args, MINUS) ? fill(&i, ' ', fselect()->lenl[0]) : 0;
	if (!n && tmp)
		fselect()->result[i--] = '0';
	while (n > 0)
	{
		fselect()->result[i--] = RANGE[n % base];
		n /= base;
	}
	fill(&i, '0', fselect()->lenl[1]);
	if (!IS_ON(fselect()->args, MINUS))
		fill(&i, IS_ON(fselect()->args, ZERO) ? '0' : ' ', fselect()->lenl[0]);
	return ((char *)fselect()->result);
}
