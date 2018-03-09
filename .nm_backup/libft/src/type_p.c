/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:58:07 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:19:41 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tools.h"

static void	fill_main(char *done, int *j)
{
	int	i;

	i = -1;
	while (done[++i])
		fselect()->final_string[(*j)++] = done[i];
}

void		type_p(int *j, va_list args)
{
	unsigned long long	rec;
	char				*done;

	rec = (unsigned long long)va_arg(args, void *);
	fselect()->args |= PMASK;
	done = tl_ntoa_16(rec, 16);
	fill_main(done, j);
}
