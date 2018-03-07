/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:36 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/07 14:00:55 by ataguiro         ###   ########.fr       */
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
# define A 5

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

typedef struct		s_files
{
	struct s_files	*next;
	char			*filename;
	char			*data;
	uint8_t			type;
	uint8_t			state;
}					t_files;

extern uint8_t		options;
extern t_files		*g_files;
extern char			*av_0;

void	parse_and_display(void);
void	fill_file_state(void);

void	print_macho32(t_files *ptr);
void	print_macho64(t_files *ptr);
void	print_fat32(t_files *ptr);
void	print_fat64(t_files *ptr);
void	print_ar(t_files *ptr);

#endif
