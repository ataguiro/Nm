/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 23:31:41 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/06 15:25:37 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		j;
	int		t;

	i = 0;
	j = 0;
	t = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (s[j])
	{
		str[t] = (*f)(j, s[j]);
		j++;
		t++;
	}
	str[t] = 0;
	return (str);
}
