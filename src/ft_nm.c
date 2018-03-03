/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:33:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/03 15:30:51 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

uint8_t	options;
t_files	*g_files;
char	*av_0;

static get_file_type(char *element)
{
	struct stat	buf;
	int			fd;
	int			ret;

	fd = open(element, O_RDONLY);
	if (-1 == fd)
		ft_printf("%s: could not open \"%s\"", av_0, element);
	ret = fstat(fd, &buf);
	if (-1 == ret)
		ft_printf("%s: could not read info about \"%s\"", av_0, element);
	
}

static void	save_as_file(char *element)
{
	t_files	*ptr;
	t_files	*new;

	ptr = g_files;
	new = (t_files *)malloc(sizeof(t_files));
	new->next = NULL;
	new->filename = element;
	new->type = get_file_type(element);
	if (!ptr)
		g_files = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

static void	distribute(char *element)
{
	if (*element == '-')
	{
		element++;
		(*element == 'n') ? ADD_OPT(options, N) : 0;
		(*element == 'r') ? ADD_OPT(options, R) : 0;
		(*element == 'j') ? ADD_OPT(options, J) : 0;
		(*element == 'o') ? ADD_OPT(options, O) : 0;
		(*element == 'A') ? ADD_OPT(options, A) : 0;
	}
	else
		save_as_file(element);
}

static void	separate_options_and_files(char **av)
{
	while (*av)
	{
		distribute(*av);
		av++;
	}
}

int			main(int ac, char **av)
{
	av[ac] = NULL;
	av_0 = av[0];
	separate_options_and_files(av);
}
