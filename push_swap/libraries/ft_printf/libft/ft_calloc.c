/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:38:22 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/10 14:42:28 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nblocks, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nblocks * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nblocks * size);
	return (ptr);
}
