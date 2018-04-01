/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:45:55 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/01 12:39:43 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	handle_ar(char *ptr)
{
	(void)ptr;
	ft_dprintf(2, "%s: %s: is an AR archive (unsupported)\n", \
			g_program, g_filename);
}
