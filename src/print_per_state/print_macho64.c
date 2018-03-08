/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_macho64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:20 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/08 15:14:46 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_macho64(t_files *ptr)
{
	t_parse	p;
	int		i;

	i = 0;
	p.header64 = (struct mach_header_64 *) ptr->data;
	p.lc = (struct symtab_command *) (ptr->data 
		\ + sizeof(struct mach_header_64));
	while (i < p.header64->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			printf("I found a symbol!\n");
		}
		++i;
	}
}
