/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:19:37 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/05 18:42:06 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	redistribute_per_state(t_files *ptr)
{
	(void)ptr;
}

void	parse_and_display(void)
{
	t_files	*ptr;

	ptr = g_files;
	fill_file_state();
	t_files *tmp;
	tmp = g_files;
	while (tmp)
	{
		char t[36];
		printf("-------------------------------------\n");
		printf("Path:\t\t%s\n", tmp->filename);
		if (tmp->type == 1) strcpy(t, "\033[1;31mDIRECTORY\033[0m");
		if (tmp->type == 0) strcpy(t, "\033[1;32mREGULAR\033[0m");
		if (tmp->type == 2) strcpy(t, "\033[1;31mNO PERMISSION\033[0m");
		if (tmp->type == 3) strcpy(t, "\033[1;31mDOES_NOT_EXIST\033[0m");
		printf("Type:\t\t%s\n", t);
		if (tmp->state == MACHO32) strcpy(t, "\033[1;32mMACHO 32 bits\033[0m");
		if (tmp->state == MACHO64) strcpy(t, "\033[1;32mMACHO 64 bits\033[0m");
		if (tmp->state == FAT32) strcpy(t, "\033[1;32mFAT 32 bits\033[0m");
		if (tmp->state == FAT64) strcpy(t, "\033[1;32mFAT 64 bits\033[0m");
		if (tmp->state == AR) strcpy(t, "\033[1;32mAR Library\033[0m");
		if (tmp->state == NONE) strcpy(t, "\033[1;31mNot recognized\033[0m");
		printf("State:\t\t%s\n", t);
		printf("Next:\t\t%p\n", tmp->next);
		tmp = tmp->next;
	}
	while (ptr)
	{
		if (ptr->type == DIRECTORY)
			ft_dprintf(2, "%s: %s: Is a directory.\n", av_0, ptr->filename);
		else if (ptr->type == NO_PERMISSION)
			ft_dprintf(2, "%s: %s: Permission denied.\n", av_0, ptr->filename);
		else if (ptr->type == DOES_NOT_EXIST)
			ft_dprintf(2, "%s: %s: No such file or directory.\n", av_0, ptr->filename);
		else
			redistribute_per_state(ptr);
		ptr = ptr->next;
	}
}
