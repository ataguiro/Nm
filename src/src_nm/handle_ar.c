/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:45:55 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/09 14:54:26 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static uint8_t	valid_ptr(void *ptr)
{
	if (ptr && ((ptr - g_check.data) < (long)g_check.size))
		return (1);
	else
		return (0);
}

void			handle_ar(char *ptr)
{
	struct ar_hdr	*h;
	char			*str;
	size_t			n;
	int				i;

	g_multi = 0;
	ptr += SARMAG;
	i = -1;
	check(ptr + sizeof(struct ar_hdr));
	h = (struct ar_hdr *)(ptr);
	ptr += (ft_atoi(h->ar_size) + sizeof(struct ar_hdr));
	while (valid_ptr(ptr))
	{
		h = (struct ar_hdr *)(ptr);
		if (!ft_strncmp(h->ar_name, ARMAG, SARMAG))
			return ;
		str = ptr + sizeof(struct ar_hdr);
		ft_printf("\n%s(%s):\n", g_filename, str);
		n = ft_strlen(str);
		while ((check(str + n)) && str[n++] == 0)
			;
		handle_file(ptr + sizeof(struct ar_hdr) + n - 1);
		ptr += (ft_atoi(h->ar_size) + sizeof(struct ar_hdr));
	}
}
