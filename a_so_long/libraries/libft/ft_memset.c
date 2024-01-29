/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:29:03 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/11 10:35:23 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (size-- > 0)
	{
		*ptr = (unsigned char)x;
		ptr++;
	}
	return (str);
}
