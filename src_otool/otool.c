/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/29 17:36:11 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_check	g_check = {0, NULL};

void	handle_fileo(char *data)
{
	uint64_t	magic;

	magic = *(uint64_t *)data;
	(magic == AR_MAGIC || magic == AR_CIGAM) ? handle_ar(data) : 0;
	magic = (uint32_t)magic;
	if (magic == MH_MAGIC || magic == MH_CIGAM)
		handle_macho32o(data);
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		handle_macho64o(data);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat32(data);
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		handle_fat64(data);
	else
		ft_dprintf(2, "%s: %s: is not an object file\n", program, filename);
}

void	otool(char *filename_local, size_t size)
{
	int		fd;
	char	*data;

	if (!ISON(options, T) && !ISON(options, D))
	{
		ft_printf("error: %s: one of -td must be specified\n", program);
		exit(EXIT_FAILURE);
	}
	fd = open(filename_local, O_RDONLY);
	if (MAP_FAILED == (data = mmap(0, size, PROT_READ, \
		MAP_PRIVATE, fd, 0)))
	{
		ft_dprintf(2, "%s: mmap() call failed.\n", program);
		return ;
	}
	close(fd);
	g_check.data = data;
	g_check.size = size;
	filename = filename_local;
	handle_fileo(data);
}
