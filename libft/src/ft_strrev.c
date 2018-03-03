/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:40:30 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/02 13:57:42 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str) - 1;
	new = ft_strnew(ft_strlen(str));
	if (!new)
		return (NULL);
	while (len >= 0)
	{
		new[i] = str[len];
		len--;
		i++;
	}
	return (new);
}
