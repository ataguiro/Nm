/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:34:13 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/09 13:17:25 by ataguiro         ###   ########.fr       */
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
	check(p.fatarch + n);
	while (++i < n)
	{
		if (is_hostarch(swap_uint64(p.fatarch[i].cputype)))
		{
			g_multi = 0;
			return ;
		}
	}
	if (i > 0)
		g_multi = 2;
	if (i > 1)
		g_multi = 3;
}

static int	redistribute(cpu_type_t type, char *ptr)
{
	cpu_type_t	tmp;

	tmp = swap_uint64(type);
	check(ptr);
	if (!g_multi)
	{
		if (is_hostarch(tmp))
		{
			handle_file(ptr);
			return (0);
		}
	}
	else
		handle_file(ptr);
	return (1);
}

void		handle_fat64(char *ptr)
{
	t_parse		p;
	uint32_t	n;
	uint32_t	offset;
	int64_t		i;

	i = -1;
	check(ptr + sizeof(struct fat_header));
	p.fathdr = (struct fat_header *)ptr;
	check((void *)p.fathdr + sizeof(struct fat_arch_64));
	p.fatarch64 = (struct fat_arch_64 *)(p.fathdr + 1);
	n = swap_uint64(p.fathdr->nfat_arch);
	check(p.fatarch64 + n);
	set_multi(p, n);
	while (++i < n)
	{
		offset = swap_uint64(p.fatarch64[i].offset);
		if (!redistribute(p.fatarch[i].cputype, ptr + offset))
			return ;
	}
}
