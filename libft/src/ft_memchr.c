/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:24:44 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/04 23:12:06 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	new;

	src = (void *)s;
	new = c;
	while (n > 0)
	{
		if (*src == new)
			return ((void *)src);
		src++;
		n--;
	}
	return (NULL);
}
