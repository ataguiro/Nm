#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)

int64_t	g_size;

static void	parse_segments(t_parse p)
{
	int64_t				j;

	j = -1;
	p.sc64 = (struct segment_command_64 *)p.lc;
	p.section64 = (struct section_64 *)((char *)p.sc64 \
			+ sizeof(struct segment_command_64));
	while (++j < p.sc64->nsects)
	{
		if (!ft_strcmp((p.section64+j)->sectname, SECT_TEXT) \
			&& !ft_strcmp((p.section64+j)->segname, SEG_TEXT) \
			&& ISON(options, T))
			;
		else if (!ft_strcmp((p.section64+j)->sectname, SECT_DATA) \
			&& !ft_strcmp((p.section64+j)->segname, SEG_DATA) \
			&& ISON(options, D))
			;
		else if (!ft_strcmp((p.section64+j)->sectname, SECT_BSS) \
			&& !ft_strcmp((p.section64+j)->segname, SEG_DATA) \
			&& ISON(options, B))
			;
	}
}

void		handle_macho64o(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	g_segments.k = 0;
	p.header64 = (struct mach_header_64 *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i++ < p.header64->ncmds)
	{
		if (p.lc->cmd == LC_SEGMENT_64)
			parse_segments(p);
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
	clear_globals();
}
