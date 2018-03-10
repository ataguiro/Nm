/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:58:07 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:47:42 by ataguiro         ###   ########.fr       */
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

void		type_u(int *j, va_list args)
{
	unsigned long long	rec;
	char				*done;

	if (!(fselect()->type ^ 'U'))
		rec = (unsigned long)va_arg(args, long long);
	else if (!(fselect()->modif[0] ^ 'h') && fselect()->modif[1] ^ 'h')
		rec = (unsigned short)va_arg(args, long long);
	else if (!(fselect()->modif[0] ^ 'h') && !(fselect()->modif[1] ^ 'h'))
		rec = (unsigned char)va_arg(args, long long);
	else if (!(fselect()->modif[0] ^ 'l') && fselect()->modif[1] ^ 'l')
		rec = (unsigned long)va_arg(args, long long);
	else if (!(fselect()->modif[0] ^ 'l') && !(fselect()->modif[1] ^ 'l'))
		rec = (unsigned long long)va_arg(args, long long);
	else if (!(fselect()->modif[0] ^ 'j'))
		rec = (intmax_t)va_arg(args, intmax_t);
	else if (!(fselect()->modif[0] ^ 'z'))
		rec = (size_t)va_arg(args, size_t);
	else
		rec = (unsigned int)va_arg(args, int);
	done = tl_ntoa_u(rec, 10);
	fill_main(done, j);
}
