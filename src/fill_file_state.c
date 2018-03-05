/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:29:14 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/05 16:47:47 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static uint64_t	get_magic(t_files *ptr)
{
	uint64_t	magic;
	int			fd;

	fd = open(ptr->filename, O_RDONLY);
	read(fd, &magic, sizeof(uint64_t));
	return (magic);
}

void			fill_file_state(void)
{
	t_files		*ptr;
	uint64_t	magic;

	ptr = g_files;
	while (ptr)
	{
		if (ptr->type == REGULAR)
		{
			magic = get_magic(ptr);
			ptr->state = (magic == AR_MAGIC || magic == AR_CIGMA) ? AR : NONE;
			magic = (uint32_t)magic;
			if (magic == MH_MAGIC || magic == MH_CIGAM)
				ptr->state = MACHO32;
			else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
				ptr->state = MACHO64;
			else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
				ptr->state = FAT32;
			else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
				ptr->state = FAT64;
		}
		ptr = ptr->next;
	}
}
