/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:01:10 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/21 14:33:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef C
# define C 16
#endif

static void	print_ascii(void *ptr, size_t size, size_t i)
{
	size_t	j;

	j = i - (C - 1);
	while (j <= i)
	{
		if (j >= size)
			ft_putchar(' ');
		else if (ft_isprint(((char *)ptr)[j]) && (((char *)ptr)[j] != '\n'))
			ft_putchar(0xFF & ((char *)ptr)[j]);
		else
			ft_putchar('.');
		j++;
	}
}

void		ft_print_memory(void *ptr, size_t size, size_t start)
{
	size_t	i;

	i = 0;
	while (i < size + ((size % C) ? (C - size % C) : 0))
	{
		if (i % C == 0)
			ft_printf("%016llx: ", start + i);
		if (i < size)
			ft_printf("%02x ", 0xff & ((char *)ptr)[i]);
		else
			ft_printf("   ");
		if (i % C == (C - 1))
		{
			print_ascii(ptr, size, i);
			ft_putchar('\n');
		}
		i++;
	}
}
