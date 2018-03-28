/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/28 15:00:36 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_segments	g_segments = {0, 0, 0, 0};
char		*program = NULL;
char		*filename = NULL;
t_files		*g_files = NULL;
t_symbols	*g_symbols = NULL;
uint8_t		options = 0;
uint8_t		g_multi;

static uint8_t	get_file_type(char *element, t_files *ptr)
{
	struct stat	buf;
	int			fd;
	int			ret;

	fd = open(element, O_RDONLY);
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

static void		distribute(char *element)
{
	if (*element == '-')
	{
		while (*(++element))
		{
			if (*element == 'n')
				ADD_OPT(options, N);
			else if (*element == 'r')
				ADD_OPT(options, R);
			else if (*element == 'j')
				ADD_OPT(options, J);
			else if (*element == 'o')
				ADD_OPT(options, O);
			else if (*element == 'p')
				ADD_OPT(options, P);
			else
			{
				ft_dprintf(2, "%s: '%c' option not recognized\n", \
						program, *element);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
		save_as_file(element);
}

static void		separate_options_and_files(char **av)
{
	while (*av)
	{
		distribute(*av);
		av++;
	}
}

int				main(int ac, char **av)
{
	t_files				*ptr;

	av[ac] = NULL;
	program = av[0];
	separate_options_and_files(av + 1);
	ptr = g_files;
	(!ptr) ? save_as_file("a.out") : 0;
	ptr = g_files;
	g_multi = (ptr->next) ? 1 : 0;
	while (ptr)
	{
		if (ptr->type == DIRECTORY)
			ft_dprintf(2, "%s: %s: Is a directory.\n", program, ptr->filename);
		else if (ptr->type == NO_PERMISSION)
			ft_dprintf(2, "%s: %s: Permission denied.\n", program, ptr->filename);
		else if (ptr->type == DOES_NOT_EXIST)
			ft_dprintf(2, "%s: %s: No such file or directory.\n", program, ptr->filename);
		else
			nm(ptr->filename, ptr->size);
		ptr = ptr->next;
	}
}
