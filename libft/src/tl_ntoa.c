/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:46:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:18:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "ft_printf.h"
#define RANGE "0123456789"
#define LL_MIN -9223372036854775807
#define LL_MAX "-9223372036854775808"

static int	tl_nbrlen(long long x, int base, int tmp)
{
	int	len;
	int	sign;

	len = 1;
	(!x && !tmp) ? len-- : 0;
	sign = (x < 0 || IS_ON(fselect()->args, PLUS)
	|| IS_ON(fselect()->args, SPACE) || IS_ON(fselect()->args, SPACE));
	if ((x ^ (LL_MIN - 1)))
	{
		ABS(x);
		while (x /= base)
			++len;
	}
	else
		len += 18;
	fselect()->lenl[1] = fselect()->lenl[1] - len > 0 ?
	fselect()->lenl[1] - len : 0;
	fselect()->lenl[0] = fselect()->lenl[0]
	- (len + fselect()->lenl[1] + sign) > 0 ?
	fselect()->lenl[0] - (len + fselect()->lenl[1] + sign) : 0;
	len += fselect()->lenl[1] + fselect()->lenl[0];
	len += sign;
	return (len);
}

static void	fill(int *i, char c, int range, int sign)
{
	int j;

	j = 0;
	if (c)
		while (j++ < range)
		{
			fselect()->result[(*i)--] = c;
		}
	else
	{
		if (sign)
			fselect()->result[*i] = '-';
		else if (IS_ON(fselect()->args, PLUS))
			fselect()->result[*i] = '+';
		else if (IS_ON(fselect()->args, SPACE))
			fselect()->result[*i] = ' ';
	}
}

static void	inits(int *tmp, int *sign, long long n)
{
	*sign = (n < 0) ? 1 : 0;
	*tmp = fselect()->lenl[1];
	*tmp != -1 ? fselect()->args &= ~(PMASK << ZERO) : 0;
	IS_ON(fselect()->args, MINUS) ? fselect()->args &= ~(PMASK << ZERO) : 0;
	if (IS_ON(fselect()->args, ZERO) && (fselect()->lenl[1] == -1 || *sign))
	{
		fselect()->lenl[1] = fselect()->lenl[0] - (IS_ON(fselect()->args, PLUS)
		|| IS_ON(fselect()->args, SPACE) || *sign);
		fselect()->lenl[0] = 0;
	}
	fselect()->lenl[1] == -1 ? fselect()->lenl[1] = 0 : 0;
}

static void	spec_case(int sign, int *i)
{
	fill(i, '0', fselect()->lenl[1], sign);
	fill(i, 0, 0, sign);
	if (!IS_ON(fselect()->args, MINUS))
	{
		IS_ON(fselect()->args, PLUS) || IS_ON(fselect()->args, SPACE)
		|| sign ? --(*i) : 0;
		fill(i, IS_ON(fselect()->args, ZERO) ? '0' : ' ', \
		fselect()->lenl[0], 0);
	}
}

char		*tl_ntoa(long long n, int base)
{
	int			i;
	int			j;
	int			sign;
	int			tmp;

	j = 19;
	inits(&tmp, &sign, n);
	i = tl_nbrlen(n, base, tmp) - 1;
	fselect()->result[i + 1] = 0;
	IS_ON(fselect()->args, MINUS) ? fill(&i, ' ', fselect()->lenl[0], sign) : 0;
	n = (sign) ? -n : n;
	if (!n && tmp)
		fselect()->result[i--] = '0';
	if ((n ^ (LL_MIN - 1)))
		while (n > 0)
		{
			fselect()->result[i--] = RANGE[n % base];
			n /= base;
		}
	else
		while (j > 0)
			fselect()->result[i--] = LL_MAX[j--];
	spec_case(sign, &i);
	return ((char *)fselect()->result);
}
