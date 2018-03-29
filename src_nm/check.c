/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:14:09 by ataguiro          #+#    #+#             */
/*   Updated: 2018/03/29 18:46:36 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	*check(void *ptr)
{
	//printf("Checking %p...\ndata_start:\t\t%zu\nrequested_ptr:\t\t%zu\nsize_of_mmap:\t\t%zu\ndifference:\t\t%ld\n", ptr, (size_t)g_check.data, (size_t)ptr, (size_t)g_check.size, (long)((ptr - g_check.data)));

	if (ptr && ((ptr - g_check.data) < (long)g_check.size))
		return (ptr);
	else
	{
		ft_dprintf(2, "%s: %s: corrupted file\n", program, filename);
		exit(EXIT_FAILURE);
	}
}
