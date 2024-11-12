/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:54:04 by dde-alme          #+#    #+#             */
/*   Updated: 2023/11/02 12:04:25 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
/*
int	main(void)
{
	unsigned int	num1 = 456;
	unsigned int	num2 = 400;
	unsigned int	num3 = 0;

	printf("Testing ft_print_hex:\n");
	printf("Number 1 (format 'X'):\n ");
	int	len1 = ft_print_hex(num1, 'X');
	printf("\nLenght: %d\n\n", len1);

	printf("Number 2 (format 'X'):\n ");
	int	len2 = ft_print_hex(num2, 'X');
	printf("\nLenght: %d\n\n", len2);

	printf("Number 3 (format 'x'):\n ");
	int	len3 = ft_print_hex(num3, 'x');
	printf("\nLenght: %d\n\n", len3);
}*/
