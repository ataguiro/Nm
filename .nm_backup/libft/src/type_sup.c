/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:25:49 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:20:32 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tools.h"
#include <wchar.h>
#define NULL_BAK "(null)\0"

static int	check_unicode(wint_t *rec)
{
	int	i;

	i = 0;
	while (rec[i])
	{
		if (rec[i] >= 0x0080)
			return (1);
		i++;
	}
	return (0);
}

static void	modif_other(int *j, wint_t *rec, char c, int tmp)
{
	int	i;
	int	x;
	int	diff;

	i = -1;
	x = 0;
	diff = fselect()->lenl[0] - tl_wstrnlen(rec, fselect()->lenl[1]);
	if (tmp != -1 && fselect()->lenl[0] > tmp && fselect()->lenl[0] && tmp)
		diff = fselect()->lenl[0] - tl_strnlen((char *)rec, fselect()->lenl[1])
		- check_unicode(rec);
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = c;
	while (rec[++i] && x < fselect()->lenl[1])
		fill_wchar_s(rec[i], j, &x);
}

static void	modif_minus(int *j, wint_t *rec, int tmp)
{
	int	i;
	int	diff;
	int	x;

	i = -1;
	x = 0;
	diff = fselect()->lenl[0] - tl_wstrnlen(rec, fselect()->lenl[1]);
	if (tmp != -1 && fselect()->lenl[0] > tmp && fselect()->lenl[0] && tmp)
		diff = fselect()->lenl[0] - tl_strnlen((char *)rec, fselect()->lenl[1])
		- check_unicode(rec);
	while (rec[++i] && x < (fselect()->lenl[1]))
		fill_wchar_s(rec[i], j, &x);
	while (diff-- > 0)
		fselect()->final_string[(*j)++] = ' ';
}

void		type_sup(int *j, va_list args)
{
	wint_t	*rec;
	wint_t	backup[7];
	int		i;
	int		tmp;

	i = -1;
	rec = va_arg(args, wint_t *);
	if (!rec)
	{
		while (++i < 7)
			backup[i] = NULL_BAK[i];
		rec = backup;
	}
	tmp = fselect()->lenl[1];
	tmp == -1 ? fselect()->lenl[1] = 0x7fffffff : 0;
	if (IS_ON(fselect()->args, MINUS))
		modif_minus(j, rec, tmp);
	else if (IS_ON(fselect()->args, ZERO))
		modif_other(j, rec, '0', tmp);
	else
		modif_other(j, rec, ' ', tmp);
}
