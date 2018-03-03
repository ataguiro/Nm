/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:06:30 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 13:36:31 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <wchar.h>

int	tl_wstrnlen(wint_t *str, int n)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i] && i < n)
	{
		if (str[i] < 0x0080)
			count++;
		else if (str[i] < 0x800)
			count += 2;
		else if (str[i] < 0x10000)
			count += 3;
		else if (str[i] < 0x200000)
			count += 4;
		else if (str[i] < 0x4000000)
			count += 5;
		else if (str[i] < 0x7fffffff)
			count += 6;
	}
	return (count);
}
