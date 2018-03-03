/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:30:54 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/04 13:35:49 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_checkandfree(char *tmp, char **stock, char **line)
{
	char *tmp1;
	char *tmp2;

	if (!(tmp1 = ft_strchr(tmp, '\n')))
		return (0);
	*tmp1 = 0;
	tmp2 = *line;
	*line = ft_strnew(ft_strlen(tmp) + ft_strlen(tmp2));
	ft_strcpy(*line, tmp2);
	ft_strcat(*line, tmp);
	free(tmp2);
	*stock = ft_strdup(tmp1 + 1);
	return (1);
}

static void	ft_update_it(char **line, char *buf)
{
	char	*tmp;

	if (!(*line))
	{
		*line = ft_strnew(ft_strlen(buf));
		ft_strcpy(*line, buf);
	}
	tmp = *line;
	*line = ft_strnew(ft_strlen(buf) + ft_strlen(tmp));
	ft_strcpy(*line, tmp);
	ft_strcat(*line, buf);
	free(tmp);
}

static int	ft_isup(char **stock, char **line)
{
	char	*tmp;
	char	*buf;

	if (!(buf = ft_strchr(*stock, '\n')))
	{
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = NULL;
	}
	else
	{
		*buf = 0;
		*line = ft_strdup(*stock);
		tmp = *stock;
		*stock = ft_strdup(buf + 1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			tmp[BUFF_SIZE + 1];
	int				r;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (stock && ft_isup(&stock, line))
		return (1);
	while ((r = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (r < 0)
			return (-1);
		tmp[r] = 0;
		if (ft_checkandfree(tmp, &stock, line))
			return (1);
		ft_update_it(line, tmp);
	}
	if (!r && (*line)[0])
		return (1);
	return (r);
}
