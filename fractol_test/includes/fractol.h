/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:54:21 by dde-alme          #+#    #+#             */
/*   Updated: 2024/07/23 11:48:13 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <real_value> <imaginary_value>\""

//I use a square to keep the rendering math simple

#define WIDTH	800
#define HEIGHT	800

/*
 * COLORS
 */

#define BLACK	0x000000
#define WHITE	0xFFFFFF
#define RED	0xFF0000
#define GREEN	0x00FF00
#define BLUE	0x0000FF

#define	MAGENTA_BURST	0xFF00FF
#define LIME_SHOCK	0xCCFF00
#define	NEON_ORANGE	0xFF6600
#define	PSYCH_PURPLE	0x660066
#define	AQUA_DREAM	0x33CCCC
#define	ELETRIC_BLUE	0x0066FF
#define	LAVA_RED	0xFF3300

/*
 * Key
 */

#define key_plus	65451

/*
 *COMPLEX value
 */
typedef struct	s_complex
{
	//Real
	double	x;
	//Imaginary
	double	y;
}		t_complex;

/*
 * Image
 * This is basically a pixels buffer
 * Values from mlx_get_data_addr
 */
typedef struct	s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels; //points to the actual pixels
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;
/*
 * FRACTAL ID
 * MLX stuff
 * Image
 * Hooks values
 */
typedef struct	s_fractal
{
	char	*name;
	//MLX
	void	*mlx; //mlx_init
	void	*win; //mlx_new_window
	//Image
	t_img	img;
	//Hooks member variables TODO
	double	escape_value;
	int	iter_def; //Value tight with the image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}		t_fractal;

/*
 * PROTOTYPES
 */
//*** init ***
void		fractal_init(t_fractal *fractal);

//*** render ***
void		fractal_render(t_fractal *fractal);

//*** math_utils ***
double  	map(double us_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		atodbl(char *s);

//*** hook_events ***
int	key_handle(int keysym, t_fractal *fractal);
int	mouse_handle(int button, int x, int y, t_fractal *fractal);
//int	julia_track(int x, int y, t_fractal *fractal);

//*** clean_up ***
int	close_handle(t_fractal *fractal);

#endif
