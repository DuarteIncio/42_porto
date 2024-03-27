/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:31:59 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/11 09:34:56 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int character, size_t size)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)str;
	while (size-- > 0)
	{
		if (*ptr == (unsigned char)character)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
