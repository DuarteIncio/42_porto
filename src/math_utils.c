/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:52:45 by dde-alme          #+#    #+#             */
/*   Updated: 2024/05/29 13:38:42 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*
 * us_num = unscaled_num;
 * old_min = 0;
 * [0..799] -> [-2..+2]
 */

double	map(double us_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (us_num - 0) / (old_max - 0) + new_min);
}

/*
 * SUM complex
 *
 * vector additions
 */
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
 * SQUARE complex
 *
 * real part = (x^2 - y^2)
 * imaginary = 2 * x * y
 */
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
