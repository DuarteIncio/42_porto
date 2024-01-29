/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:39:48 by dde-alme          #+#    #+#             */
/*   Updated: 2023/11/02 11:02:49 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int x)
{
	char	*num;
	int		len;

	len = ft_num_len(x);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (x != 0)
	{
		num[len - 1] = x % 10 + '0';
		x = x / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int x)
{
	int		len;
	char	*num;

	len = 0;
	if (x == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(x);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
