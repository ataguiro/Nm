/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:34:13 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/21 11:45:53 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		handle_fat32(char *ptr)
{
	t_parse		p;
	uint32_t	n;
	uint32_t	offset;
	int64_t		i;

	i = -1;
	p.fathdr = (struct fat_header *)ptr;
	p.fatarch = (struct fat_arch *)(p.fathdr + 1);
	n = swap_uint32(p.fathdr->nfat_arch);
	while (++i < n)
	{
		offset = swap_uint32(p.fatarch[i].offset);
		if (((swap_uint32(p.fatarch[i].cputype) \
				== CPU_TYPE_I386) && (sizeof(void *) == 4))
				|| ((swap_uint32(p.fatarch[i].cputype) == CPU_TYPE_X86_64)
					&& (sizeof(void *) == 8)))
			handle_fileo(ptr + offset);
	}
}
