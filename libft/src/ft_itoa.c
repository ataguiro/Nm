/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 12:48:04 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/06 16:32:05 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	t_itoa	gp;

	gp.i = 0;
	gp.nb = n;
	gp.negative = (gp.nb < 0) ? 1 : 0;
	if ((gp.buff = ft_strnew(ft_intlength(gp.nb))) == NULL)
		return (NULL);
	if (gp.negative)
		gp.buff[0] = '-';
	gp.nb = (gp.negative) ? -(gp.nb) : gp.nb;
	gp.i = ft_intlength(gp.nb) - 1;
	while (gp.i >= 0)
	{
		gp.buff[gp.i-- + gp.negative] = (gp.nb % 10) + 48;
		gp.nb /= 10;
	}
	gp.buff[ft_strlen(gp.buff)] = 0;
	return (gp.buff);
}
