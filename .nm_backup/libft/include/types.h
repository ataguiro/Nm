/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:50:31 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 17:53:28 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "ft_printf.h"

/*
**	Types supported : s, d, D, x, X, o, O, u, U, c, s, S, b
*/

void	type_s(int *j, va_list args);
void	type_d(int *j, va_list args);
void	type_x(int *j, va_list args);
void	type_b(int *j, va_list args);
void	type_o(int *j, va_list args);
void	type_u(int *j, va_list args);
void	type_c(int *j, va_list args);
void	type_p(int *j, va_list args);
void	type_sup(int *j, va_list args);
void	type_cup(int *j, va_list args);

#endif
