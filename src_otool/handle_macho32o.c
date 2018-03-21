#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)

int64_t	g_size;

static void	parse_segments(t_parse p)
{
	int64_t				j;

	j = -1;
	p.sc = (struct segment_command *)p.lc;
	p.section = (struct section *)((char *)p.sc \
			+ sizeof(struct segment_command));
	while (++j < p.sc->nsects)
	{
		if (!ft_strcmp((p.section+j)->sectname, SECT_TEXT) \
			&& !ft_strcmp((p.section+j)->segname, SEG_TEXT) \
			&& ISON(options, T))
			;
		else if (!ft_strcmp((p.section+j)->sectname, SECT_DATA) \
			&& !ft_strcmp((p.section+j)->segname, SEG_DATA) \
			&& ISON(options, D))
			;
		else if (!ft_strcmp((p.section+j)->sectname, SECT_BSS) \
			&& !ft_strcmp((p.section+j)->segname, SEG_DATA) \
			&& ISON(options, B))
			;
	}
}

void		handle_macho32o(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	g_segments.k = 0;
	p.header = (struct mach_header *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header);
	while (i++ < p.header->ncmds)
	{
		if (p.lc->cmd == LC_SEGMENT)
			parse_segments(p);
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
	clear_globals();
}
