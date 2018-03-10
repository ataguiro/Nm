/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 22:17:01 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/07 18:52:49 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!little[0] || !little)
		return ((char *)big);
	while (big[i] && (i < n))
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < n)
		{
			if (little[j + 1] == 0)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}
