/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_macho64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:20 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/08 16:37:12 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	print_symbols(struct symtab_command *sym, t_files *ptr)
{
	struct nlist_64	*array;
	char			*tmp;
	uint32_t		i;

	i = 0;
	array = (void *)ptr->data + sym->symoff;
	tmp = (void *)ptr->data + sym->stroff;
	while (i++ < sym->nsyms)
	{
		printf("%x %hhx %hhx %hx %s\n", (uint32_t)(tmp + array[i].n_value), (uint8_t)(tmp + array[i].n_type), (uint8_t)(tmp + array[i].n_sect), (uint16_t)(tmp + array[i].n_desc), tmp + array[i].n_un.n_strx);
	}
}

void		print_macho64(t_files *ptr)
{
	t_parse		p;
	uint32_t	i;

	printf("printing 64\n");
	i = 0;
	p.header64 = (struct mach_header_64 *)ptr->data;
	p.lc = (void *)ptr->data + sizeof(struct mach_header_64);
	while (i++ < p.header64->ncmds)
	{
		if (p.lc->cmd == LC_SYMTAB)
		{
			p.sym = (struct symtab_command *)p.lc;
			print_symbols(p.sym, ptr);
		}
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
}
