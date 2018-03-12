#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)

int			g_swap = 0;

static void	parse_segments(t_parse p)
{
	int64_t				j;

	j = -1;
	p.sc = (struct segment_command *)p.lc;
	p.section = (struct section *)((char *)p.sc \
			+ sizeof(struct segment_command));
	while (++j < p.sc->nsects)
	{
		if (!ft_strcmp((p.section+j)->sectname, SECT_TEXT)
			&& !ft_strcmp((p.section+j)->segname, SEG_TEXT))
			g_segments.text = g_segments.k + 1;
		else if (!ft_strcmp((p.section+j)->sectname, SECT_DATA)
			&& !ft_strcmp((p.section+j)->segname, SEG_DATA))
			g_segments.data = g_segments.k + 1;
		else if (!ft_strcmp((p.section+j)->sectname, SECT_BSS)
			&& !ft_strcmp((p.section+j)->segname, SEG_DATA))
			g_segments.bss = g_segments.k + 1;
		(g_segments.k)++;
	}
}

static void	parse_symbols(t_parse p, char *ptr)
{
	int64_t	j;

	j = -1;
	p.sym = (struct symtab_command *)p.lc;
	g_symbols = (t_symbols *)malloc(sizeof(t_symbols) * (p.sym->nsyms + 1));
	p.array = (void *)ptr + p.sym->symoff;
	while (++j < p.sym->nsyms)
	{
		g_symbols[j].value = p.array[j].n_value;
		g_symbols[j].name = ((void *)ptr + p.sym->stroff) \
			+ p.array[j].n_un.n_strx;
		g_symbols[j].type = p.array[j].n_type;
		g_symbols[j].sect = p.array[j].n_sect;
	}
	g_symbols[j].name = NULL;
}

static char	get_type(uint8_t type, uint64_t value, uint8_t sect)
{
	char	c;
	c = '?';
	c = (type & N_STAB) ? '-' : c;
	c = (DO_MASK(type) == N_UNDF) ? 'u' : c;
	if (DO_MASK(type) == N_UNDF)
		c = (value) ? 'c' : 'u';
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

static void	print_symbols(void)
{
	int64_t	i;
	char		c;

	i = -1;
	while (g_symbols[++i].name)
	{
		c = get_type(g_symbols[i].type, g_symbols[i].value, g_symbols[i].sect);
		if ((c == '-' || c == 'u') || !ft_strcmp(g_symbols[i].name, ""))
			continue ;
		if (!g_symbols[i].value)
			ft_printf("%8s", " ");
		else
			ft_printf("%08llx", g_symbols[i].value);
		ft_printf(" %c %s\n", c, g_symbols[i].name);
	}
}

void		handle_macho32(char *ptr, uint8_t swap)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	p.header = (struct mach_header *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header);
	while (i++ < p.header->ncmds)
	{
		if (p.lc->cmd == LC_SEGMENT)
			parse_segments(p);
		if (p.lc->cmd == LC_SYMTAB)
			parse_symbols(p, ptr);
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
	print_symbols();
	clear_globals();
}
