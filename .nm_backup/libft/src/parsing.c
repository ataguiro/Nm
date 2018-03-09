/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:14:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 18:43:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tools.h"
#include <stdio.h>

/*
**	x = 0x0
**
**	# : x |= 0x1
**	0 : x |= (0x1 << 1)
**	- : x |= (0x1 << 2)
**	+ : x |= (0x1 << 3)
**	  : x |= (0x1 << 4)
*/

static int	get_lenl(char *str)
{
	int		i;
	int		j;
	int		stop;
	char	rec[32];

	i = -1;
	j = 0;
	stop = 0;
	while (ft_isdigit(str[++i]))
		rec[i] = str[i];
	rec[i] = 0;
	fselect()->lenl[0] = ft_atoi(rec);
	if (str[i] == '.' && (stop = 1))
		i++;
	while (ft_isdigit(str[i]))
		rec[j++] = str[i++];
	rec[j] = 0;
	j = ft_atoi(rec);
	fselect()->lenl[1] |= j || stop ? j : -1;
	return (i);
}

static int	get_args(char *str)
{
	int	i;

	i = 0;
	while (tl_isinstr(str[++i], "#+-0 "))
	{
		if (str[i] == '#')
			fselect()->args |= PMASK;
		else if (str[i] == '0')
			fselect()->args |= PMASK << 1;
		else if (str[i] == '-')
			fselect()->args |= PMASK << 2;
		else if (str[i] == '+')
			fselect()->args |= PMASK << 3;
		else if (str[i] == ' ')
			fselect()->args |= PMASK << 4;
	}
	return (i);
}

static int	get_modif(char *str)
{
	int	i;

	i = -1;
	while (tl_isinstr(str[++i], "hlzj"))
		fselect()->modif[i] = str[i];
	fselect()->modif[2] = 0;
	fselect()->type = str[i];
	return (++i);
}

static void	init_parsing(void)
{
	fselect()->args = 0;
	fselect()->lenl[0] = 0;
	fselect()->lenl[1] = 0;
	fselect()->type = 0;
	ft_memset(fselect()->modif, 0, 3);
}

int			parser(char *str, va_list args, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_parsing();
			i += get_args(&str[i]);
			i += get_lenl(&str[i]);
			i += get_modif(&str[i]);
			choose_type(&j, args);
		}
		else
			fselect()->final_string[j++] = str[i++];
	}
	write(fd, fselect()->final_string, j);
	return (j);
}
