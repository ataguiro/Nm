#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mach-o/loader.h>
#include <mach-o/swap.h>

int	main(int ac, char **av)
{
	char	*filename = av[1];
	int		fd = open(filename, O_RDONLY);
	struct mach_header	header;

	read(fd, &header, sizeof(header));
	printf("magic: %x\ncputype: %x\ncpusubtype: %x\nfiletype: %x\nncmds: %u\nsizeofcmds: %u\nflags: %x\n", header.magic, header.cputype, header.cpusubtype, header.filetype, header.ncmds, header.sizeofcmds, header.flags);
}
