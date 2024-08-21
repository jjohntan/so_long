/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:50:15 by jetan             #+#    #+#             */
/*   Updated: 2024/08/21 17:38:40 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_img_to_char(t_data *data)
{
	int	img_width;
	int	img_height;
	
	data->empty = mlx_xpm_file_to_image(data->mlx_ptr, "space.xpm", img_width, img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm", img_width, img_height);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "coin.xpm", img_width, img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "door.xpm", img_width, img_height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "player.xpm", img_width, img_height);
}

void	check_and_put_img(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty, XPM_WIDTH, XPM_HEIGHT);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty, XPM_WIDTH, XPM_HEIGHT);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty, XPM_WIDTH, XPM_HEIGHT);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty, XPM_WIDTH, XPM_HEIGHT);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty, XPM_WIDTH, XPM_HEIGHT);
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
