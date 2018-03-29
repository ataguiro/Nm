#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)
#define PPC(x) (ppc ? swap_uint32(x) : x)
#define ARCH (ppc ? "(for architecture ppc)" : "(for architecture i386)")

size_t	g_size;
uint8_t	ppc;

static void	parse_segments(t_parse p)
{
	int64_t				j;

	j = -1;
	p.sc = (struct segment_command *)p.lc;
	p.section = (struct section *)((char *)p.sc \
			+ sizeof(struct segment_command));
	while (++j < PPC(p.sc->nsects))
	{
		check(p.section + j);
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
	g_symbols = (t_symbols *)malloc(sizeof(t_symbols) * (PPC(p.sym->nsyms) + 1));
	if (!g_symbols)
		exit(EXIT_FAILURE);
	p.array = (void *)ptr + PPC(p.sym->symoff);
	g_size = PPC(p.sym->nsyms);
	while (++j < (int64_t)g_size)
	{
		g_symbols[j].value = PPC(p.array[j].n_value);
		g_symbols[j].name = check((void *)ptr + PPC(p.sym->stroff)) \
			+ PPC(p.array[j].n_un.n_strx);
		check(g_symbols[j].name);
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

static void	print_symbols(uint8_t o)
{
	int64_t		i;
	uint8_t		flag;
	char		c;

	i = -1;
	sort(g_size);
	flag = ISON(options, J);
	while (g_symbols[++i].name)
	{
		c = get_type(g_symbols[i].type, g_symbols[i].value, g_symbols[i].sect);
		if ((c == '-' || c == 'u') || !ft_strcmp(g_symbols[i].name, ""))
			continue ;
		o ? ft_printf("%s: ", filename) : 0;
		if (!flag)
		{
			if (c == 'U')
				ft_printf("%8s", " ");
			else
				ft_printf("%08llx", g_symbols[i].value);
			ft_printf(" %c %s\n", c, g_symbols[i].name);
		}
		else
			ft_printf("%s\n", g_symbols[i].name);
	}
}

void		handle_macho32(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	g_segments.k = 0;
	p.header = (struct mach_header *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header);
	ppc = swap_uint32(p.header->cputype) == CPU_TYPE_POWERPC;
	if ((p.header->cputype) != CPU_TYPE_I386 && !ppc)
		return ;
	g_multi == 1 ? ft_printf("\n%s:\n", filename) : 0;
	g_multi == 3 ? ft_printf("\n%s %s:\n", filename, ARCH) : 0;
	g_multi == 2 ? ft_printf("%s:\n", filename, ARCH) : 0;
	while (i++ < PPC(p.header->ncmds))
	{
		if (PPC(p.lc->cmd) == LC_SEGMENT)
			parse_segments(p);
		if (PPC(p.lc->cmd) == LC_SYMTAB)
			parse_symbols(p, ptr);
		p.lc = check((void *)p.lc + PPC(p.lc->cmdsize));
	}
	print_symbols(ISON(options, O));
	clear_globals();
}