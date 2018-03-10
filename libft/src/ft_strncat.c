/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 00:35:29 by ataguiro          #+#    #+#             */
/*   Updated: 2016/09/15 11:31:22 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int t;

	i = 0;
	t = 0;
	while (dest[t])
		t++;
	while ((i < nb) && src[i])
	{
		dest[t] = src[i];
		t++;
		i++;
	}
	dest[t] = '\0';
	return (dest);
}
