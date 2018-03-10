/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:03:07 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/05 11:53:39 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	unsigned char	*s;
	unsigned char	new;

	d = dst;
	s = (void *)src;
	new = c;
	while (n > 0)
	{
		*d = *s;
		d++;
		if (*s == new)
			return (d);
		s++;
		n--;
	}
	return (NULL);
}
