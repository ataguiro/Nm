/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datodi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:56:35 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:19:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_datodi(char **tab)
{
	int	*ret;
	int	i;
	int	size;

	i = 0;
	size = ft_tablen(tab);
	ret = (int *)ft_memalloc(sizeof(int) * size);
	--size;
	while (size >= 0)
		ret[i++] = ft_atoi(tab[size--]);
	return (ret);
}
