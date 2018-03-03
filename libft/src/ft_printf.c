/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:21:34 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 18:10:17 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "ft_printf.h"
#include "tools.h"

int			ft_printf(const char *restrict format, ...)
{
	va_list	args;
	char	str[512];

	va_start(args, format);
	ft_strncpy((char *)str, (char *)format, 512);
	return (parser(str, args, 1));
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	args;
	char	str[512];

	va_start(args, format);
	ft_strncpy((char *)str, (char *)format, 512);
	return (parser(str, args, fd));
}

int			ft_fprintf(char *file, const char *restrict format, ...)
{
	va_list	args;
	int		fd;
	int		ret;
	char	str[512];

	fd = open(file, O_RDWR | O_CREAT, 0664);
	va_start(args, format);
	ft_strncpy((char *)str, (char *)format, 512);
	ret = parser(str, args, fd);
	close(fd);
	return (ret);
}
