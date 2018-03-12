/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_globals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:25:41 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/12 13:26:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	clear_globals(void)
{
	g_segments.text = 0;
	g_segments.bss = 0;
	g_segments.data = 0;
	g_segments.k = 0;
	free(g_symbols);
	g_symbols = NULL;
}
