/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:14:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/10 13:30:04 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint8_t	g_c = 0;

void	*check(void *ptr)
{
	if ((int)ptr >= 0 && (int64_t)ptr >= 0 \
			&& ((ptr - g_check.data) < (long)g_check.size) \
			&& (ptr > g_check.data))
		return (ptr);
	else
	{
		if (!g_c)
			ft_dprintf(2, "%s: %s: empty section or corrupted file\n", \
				g_program, g_filename);
		g_c = 1;
		g_error = 1;
		return (NULL);
	}
}

void	*check_bad_string(void *ptr)
{
	if (ptr && ((ptr - g_check.data) < (long)g_check.size))
		return (ptr);
	else
		return ((void *)0xcafebabe);
}
