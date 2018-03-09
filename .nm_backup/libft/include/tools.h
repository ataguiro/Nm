/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:39:42 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:53:53 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "libft.h"

/*
**	Tool-functions needed
**
**	tl_focuscpy : copies src into dst ignoring all -1 chars
**	tl_isinstr : returns 1 if c is found in the str string, 0 otherwise
**	etc.
*/

char	*tl_focuscpy(char *dst, char *src);
int		tl_isinstr(char c, char *str);
int		tl_strnlen(char *str, int n);
int		tl_wstrnlen(wchar_t *str, int n);
char	*tl_ntoa(long long n, int base);
char	*tl_ntoa_16(unsigned long long n, int base);
char	*tl_ntoa_8(unsigned long long n, int base);
char	*tl_ntoa_2(unsigned long long n, int base);
char	*tl_ntoa_u(unsigned long long n, int base);

#endif
