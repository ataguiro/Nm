/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 00:13:00 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/05 12:13:36 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (dest[t])
		t++;
	while (src[i])
	{
		dest[t] = src[i];
		t++;
		i++;
	}
	dest[t] = '\0';
	return (dest);
}
