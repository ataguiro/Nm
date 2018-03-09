/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:33:25 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/11 16:34:06 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] && c)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
			count++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (count);
}

static int	count_char(char const *s, char c)
{
	int		count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	t_infos2	info;

	if (!s)
		return (NULL);
	info.words = count_words(s, c);
	info.new = (char **)malloc(sizeof(char *) * (info.words + 2));
	info.i = 0;
	info.t = 0;
	if (!info.new)
		return (NULL);
	while (info.t < info.words)
	{
		while (s[info.i] != 0 && s[info.i] == c)
			info.i++;
		info.new[info.t] = ft_strsub(&s[info.i], 0, count_char(&s[info.i], c));
		info.t++;
		while (s[info.i] != 0 && s[info.i] != c)
			info.i++;
	}
	info.new[info.words] = 0;
	return (info.new);
}
