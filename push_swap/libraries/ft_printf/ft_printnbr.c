/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:26:39 by dde-alme          #+#    #+#             */
/*   Updated: 2023/11/02 10:28:00 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int x)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(x);
	len = ft_printstr(num);
	free(num);
	return (len);
}
