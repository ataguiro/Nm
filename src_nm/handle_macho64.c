/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_macho64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:49:51 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/06 18:07:23 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)
#define PPC(x) (g_ppc ? swap_uint64(x) : x)
#define ARCH (g_ppc ? "(for architecture ppc64)" : "(for architecture x86_64)")

int64_t	g_size;
uint8_t	g_ppc;

static void	parse_segments(t_parse p)
{
	int64_t	j;

	j = -1;
	p.sc64 = (struct segment_command_64 *)p.lc;
	p.section64 = (struct section_64 *)((char *)p.sc64 \
			+ sizeof(struct segment_command_64));
	while (++j < p.sc64->nsects)
	{
		check(p.section64 + j);
		if (!ft_strcmp((p.section64 + j)->sectname, SECT_TEXT)
			&& !ft_strcmp((p.section64 + j)->segname, SEG_TEXT))
			g_segments.text = g_segments.k + 1;
		else if (!ft_strcmp((p.section64 + j)->sectname, SECT_DATA)
			&& !ft_strcmp((p.section64 + j)->segname, SEG_DATA))
			g_segments.data = g_segments.k + 1;
		else if (!ft_strcmp((p.section64 + j)->sectname, SECT_BSS)
			&& !ft_strcmp((p.section64 + j)->segname, SEG_DATA))
			g_segments.bss = g_segments.k + 1;
		(g_segments.k)++;
	}
}

static void	parse_symbols(t_parse p, char *ptr)
{
	int64_t	j;

	j = -1;
	p.sym = (struct symtab_command *)p.lc;
	g_symbols = (t_symbols *)secure_malloc(sizeof(t_symbols) \
			* (PPC(p.sym->nsyms) + 1));
	if (!g_symbols)
		exit(EXIT_FAILURE);
	p.array64 = check((void *)ptr + PPC(p.sym->symoff));
	g_size = PPC(p.sym->nsyms);
	while (++j < g_size)
	{
		g_symbols[j].value = PPC(p.array64[j].n_value);
		g_symbols[j].name = check(((void *)ptr + PPC(p.sym->stroff))) \
			+ PPC(p.array64[j].n_un.n_strx);
		g_symbols[j].name = check_bad_string(g_symbols[j].name);
		g_symbols[j].type = p.array64[j].n_type;
		g_symbols[j].sect = p.array64[j].n_sect;
	}
	g_symbols[j].name = NULL;
}

static char	get_type(uint8_t type, uint64_t value, uint8_t sect)
{
	char	c;

	c = '?';
	c = (type & N_STAB) ? '-' : c;
	c = (DO_MASK(type) == N_UNDF && (type & N_EXT)) ? 'u' : c;
	if (DO_MASK(type) == N_UNDF && (type & N_EXT))
		c = (value) ? 'c' : c;
	c = (DO_MASK(type) == N_PBUD) ? 'u' : c;
	c = (DO_MASK(type) == N_ABS) ? 'a' : c;
	if (DO_MASK(type) == N_SECT)
	{
		c = 's';
		c = (sect == g_segments.text) ? 't' : c;
		c = (sect == g_segments.data) ? 'd' : c;
		c = (sect == g_segments.bss) ? 'b' : c;
	}
	c = (DO_MASK(type) == N_INDR) ? 'i' : c;
	c = c - (((type & N_EXT) && c != '?') ? 32 : 0);
	return (c);
}

static void	print_symbols(uint8_t o)
{
	int64_t	i;
	uint8_t	flag;
	char	c;

	i = -1;
	sort(g_size);
	flag = ISON(g_options, J);
 	while (g_symbols && g_symbols[++i].name)
	{
		c = get_type(g_symbols[i].type, g_symbols[i].value, g_symbols[i].sect);
		if ((c == '-' || c == 'u') || ((size_t)g_symbols[i].name != 0xcafebabe \
		&& !ft_strcmp(g_symbols[i].name, "")))
			continue ;
		o ? ft_printf("%s: ", g_filename) : 0;
		if (!flag)
		{
			(c == 'U') ? ft_printf("%16s", " ") : \
			ft_printf("%016llx", g_symbols[i].value);
			ft_printf(" %c %s\n", c, (size_t)g_symbols[i].name != 0xcafebabe \
			? g_symbols[i].name : "bad string index");
		}
		else
			ft_printf("%s\n", g_symbols[i].name);
	}
}

void		handle_macho64(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	g_segments.k = 0;
	p.header64 = (struct mach_header_64 *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header_64);
	g_ppc = swap_uint64(p.header64->cputype) == CPU_TYPE_POWERPC64;
	if ((p.header64->cputype) != CPU_TYPE_X86_64 && !g_ppc)
		return ;
	g_multi == 1 ? ft_printf("\n%s:\n", g_filename) : 0;
	g_multi == 3 ? ft_printf("\n%s %s:\n", g_filename, ARCH) : 0;
	g_multi == 2 ? ft_printf("%s:\n", g_filename, ARCH) : 0;
	while (i++ < PPC(p.header64->ncmds))
	{
		if (PPC(p.lc->cmd) == LC_SEGMENT_64)
			parse_segments(p);
		if (PPC(p.lc->cmd) == LC_SYMTAB)
			parse_symbols(p, ptr);
		check(p.lc = (void *)p.lc + PPC(p.lc->cmdsize));
	}
	print_symbols(ISON(g_options, O));
	clear_globals();
}
