/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:44:27 by dde-alme          #+#    #+#             */
/*   Updated: 2024/05/29 14:19:58 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*
 * Put a pixell in my image buffer
 */

static	void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

/*
 * MANDELBROT:
 * z = z^2 + c
 * z initially is (0, 0)
 * c is the actual point
 */

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;

	i = 0;
	//First iteration
	z.x = 0.0;
	z.y = 0.0;

	//Pixel coordinates x && y scaled to fit mandelbrot needs
	c.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	//How many time i want to iterate z^2 + c to check
	//if the point belongs to the mandelbrot set
	while (i < fractal->iter_def)
	{
		//z = z^2 + c
		z = sum_complex(square_complex(z), c );
		//Is the value in the mandelbrot set?
		//If the hypotenuse > 2 i assume the point is no longer from the mandelbrot set
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iter_def);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	//The point is in fact in the mandelbrot set
	my_pixel_put(x, y, &fractal->img, PSYCH_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y< HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
				fractal->win,
				fractal->img.img_ptr, 0, 0);
}
