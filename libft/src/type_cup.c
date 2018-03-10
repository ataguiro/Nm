/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:25:49 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 13:50:36 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "ft_printf.h"
#include "tools.h"

static void	modif_other(int *j, wint_t rec, char c)
{
	int	i;
	int	diff;

	i = 0;
	diff = fselect()->lenl[0] - 1;
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = c;
	if (rec)
		fill_wchar_c(rec, j);
	else
		fselect()->final_string[(*j)++] = 0;
}

static void	modif_minus(int *j, wint_t rec)
{
	int	i;
	int	diff;

	i = 0;
	diff = fselect()->lenl[0] - 1;
	if (rec)
		fill_wchar_c(rec, j);
	else
		fselect()->final_string[(*j)++] = 0;
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = ' ';
}

void		type_cup(int *j, va_list args)
{
	wint_t	rec;

	rec = va_arg(args, wint_t);
	if (IS_ON(fselect()->args, MINUS))
		modif_minus(j, rec);
	else if (IS_ON(fselect()->args, ZERO))
		modif_other(j, rec, '0');
	else
		modif_other(j, rec, ' ');
}
