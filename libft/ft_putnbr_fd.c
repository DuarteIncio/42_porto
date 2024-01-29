/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:21:58 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/13 11:19:59 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int x, int fd)
{
	char	c;

	if (x == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (x < 0)
		{
			write(fd, "-", 1);
			x = -x;
			ft_putnbr_fd(x, fd);
		}
		else if (x > 9)
		{
			ft_putnbr_fd(x / 10, fd);
			c = (x % 10) + 48;
			write(fd, &c, 1);
		}
		else
		{
			c = x + 48;
			write(fd, &c, 1);
		}
	}
}
