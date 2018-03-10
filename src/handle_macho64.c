#include "nm.h"

static void	parse_segments(t_parse p)
{
	int64_t				j;

	j = -1;
	p.sc64 = (struct segment_command_64 *)p.lc;
	p.section64 = (struct section_64 *)((char *)p.sc64 \
			+ sizeof(struct segment_command64));
	while (++j < p.sc64->nsects)
	{
		if (!ft_strcmp((s+j)->sectname, SECT_TEXT)
			&& !ft_strcmp((s+j)->segname, SEG_TEXT))
			g_segments.text = j + 1;
		else if (!ft_strcmp((s+j)->sectname, SECT_DATA)
			&& !ft_strcmp((s+j)->segname, SEG_DATA))
			g_segments.data = j + 1;
		else if (!ft_strcmp((s+j)->sectname, SECT_BSS)
			&& !ft_strcmp((s+j)->segname, SEG_BSS))
			g_segments.bss = j + 1;
	}
}

static void	parse_symbols(t_parse p, char *ptr)
{
	int64_t	j;

	j = -1;
	p.sym = (struct symtab_command *)p.lc;
	g_symbols = (t_symbols *)malloc(sizeof(t_symbols) * (p.sym->nsyms + 1));
	p.array64 = (void *)ptr + p.sym->symoff;
	while (++j < p.sym->nsyms)
	{
		g_symbols[j].value = p.array64[j].n_value;
		g_symbols[j].name = ((void *)ptr + p.sym->symoff) \
			+ p.array64[j].n_un.n_strx;
		g_symbols[j].type = p.array64[j].n_type;
		g_symbols[j].sect = p.array64[j].n_sect;
	}
}

void		handle_macho64(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	p.header64 = (struct mach_header_64 *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i++ < p.header64.ncmds)
	{
		if (p.lc->cmd == LC_SEGMENT_64)
			parse_segments(p);
		if (p.lc->cmd == LC_SYMTAB)
			parse_symbols(p, ptr);
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
}
