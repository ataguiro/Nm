/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:38:56 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/14 17:46:33 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_readline(char *line, const int fd)
{
	int		ret;
	char	buffer[2];

	ft_memset(line, 0, 24);
	ft_memset(buffer, 0, 2);
	while ((ret = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] != '\n')
			ft_strcat(line, buffer);
		else
			return (1);
	}
	if (line[0])
		return (1);
	return (ret);
}
