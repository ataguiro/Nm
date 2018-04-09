/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/04/09 19:39:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#define _D "%s: %s: Is a directory.\n"
#define _P "%s: %s: Permission denied.\n"
#define _N "%s: %s: No such file or directory.\n"

t_segments		g_segments = {0, 0, 0, 0};
char			*g_program = NULL;
char			*g_filename = NULL;
t_files			*g_files = NULL;
t_symbols		*g_symbols = NULL;
uint8_t			g_options = 0;
uint8_t			g_multi;
uint8_t			g_oldmulti;
uint8_t			g_error = 0;

static uint8_t	get_file_type(char *element, t_files *ptr)
{
	struct stat	buf;
	int			fd;
	int			ret;

	fd = open(element, O_RDONLY | O_NONBLOCK);
	if (-1 == fd && errno == EACCES)
		return (NO_PERMISSION);
	else if (-1 == fd)
		return (DOES_NOT_EXIST);
	ret = fstat(fd, &buf);
	if (-1 == ret)
		return (NO_PERMISSION);
	if (S_ISDIR(buf.st_mode))
		return (DIRECTORY);
	close(fd);
	ptr->size = buf.st_size;
	return (REGULAR);
}

static void		save_as_file(char *element)
{
	t_files	*ptr;
	t_files	*new;

	ptr = g_files;
	new = (t_files *)malloc(sizeof(t_files));
	if (!new)
		return ;
	new->next = NULL;
	new->filename = element;
	new->type = get_file_type(element, new);
	if (!ptr)
		g_files = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

static int		distribute(char *element)
{
	if (*element == '-')
	{
		while (*(++element))
		{
			if (*element == 'n')
				ADD_OPT(g_options, N);
			else if (*element == 'r')
				ADD_OPT(g_options, R);
			else if (*element == 'j')
				ADD_OPT(g_options, J);
			else if (*element == 'o')
				ADD_OPT(g_options, O);
			else if (*element == 'p')
				ADD_OPT(g_options, P);
			else
			{
				ft_dprintf(2, "%s: '%c' option not recognized\n", \
						g_program, *element);
				return (EXIT_FAILURE);
			}
		}
	}
	else
		save_as_file(element);
	return (EXIT_SUCCESS);
}

static int		separate_g_options_and_files(char **av)
{
	while (*av)
	{
		if (EXIT_FAILURE == distribute(*av))
			return (EXIT_FAILURE);
		av++;
	}
	return (EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	t_files	*ptr;

	g_program = av[ac ^ ac];
	if (EXIT_FAILURE == separate_g_options_and_files(av + 1))
		return (EXIT_FAILURE);
	ptr = g_files;
	(!ptr) ? save_as_file("a.out") : 0;
	ptr = g_files ? g_files : NULL;
	g_multi = (ptr && ptr->next) ? 1 : 0;
	g_oldmulti = g_multi;
	while (ptr)
	{
		if (ptr->type == DIRECTORY && (g_error = EXIT_FAILURE))
			ft_dprintf(2, _D, g_program, ptr->filename);
		else if (ptr->type == NO_PERMISSION && (g_error = EXIT_FAILURE))
			ft_dprintf(2, _P, g_program, ptr->filename);
		else if (ptr->type == DOES_NOT_EXIST && (g_error = EXIT_FAILURE))
			ft_dprintf(2, _N, g_program, ptr->filename);
		else
			nm(ptr->filename, ptr->size) ? g_error = 1 : 0;
		ptr = ptr->next;
		g_multi = g_oldmulti;
	}
	return (g_error ? EXIT_FAILURE : EXIT_SUCCESS);
}
