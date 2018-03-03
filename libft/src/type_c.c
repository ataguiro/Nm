/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:25:49 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 12:21:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tools.h"

static void	modif_other(int *j, char rec, char c)
{
	int	i;
	int	diff;

	i = 0;
	diff = fselect()->lenl[0] - 1;
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = c;
	if (rec)
		fselect()->final_string[(*j)++] = rec;
	else
		fselect()->final_string[(*j)++] = 0;
}

static void	modif_minus(int *j, char rec)
{
	int	i;
	int	diff;

	i = 0;
	diff = fselect()->lenl[0] - 1;
	if (rec)
		fselect()->final_string[(*j)++] = rec;
	else
		fselect()->final_string[(*j)++] = 0;
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = ' ';
}

void		type_c(int *j, va_list args)
{
	char	rec;

	if (!(fselect()->modif[0] ^ 'l') && fselect()->modif[1] ^ 'l')
		type_cup(j, args);
	else
	{
		if (!(fselect()->type ^ 'c'))
			rec = (char)va_arg(args, int);
		else
			rec = fselect()->type;
		if (IS_ON(fselect()->args, MINUS))
			modif_minus(j, rec);
		else if (IS_ON(fselect()->args, ZERO))
			modif_other(j, rec, '0');
		else
			modif_other(j, rec, ' ');
	}
}
