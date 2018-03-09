/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:19:37 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/09 17:02:51 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	redistribute_per_state(t_files *ptr)
{
	if (ptr->state == MACHO32)
		print_macho32(ptr);
	else if (ptr->state == MACHO64)
		print_macho64(ptr);
	else if (ptr->state == FAT32)
		print_fat32(ptr);
	else if (ptr->state == FAT64)
		print_fat64(ptr);
	else if (ptr->state == AR)
		print_ar(ptr);
}

void		parse_and_display(void)
{
	t_files	*ptr;

	ptr = g_files;
	fill_file_state();
	while (ptr)
	{
		if (ptr->type == DIRECTORY)
			ft_dprintf(2, "%s: %s: Is a directory.\n", av_0, ptr->filename);
		else if (ptr->type == NO_PERMISSION)
			ft_dprintf(2, "%s: %s: Permission denied.\n", av_0, ptr->filename);
		else if (ptr->type == DOES_NOT_EXIST)
			ft_dprintf(2, "%s: %s: No such file or directory.\n", av_0, ptr->filename);
		else if (ptr->state == NONE)
			ft_dprintf(2, "%s: %s The file was not recognized as a valid object file\n\n", av_0, ptr->filename);
		else
			redistribute_per_state(ptr);
		ptr = ptr->next;
	}
}
