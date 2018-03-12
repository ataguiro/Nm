/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:34:13 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/12 14:40:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		handle_fat64(char *ptr)
{
	t_parse		p;
	uint32_t	n;
	uint32_t	offset;
	int64_t		i;

	i = -1;
	p.fathdr = (struct fat_header *)ptr;
	p.fatarch64 = (struct fat_arch_64 *)(p.fathdr + 1);
	n = swap_uint64(p.fathdr->nfat_arch);
	while (++i < n)
	{
		offset = swap_uint64(p.fatarch64[i].offset);
		handle_file(ptr + offset);
	}
}
