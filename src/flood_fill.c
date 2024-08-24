/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:45:23 by jetan             #+#    #+#             */
/*   Updated: 2024/08/24 17:08:07 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/* 'F' mark the position as filled*/
void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return;
	if (data->map[y][x] == '1' || data->map[y][x] == 'F')
		return;
	if (data->map[y][x] == 'C')
	
	if (data->map[y][x] == 'E')
	
	data->map[y][x] = 'F';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}

int	main()
{
	
}
