/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:02:58 by dde-alme          #+#    #+#             */
/*   Updated: 2024/06/05 10:59:08 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*
 * If MALLOC goes wrong (improbable)
 */
static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iter_def = 300;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win,
		KeyPress,
		KeyPressMask,
		key_handle,
		fractal);
	mlx_hook(fractal->win,
		ButtonPress,
		ButtonPressMask,
		mouse_handle,
		fractal);
	mlx_hook(fractal->win,
		DestroyNotify,
		StructureNotifyMask,
		close_handle,
		fractal);
}

/*
 * Init
 * ~mlx
 * ~listening events
 * ~hooks data
 */
void	fractal_init(t_fractal *fractal)
{
	//MLX stuff
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();//TODO
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img_ptr,
						&fractal->img.bpp,
						&fractal->img.line_len,
						&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
	
