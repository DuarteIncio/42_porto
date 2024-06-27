/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:21:12 by dde-alme          #+#    #+#             */
/*   Updated: 2024/06/05 11:43:58 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
/*
 * ESC or press the x button in the window
 * int	(*f)(void *param)
 */

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,
			fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx,
			fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

/*
 * Using X11.keysyms to make the code more readable
 */

int	key_handle(int	keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.3 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.3 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.3 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.3 * fractal->zoom);
	else if (keysym == key_plus)
		fractal->iter_def += 10;
	else if (keysym == XK_minus)
		fractal->iter_def -= 10;
	//refresh the image
	fractal_render(fractal);
	return (0);
}

/*
 * int	(*f)(int button, int x, int y, void *param)
 */

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	//zoom in
	if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	//zoom out
	else if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	//refresh
	fractal_render(fractal);
	return (0);
}
