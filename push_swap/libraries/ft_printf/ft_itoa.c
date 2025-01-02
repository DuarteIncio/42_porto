/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <dde-alme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:47:58 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/20 15:19:52 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(int x)
{
	int	size;

	size = 0;
	if (x <= 0)
		size++;
	while (x != 0)
	{
		x = x / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_res(int size, int offset, int x, char *res)
{
	while (size > offset)
	{
		res[size - 1] = x % 10 + '0';
		x = x / 10;
		size--;
	}
}

char	*ft_itoa(int x)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = ft_get_size(x);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (x == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		x = 147483648;
		offset = 2;
	}
	if (x < 0)
	{
		res[0] = '-';
		offset = 1;
		x = -x;
	}
	ft_fill_res(size, offset, x, res);
	res[size] = '\0';
	return (res);
}
