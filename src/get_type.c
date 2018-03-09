/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:21:36 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/09 18:06:41 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#define DO_MASK(type) (type & N_TYPE)

char	get_type(uint8_t type)
{
	char	ret;

	ret = '?';
	ret = DO_MASK(type) == N_UNDF ? 'u' : ret;
	ret = DO_MASK(type) == N_PBUD ? 'u' : ret;
	ret = DO_MASK(type) == N_ABS ? 'a' : ret;
	ret = DO_MASK(type) == N_INDR ? 'i' : ret;
	if ((type & N_EXT) && ret != '?')
		ret -= 32;
	return (ret);
}
