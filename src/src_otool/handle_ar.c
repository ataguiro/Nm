/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:45:55 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/09 15:00:01 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static uint8_t	valid_ptr(void *ptr)
{
	if (!g_c && ptr && ((ptr - g_check.data) < (long)g_check.size))
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

	g_multi = 5;
	ft_printf("Archive : %s\n", g_filename);
	ptr += SARMAG;
	i = -1;
	check(ptr + sizeof(struct ar_hdr));
	h = g_c ? NULL : (struct ar_hdr *)(ptr);
	!g_c ? ptr += (ft_atoi(h->ar_size) + sizeof(struct ar_hdr)) : 0;
	while (valid_ptr(ptr))
	{
		h = (struct ar_hdr *)(ptr);
		if (!check(h->ar_name) || !ft_strncmp(h->ar_name, ARMAG, SARMAG))
			return ;
		str = ptr + sizeof(struct ar_hdr);
		ft_printf("%s(%s):\n", g_filename, str);
		n = ft_strlen(str);
		while ((check(str + n)) && str[n++] == 0)
			;
		!g_c ? handle_fileo(ptr + sizeof(struct ar_hdr) + n - 1) : 0;
		!g_c ? ptr += (ft_atoi(h->ar_size) + sizeof(struct ar_hdr)) : 0;
	}
}
