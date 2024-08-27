/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:45:23 by jetan             #+#    #+#             */
/*   Updated: 2024/08/27 16:08:13 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/* *check if the current position is out of bounds or already visited or a wall
*'F' means filled */
void	flood_fill(t_data *data, int x, int y)
{
	char	**map;

	map = data->tmp_map;
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		data->tmp_c_count++;
	if (map[y][x] == 'E')
		data->exit_found = 1;
	if (data->tmp_c_count == data->c_count && data->exit_found == 1)
	{
		data->valid_map = 1;
		return ;
	}
	map[y][x] = 'F';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
	return ;
}
