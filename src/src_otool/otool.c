/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/09 17:05:02 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_check	g_check = {0, NULL};
void	*g_lastaddr = 0;

static int	handle_recursive(char *data)
{
	ft_dprintf(2, "%s: %s: Recursive callback at %p, skipping...\n", \
			g_program, g_filename, data);
	return (EXIT_FAILURE);
}

int			handle_fileo(char *data)
{
	uint64_t	magic;

	if (data == g_lastaddr)
		return (handle_recursive(data));
	g_lastaddr = data;
	if (NULL == check(data + sizeof(uint64_t)))
		return (EXIT_FAILURE);
	magic = *(uint64_t *)data;
	if ((magic == AR_MAGIC || magic == AR_CIGAM))
		handle_ar(data);
	else if ((magic = (uint32_t)magic) \
			&& (magic == MH_MAGIC || magic == MH_CIGAM))
		handle_macho32o(data);
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		handle_macho64o(data);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat32(data);
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		handle_fat64(data);
	else
	{
		ft_dprintf(2, "%s: %s: is not an object file\n", g_program, g_filename);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			otool(char *filename_local, size_t size)
{
	int		fd;
	char	*data;

	if (!ISON(g_options, T) && !ISON(g_options, D))
	{
		ft_printf("error: %s: one of -td must be specified\n", g_program);
		return (EXIT_FAILURE);
	}
	fd = open(filename_local, O_RDONLY | O_NONBLOCK);
	if (MAP_FAILED == (data = mmap(0, size, PROT_READ, \
		MAP_PRIVATE, fd, 0)))
	{
		ft_dprintf(2, "%s: mmap() call failed.\n", g_program);
		return (EXIT_FAILURE);
	}
	close(fd);
	g_check.data = data;
	g_check.size = size;
	g_filename = filename_local;
	return (handle_fileo(data));
}
