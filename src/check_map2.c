/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:48:45 by jetan             #+#    #+#             */
/*   Updated: 2024/08/25 16:08:12 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * check the character and increase the count
 * set the starting positon
*/
static void	check_and_count(t_data *data, int h, int w)
{
	if (data->map[h][w] == 'C')
		data->c_count++;
	else if (data->map[h][w] == 'P')
	{
		data->y = h;
		data->x = w;
		data->p_count++;
	}
}

/*	*check the map must contain 1 exit, at least 1 collectible,
	and 1 starting position to be valid. */
int	check_ecp(t_data *data)
{
	int	h;
	int	w;
	int	exit;

	h = 0;
	exit = 0;
	while (data->map[h])
	{
		w = 0;
		while (data->map[h][w])
		{
			if (data->map[h][w] == 'E')
				exit++;
			check_and_count(data, h, w);
			w++;
		}
		h++;
	}
	if (exit != 1 && data->c_count < 1 && data->p_count != 1)
		return (0);
	return (1);
}

void	game_res(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, 40, 40);
}

int	frame(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	put_img_to_win(data);
	if (data->c_count == 0 && data->e_count == 1 && data->p_count == 1)
		game_res(data);
	return (0);
}
