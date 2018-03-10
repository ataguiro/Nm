/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:30:46 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/22 15:44:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PMASK 0x1
# define IS_ON(x, y) (x & PMASK << y)

# define DIEZ 0
# define ZERO 1
# define MINUS 2
# define PLUS 3
# define SPACE 4

# define MAX_LEN 40960

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# include "libft.h"
# include "types.h"

/*
**	This structures stores all informations needed about a %, and is called by
**	the fselect() singleton
*/

typedef struct		s_lenv
{
	char			final_string[MAX_LEN];
	char			result[MAX_LEN];
	int				fd;
	int				args;
	int				lenl[2];
	char			modif[3];
	char			type;
}					t_lenv;

/*
**	Main ft_printf functions
*/

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);
int					ft_fprintf(char *file, const char *restrict format, ...);

/*
**	Singleton to store all needed information
**	ex : fselect()->type
*/

t_lenv				*fselect(void);

/*
**	Main functions
**
**	parser : store all needed information about the % (flags, type, modifier...)
**	into the t_lenv structure (called by fselect singleton)
**
**	choose_type : write the argument caugth with va_arg into the buffer,
**	depending on the info recovered in fselect()
*/

int					parser(char *str, va_list args, int fd);
void				choose_type(int *j, va_list args);

/*
**	Unicode main functions
*/

void				fill_wchar_c(wint_t rec, int *j);
void				fill_wchar_s(wint_t rec, int *j, int *x);

#endif
