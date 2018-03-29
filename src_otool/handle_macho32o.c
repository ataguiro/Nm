#include "nm.h"
#define DO_MASK(type) (type & N_TYPE)

int64_t	g_size;

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
	while (++j < p.sc64->nsects)
	{
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

void		handle_macho32o(char *ptr)
{
	t_parse		p;
	uint32_t	i;

	i = 0;
	p.header = (struct mach_header *)ptr;
	p.lc = (void *)ptr + sizeof(struct mach_header);
	ft_printf("%s:\n", filename);
	while (i++ < p.header->ncmds)
	{
		if (p.lc->cmd == LC_SEGMENT)
			parse_segments(p, ptr);
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
	clear_globals();
}
