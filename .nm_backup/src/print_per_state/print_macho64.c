/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_macho64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:20 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/09 17:34:43 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	print_symbols(t_files *ptr)
{
	t_info	*tmp;
	char	type;

	tmp = ptr->info;
	while (tmp)
	{
		if (tmp->strx)
		{
			type = get_type(ptr->type);
			(!tmp->value)?ft_printf("%16s", " "):ft_printf("%016llx", tmp->value);
			ft_printf(" %c %s\n", type, tmp->strx);
		}
		tmp = tmp->next;
	}
}

static void	append_symbol(char *tmp, t_files *ptr, struct nlist_64 entry)
{
	t_info			*new;
	t_info			*head;

	head = ptr->info;
	new = (t_info *)malloc(sizeof(t_info));
	new->value = entry.n_value;
	new->strx = (void *)tmp + entry.n_un.n_strx;
	new->type = entry.n_type;
	new->sect = entry.n_sect;
	new->desc = entry.n_desc;
	new->next = NULL;
	if (!head)
		ptr->info = new;
	else
	{
		while (head->next)
				head = head->next;
		head->next = new;
	}
}

void		print_macho64(t_files *ptr)
{
	struct nlist_64	*array;
	t_parse			p;
	uint32_t		i;
	uint32_t		j;

	i = 0;
	j = 0;
	p.header64 = (struct mach_header_64 *)ptr->data;
	p.lc = (void *)ptr->data + sizeof(struct mach_header_64);
	while (i++ < p.header64->ncmds)
	{
		if (p.lc->cmd == LC_SYMTAB)
		{
			p.sym = (struct symtab_command *)p.lc;
			array = (void *)ptr->data + p.sym->symoff;
			while (j < p.sym->nsyms)
				append_symbol((void *)ptr->data + p.sym->stroff, \
						ptr, array[j++]);
		}
		j = 0;
		p.lc = (void *)p.lc + p.lc->cmdsize;
	}
	print_symbols(ptr);
}
