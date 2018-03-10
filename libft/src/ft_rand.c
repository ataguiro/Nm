/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:10:01 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:10:45 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

int	ft_rand(void)
{
	long long	random;
	long long	n;
	clock_t		t1;

	t1 = clock();
	n = 0xFFFFF;
	while (n > 0)
		n--;
	random = (long long)(clock() - t1 + clock() * 0x7FFFFFFFFFF) * 0x12;
	random /= ((sizeof(int) * 0x4) + 0xdeadbeef);
	random >>= 0xa;
	random /= sizeof(int) * 0xa;
	return ((int)random);
}
