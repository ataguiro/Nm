/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/12 14:03:38 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	handle_file(char *data)
{
	uint64_t	magic;

	magic = *(uint64_t *)data;
	(magic == AR_MAGIC || magic == AR_CIGAM) ? handle_ar(data) : 0;
	magic = (uint32_t)magic;
	if (magic == MH_MAGIC || magic == MH_CIGAM)
		handle_macho32(data);
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		handle_macho64(data);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat32(data);
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		handle_fat64(data);
	else
	{
		ft_dprintf(2, "%s: %s The file was not recognized as a valid object file\n\n", program, filename);
	}
}

void	nm(char *filename_local, size_t size)
{
	int		fd;
	char	*data;

	fd = open(filename_local, O_RDONLY);
	if (MAP_FAILED == (data = mmap(0, size, PROT_READ, \
		MAP_PRIVATE, fd, 0)))
	{
		ft_dprintf(2, "%s: mmap() call failed.\n", program);
		return ;
	}
	close(fd);
	filename = filename_local;
	handle_file(data);
}
