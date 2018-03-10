/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/09 17:09:28 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	handle_file(char *data)
{
	uint64_t	magic;

	magic = *(uint64_t *)data;
	if (magic == AR_MAGIC || magic == AR_CIGAM)
		handle_ar(data);
	else if (magic == MH_MAGIC || magic == MH_CIGAM)
		handle_macho32(data);
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		handle_macho64(data);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat32(data);
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		handle_fat64(data);
}

void		nm(char *filename)
{
	int		fd;
	char	*data;

	fd = open(filename, O_RDONLY);
	if (MAP_FAILED == (data = mmap(0, buf.st_size, PROT_READ, \
		MAP_PRIVATE, fd, 0)))
	{
		ft_dprintf(2, "%s: mmap() call failed.\n", program);
		return ;
	}
	handle_file(data);
}
