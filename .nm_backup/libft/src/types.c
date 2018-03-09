/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:08:53 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:57:38 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_type(int *j, va_list args)
{
	if (!(fselect()->type ^ 's'))
		type_s(j, args);
	else if (!(fselect()->type ^ 'd') || !(fselect()->type ^ 'i')
	|| !(fselect()->type ^ 'D'))
		type_d(j, args);
	else if (!(fselect()->type ^ 'x') || !(fselect()->type ^ 'X'))
		type_x(j, args);
	else if (!(fselect()->type ^ 'o') || !(fselect()->type ^ 'O'))
		type_o(j, args);
	else if (!(fselect()->type ^ 'u') || !(fselect()->type ^ 'U'))
		type_u(j, args);
	else if (!(fselect()->type ^ 'c'))
		type_c(j, args);
	else if (!(fselect()->type ^ 'p'))
		type_p(j, args);
	else if (!(fselect()->type ^ 'C'))
		type_cup(j, args);
	else if (!(fselect()->type ^ 'S'))
		type_sup(j, args);
	else if (!(fselect()->type ^ 'b'))
		type_b(j, args);
	else if (fselect()->type)
		type_c(j, args);
}
