/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_macho32o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:20:00 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/29 17:50:06 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)
#define PPC(x) (ppc ? swap_uint32(x) : x)
#define ARCH (ppc ? "(architecture ppc)" : "(architecture i386)")

int64_t	g_size;
uint8_t	ppc;

static void	otool_hexdump(void *ptr, size_t size, size_t start)
{
	size_t	i;

	i = 0;
	while (i < size + ((size % 16) ? (16 - size % 16) : 0))
	{
		if (i % 16 == 0)
			ft_printf("%08llx\t", start + i);
		if (i < size)
			ft_printf("%02x", 0xff & ((char *)ptr)[i]);
		if (!ppc && i < size)
			ft_putchar(' ');
		if (ppc && (i % 4 == 3) && i < size)
			ft_putchar(' ');
		if (i % 16 == 15)
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
	p.sc = (struct segment_command *)p.lc;
	p.section = (struct section *)((char *)p.sc \
			+ sizeof(struct segment_command));
	while (++j < PPC(p.sc->nsects))
	{
		check(p.section + j);
		if (!ft_strcmp((p.section+j)->sectname, SECT_TEXT) \
			&& !ft_strcmp((p.section+j)->segname, SEG_TEXT) \
			&& ISON(options, T))
		{
			ft_printf("Contents of (__TEXT,__text) section\n");
			print_dump(ptr + PPC((p.section+j)->offset), PPC((p.section+j)->size), \
					PPC((p.section+j)->addr));
		}
		else if (!ft_strcmp((p.section+j)->sectname, SECT_DATA) \
			&& !ft_strcmp((p.section+j)->segname, SEG_DATA) \
			&& ISON(options, D))
		{
			ft_printf("Contents of (__DATA,__data) section\n");
			print_dump(ptr + PPC((p.section+j)->offset), PPC((p.section+j)->size), \
					PPC((p.section+j)->addr));
		}
	}
}

void		handle_macho32o(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	p.header = (struct mach_header *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header);
	ppc = swap_uint32(p.header->cputype) == CPU_TYPE_POWERPC;
	if ((p.header->cputype) != CPU_TYPE_I386 && !ppc)
		return ;
	if (g_multi == 3)
		ft_printf("%s %s:\n", filename, ARCH);
	else
		ft_printf("%s:\n", filename, ARCH);
	while (i++ < PPC(p.header->ncmds))
	{
		if (PPC(p.lc->cmd) == LC_SEGMENT)
			parse_segments(p, ptr);
		p.lc = check((void *)p.lc + PPC(p.lc->cmdsize));
	}
}
