/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_macho64o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:20:00 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/29 17:33:59 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)
#define PPC(x) (ppc ? swap_uint64(x) : x)
#define ARCH (ppc ? "(for architecture ppc64)" : "(for architecture x86_64)")

int64_t	g_size;
uint8_t	ppc;

static void	otool_hexdump(void *ptr, size_t size, size_t start)
{
	size_t	i;

	i = 0;
	while (i < size + ((size % 16) ? (16 - size % 16) : 0))
	{
		if (i % 16 == 0)
			ft_printf("%016llx\t", start + i);
		if (i < size)
			ft_printf("%02x ", 0xff & ((char *)ptr)[i]);
		if (i % 16 == (16 - 1))
			ft_putchar('\n');
		i++;
	}
}

static void	print_dump(void *addr, size_t size, size_t start)
{
	if (ISON(options, A))
		ft_print_memory(addr, size, start);
	else
		otool_hexdump(addr, size, start);
}

static void	parse_segments(t_parse p, char *ptr)
{
	int64_t				j;

	j = -1;
	p.sc64 = (struct segment_command_64 *)p.lc;
	p.section64 = (struct section_64 *)((char *)p.sc64 \
			+ sizeof(struct segment_command_64));
	while (++j < (int64_t)PPC(p.sc64->nsects))
	{
		check(p.section64 + j);
		if (!ft_strcmp((p.section64+j)->sectname, SECT_TEXT) \
			&& !ft_strcmp((p.section64+j)->segname, SEG_TEXT) \
			&& ISON(options, T))
		{
			ft_printf("Contents of (__TEXT,__text) section\n");
			print_dump(ptr + (p.section64+j)->offset, (p.section64+j)->size, \
					(p.section64+j)->addr);
		}
		else if (!ft_strcmp((p.section64+j)->sectname, SECT_DATA) \
			&& !ft_strcmp((p.section64+j)->segname, SEG_DATA) \
			&& ISON(options, D))
		{
			ft_printf("Contents of (__DATA,__data) section\n");
			print_dump(ptr + (p.section64+j)->offset, (p.section64+j)->size, \
					(p.section64+j)->addr);
		}
	}
}

void		handle_macho64o(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	p.header64 = (struct mach_header_64 *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header_64);
	ppc = swap_uint64(p.header64->cputype) == CPU_TYPE_POWERPC64;
	if ((p.header64->cputype) != CPU_TYPE_X86_64 && !ppc)
		return ;
	if (g_multi == 3)
		ft_printf("%s %s:\n", filename, ARCH);
	else
		ft_printf("%s:\n", filename, ARCH);
	while (i++ < PPC(p.header64->ncmds))
	{
		if (PPC(p.lc->cmd) == LC_SEGMENT_64)
			parse_segments(p, ptr);
		p.lc = check((void *)p.lc + PPC(p.lc->cmdsize));
	}
}
