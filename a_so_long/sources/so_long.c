/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:02:10 by dde-alme          #+#    #+#             */
/*   Updated: 2024/01/24 10:39:33 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	key_press(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		exit (0);
	if (keycode == 119 || keycode == 65362)
		data->game->player_up = 1;
	if (keycode == 115 || keycode == 65364)
		data->game->player_down = 1;
	if (keycode == 97 || keycode == 65361)
		data->game->player_left = 1;
	if (keycode == 100 || keycode == 65363)
		data->game->player_right = 1;
	return (0);
}

int	key_release(int	keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		data->game->player_up = 0;
	if (keycode == 115 || keycode == 65364)
		data->game->player_down = 0;
	if (keycode == 97 || keycode == 65361)
		data->game->player_left = 0;
	if (keycode == 100 || keycode == 65363)
		data->game->player_right = 0;
	return (0);
}

int	main(void)
{
	t_data	img;
	t_data	data;
	t_game	game;

	data.game = &game;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1500, 500, "So_Long");
	img.img = mlx_new_image(data.mlx, 1500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 3, 1L<<1, key_release, &data);
	mlx_loop(data.mlx);
}
