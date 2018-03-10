/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:25:34 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/25 14:19:37 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	j = 0;
	if (!src)
		return (ft_strnew(0));
	while (src[n])
		n++;
	if (!n)
		return (ft_strnew(0));
	dest = ft_strnew(n + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
