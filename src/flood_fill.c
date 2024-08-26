/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:45:23 by jetan             #+#    #+#             */
/*   Updated: 2024/08/26 14:56:47 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/* *check if the current position is out of bounds or already visited or a wall
*'F' means filled*/
int	flood_fill(t_data *data, int x, int y)
{
	char	**map;
	int		c;

	map = data->tmp_map;
	c = data->tmp_c_count;
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	if (map[y][x] == 'C')
		c--;
	if (map[y][x] == 'E')
	{
		if (c == 0)
			return (1);
		else
			return (0);
	}
	map[y][x] = 'F';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
	return (1);
}
// int	main()
// {
// }
