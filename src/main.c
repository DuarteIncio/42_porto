/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:39:25 by dde-alme          #+#    #+#             */
/*   Updated: 2024/05/29 14:14:34 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * I can have 2 prompts:
 * 	./fractol mandelbrot
 * 	./fractol julia <real> <imaginary>
 *
 * The main function is a TL;DR of your application
 */
#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
		|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		//Prompt correct = Kick off the application;
		//1)
		fractal_init(&fractal);
		//2)
		fractal_render(&fractal);
		//3)
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
