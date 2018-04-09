/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:36 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/09 14:32:55 by ataguiro         ###   ########.fr       */
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
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <mach-o/ranlib.h>
# include <ar.h>
# include <sys/mman.h>

# include <sys/stat.h>

# include "libft.h"

# define ISON(x, y) (x & (1 << y))
# define ADD_OPT(x, y) (x |= (1 << y))

# define N 0
# define P 1
# define R 2
# define O 3
# define J 4

# define T 0
# define D 1
# define B 2
# define A 3

/*
** Basic file types and errors
*/

# define REGULAR		0
# define DIRECTORY		1
# define NO_PERMISSION	2
# define DOES_NOT_EXIST	3

/*
** AR Magic number
*/

# define AR_MAGIC		0x0a3e686372613c21
# define AR_CIGAM		0x213c617263683e0a

typedef struct					s_parse
{
	struct mach_header			*header;
	struct mach_header_64		*header64;
	struct fat_header			*fathdr;
	struct fat_arch				*fatarch;
	struct fat_arch_64			*fatarch64;
	struct load_command			*lc;
	struct segment_command		*sc;
	struct segment_command_64	*sc64;
	struct section				*section;
	struct section_64			*section64;
	struct nlist				*array;
	struct nlist_64				*array64;
	struct symtab_command		*sym;
}								t_parse;

typedef struct					s_symbols
{
	uint64_t					value;
	char						*name;
	uint8_t						sect;
	char						type;
}								t_symbols;

typedef struct					s_segments
{
	uint64_t					text;
	uint64_t					bss;
	uint64_t					data;
	uint64_t					k;
}								t_segments;

typedef struct					s_files
{
	size_t						size;
	struct s_files				*next;
	char						*filename;
	char						*data;
	uint8_t						type;
}								t_files;

/*
** The only purpose of this structure is to check file curruption
*/

typedef struct					s_check
{
	size_t						size;
	void						*data;
}								t_check;

extern t_check					g_check;

extern t_segments				g_segments;
extern t_symbols				*g_symbols;
extern t_files					*g_files;
extern uint8_t					g_options;

extern char						*g_program;
extern char						*g_filename;
extern uint8_t					g_multi;

int								nm(char *ptr, size_t n);
int								otool(char *ptr, size_t n);

void							*check(void *ptr);
void							*check_bad_string(void *ptr);

int								handle_file(char *ptr);
int								handle_fileo(char *ptr);

void							handle_macho32(char *ptr);
void							handle_macho32o(char *ptr);
void							handle_macho64(char *ptr);
void							handle_macho64o(char *ptr);
void							handle_fat32(char *ptr);
void							handle_fat64(char *ptr);
void							handle_ar(char *ptr);

void							clear_globals(void);

uint16_t						swap_uint16(uint16_t n);
uint32_t						swap_uint32(uint32_t n);
uint64_t						swap_uint64(uint64_t n);

void							sort(size_t size);

void							*secure_malloc(size_t size);

#endif
