/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 22:28:39 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/25 17:26:48 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	k;

	new = ft_strnew(len + 1);
	if (new == NULL || !s)
		return (ft_strnew(0));
	i = 0;
	k = 0;
	while (k < len)
	{
		new[i] = s[start];
		start++;
		k++;
		i++;
	}
	new[i] = 0;
	new[i + 1] = 0;
	return (new);
}
