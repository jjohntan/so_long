/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:50:15 by jetan             #+#    #+#             */
/*   Updated: 2024/08/27 15:53:16 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_img_to_char(t_data *data)
{
	int	img_width;
	int	img_height;

	data->space = mlx_xpm_file_to_image(data->mlx_ptr, "./sprite/space.xpm",
			&img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./sprite/wall.xpm",
			&img_width, &img_height);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprite/coin.xpm", &img_width, &img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./sprite/door.xpm",
			&img_width, &img_height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "./sprite/player.xpm",
			&img_width, &img_height);
}

static void	check_and_put_img(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space,
			x * SIZE, y * SIZE);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
			x * SIZE, y * SIZE);
	else if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space,
			x * SIZE, y * SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible,
			x * SIZE, y * SIZE);
	}
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			x * SIZE, y * SIZE);
	else if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space,
			x * SIZE, y * SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			x * SIZE, y * SIZE);
	}
}

void	put_img_to_win(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			check_and_put_img(data, y, x);
			x++;
		}
		y++;
	}
}

void	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * SIZE,
			data->height * SIZE, "so_long");
	put_img_to_char(data);
	put_img_to_win(data);
}
