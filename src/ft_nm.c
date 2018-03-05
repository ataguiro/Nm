/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/05 16:58:59 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

uint8_t	options;
t_files	*g_files = NULL;
char	*av_0;

static uint8_t	get_file_type(char *element)
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
	close(fd);
	return (S_ISDIR(buf.st_mode) ? DIRECTORY : REGULAR);
}

static void		save_as_file(char *element)
{
	t_files	*ptr;
	t_files	*new;

	ptr = g_files;
	new = (t_files *)malloc(sizeof(t_files));
	new->next = NULL;
	new->filename = element;
	new->type = get_file_type(element);
	new->state = NONE;
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
		element++;
		while (*element)
		{
			if (*element == 'n')
				ADD_OPT(options, N);
			else if (*element == 'r')
				ADD_OPT(options, R);
			else if (*element == 'j')
				ADD_OPT(options, J);
			else if (*element == 'o')
				ADD_OPT(options, O);
			else if (*element == 'A')
				ADD_OPT(options, A);
			else
			{
				ft_dprintf(2, "%s: '%c' option not recognized\n", av_0, *element);
				exit(EXIT_FAILURE);
			}
			element++;
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
	av[ac] = NULL;
	av_0 = av[0];
	separate_options_and_files(av + 1);

	ft_printf("options: %b\n", options);
	parse_and_display();
}
