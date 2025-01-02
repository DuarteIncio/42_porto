/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:36:15 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/11 12:40:10 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)character)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)character == '\0')
		return ((char *)str);
	return (NULL);
}
