#include "nm.h"

#define SWAP32(x) ((((x) & 0xff000000) >> 24) | (((x) & 0xff0000) >> 8) \
							| (((x) & 0xff00) << 8) | (((x) & 0xff) << 24))

void		handle_fat32(char *ptr, char *filename)
{
	t_parse		p;
	uint32_t	n;
	uint32_t	offset;
	int64_t		i;

	i = -1;
	p.fathdr = ptr;
	p.fatarch = (struct fat_arch *)(p.fathdr + 1);
	n = SWAP32(p.fathdr->nfat_arch);
	while (++i < n)
	{
		offset = SWAP32(p.fatarch[i].offset);
		handle_file(ptr + offset, filename);
	}
}
