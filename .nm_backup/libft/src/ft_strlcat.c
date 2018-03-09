/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:31:53 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/06 00:52:58 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	t;
	unsigned int	p;

	i = 0;
	t = 0;
	t = ft_strlen(src);
	p = ft_strlen(dst);
	while (dst[i] && i < size)
		i++;
	t += i;
	if (size - 1 > p)
		ft_strncat(dst, (char *)src, size - p - 1);
	return (t);
}
