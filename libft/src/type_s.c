/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:25:49 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 12:25:16 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tools.h"
#define NULL_BAK "(null)\0"

static void	modif_other(int *j, char *rec, char c)
{
	int	i;
	int	diff;

	i = 0;
	diff = fselect()->lenl[0] - tl_strnlen(rec, fselect()->lenl[1]);
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = c;
	while (rec[i] && i < fselect()->lenl[1])
		fselect()->final_string[(*j)++] = rec[i++];
}

static void	modif_minus(int *j, char *rec)
{
	int	i;
	int	diff;

	i = 0;
	diff = fselect()->lenl[0] - tl_strnlen(rec, fselect()->lenl[1]);
	while (rec[i] && i < fselect()->lenl[1])
		fselect()->final_string[(*j)++] = rec[i++];
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = ' ';
}

void		type_s(int *j, va_list args)
{
	char	*rec;
	int		i;
	char	backup[7];

	i = -1;
	if (!(fselect()->modif[0] ^ 'l') && fselect()->modif[1] ^ 'l')
		type_sup(j, args);
	else
	{
		rec = va_arg(args, char *);
		if (!rec)
		{
			while (++i < 7)
				backup[i] = NULL_BAK[i];
			rec = backup;
		}
		fselect()->lenl[1] == -1 ? fselect()->lenl[1] = 0x7fffffff : 0;
		if (IS_ON(fselect()->args, MINUS))
			modif_minus(j, rec);
		else if (IS_ON(fselect()->args, ZERO))
			modif_other(j, rec, '0');
		else
			modif_other(j, rec, ' ');
	}
}
