/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:36 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/09 17:34:01 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# include <mach-o/loader.h>
# include <mach-o/swap.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>

# include <sys/mman.h>

#include <sys/stat.h>

# include "libft.h"

# define ISON(x, y) (x & 1 << y)
# define ADD_OPT(x, y) (x |= 1 << y)

# define N 1
# define R 2
# define J 3
# define O 4
# define P 5

/*
** Basic file types and errors
*/

# define REGULAR		0
# define DIRECTORY		1
# define NO_PERMISSION	2
# define DOES_NOT_EXIST	3

/*
** Advanced regular files states
*/

# define MACHO32		32
# define MACHO64		64
# define FAT32			33
# define FAT64			65
# define AR				0
# define NONE			1

/*
** AR Magic number
*/

# define AR_MAGIC		0x0a3e686372613c21
# define AR_CIGMA		0x213c617263683e0a

typedef struct				s_files
{
	struct s_file			*next;
	char					*filename;
	uint8_t					type;
}							t_files;

extern t_files				*g_files;
extern uint8_t				options;
extern char					*program;

#endif
