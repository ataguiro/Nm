/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:14:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/29 20:14:16 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	*check(void *ptr)
{
	if (ptr && ((ptr - g_check.data) < (long)g_check.size))
		return (ptr);
	else
	{
		ft_dprintf(2, "%s: %s: corrupted file\n", g_program, g_filename);
		exit(EXIT_FAILURE);
	}
}
