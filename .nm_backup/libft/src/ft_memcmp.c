/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:44:50 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/04 21:45:20 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;

	cs1 = (void *)s1;
	cs2 = (void *)s2;
	while (n > 0)
	{
		if (*cs1 != *cs2)
			return ((unsigned char)*cs1 - (unsigned char)*cs2);
		cs1++;
		cs2++;
		n--;
	}
	return (0);
}
