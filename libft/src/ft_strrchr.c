/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:45:14 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/05 00:29:16 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	n;

	i = ft_strlen((char *)s);
	n = c;
	while (i >= 0)
	{
		if (s[i] == n)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
