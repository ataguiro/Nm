/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:35:34 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/12 13:38:05 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint16_t	swap_uint16(uint16_t n)
{
	return (n << 8) | (n >> 8 );
}

uint32_t	swap_uint32(uint32_t n)
{
	n = ((n << 8) & 0xFF00FF00 ) | ((n >> 8) & 0xFF00FF ); 
	return (n << 16) | (n >> 16);
}

uint64_t	swap_uint64(uint64_t n)
{
	n = ((n << 8) & 0xFF00FF00FF00FF00ULL ) \
		| ((n >> 8) & 0x00FF00FF00FF00FFULL );
	n = ((n << 16) & 0xFFFF0000FFFF0000ULL ) \
		| ((n >> 16) & 0x0000FFFF0000FFFFULL );
	return (n << 32) | (n >> 32);
}
