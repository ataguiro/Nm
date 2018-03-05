/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:36 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/05 15:00:30 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# include <mach-o/loader.h>
# include <mach-o/swap.h>

#include <sys/stat.h>

# include "libft.h"

# define ISON(x, y) (x & 1 << y)
# define ADD_OPT(x, y) (x |= 1 << y)

# define N 1
# define R 2
# define J 3
# define O 4
# define A 5

# define REGULAR		0
# define DIRECTORY		1
# define NO_PERMISSION	2
# define DOES_NOT_EXIST	3

typedef struct		s_files
{
	struct s_files	*next;
	char			*filename;
	uint8_t			type;
}					t_files;

extern uint8_t		options;
extern t_files		*g_files;
extern char			*av_0;

void	parse_and_display(void);

#endif
