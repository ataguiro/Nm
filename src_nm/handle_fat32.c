/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:34:13 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/29 11:54:00 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"


static int	is_hostarch(cpu_type_t type)
{
	if ((type == CPU_TYPE_X86_64) && (sizeof(void *) == 8))
		return (1);
	if ((type == CPU_TYPE_I386) && (sizeof(void *) == 4))
		return (1);
	return (0);
}

static void	set_multi(t_parse p, uint32_t n)
{
	int64_t	i;

	i = -1;
	while (++i < n)
	{
		if (is_hostarch(swap_uint32(p.fatarch[i].cputype)))
		{
			g_multi = 0;
			return ;
		}
	}
	if (i > 0)
		g_multi = 2;
}

static void	redistribute(cpu_type_t type, char *ptr)
{
	cpu_type_t	tmp;

	tmp = swap_uint32(type);
	if (!g_multi)
	{
		if (is_hostarch(tmp))
			handle_file(ptr);
	}
	else
		handle_file(ptr);
}

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
	set_multi(p, n);
	while (++i < n)
	{
		offset = swap_uint32(p.fatarch[i].offset);
		redistribute(p.fatarch[i].cputype, ptr + offset);
	}
}
