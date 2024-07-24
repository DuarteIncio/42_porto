/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:39:25 by dde-alme          #+#    #+#             */
/*   Updated: 2024/07/17 11:39:02 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
		|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
			fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
