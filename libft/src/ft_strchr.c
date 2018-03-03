/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:45:14 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/05 00:17:48 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	n;

	i = 0;
	n = c;
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] == n)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
