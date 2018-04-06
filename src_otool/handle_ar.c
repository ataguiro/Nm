/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:45:55 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/06 14:20:19 by ataguiro         ###   ########.fr       */
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

	ptr += 8;
	check(ptr + sizeof(struct ar_hdr));
	h = (struct ar_hdr *)(ptr);
	ptr += (ft_atoi(h->ar_size) + sizeof(struct ar_hdr));
	while (valid_ptr(ptr))
	{
		h = (struct ar_hdr *)(ptr);
		handle_fileo(ptr + sizeof(struct ar_hdr) + 20);
		ptr += (ft_atoi(h->ar_size) + sizeof(struct ar_hdr));
	}
}
