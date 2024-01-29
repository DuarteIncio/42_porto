/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:13:29 by dde-alme          #+#    #+#             */
/*   Updated: 2024/01/24 10:23:20 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"

# include <stdio.h>
# include <fcntl.h>

typedef struct s_coord {
	int	x;
	int	y;
}		t_coord;

typedef struct s_game {
        t_coord player;
        int     player_up;
        int     player_down;
        int     player_left;
        int     player_right;
}               t_game;

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	t_game	*game;

	int	bpp;
	int	line_len;
	int	endian;
}		t_data;

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define MLX_ERROR 1

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	my_close(int keycode, t_data *data);

#endif
