/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:20:03 by jetan             #+#    #+#             */
/*   Updated: 2024/08/20 16:53:37 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
* check the first row and rest row have the same length 
*/
int	check_rectangular(char **map)
{
	int	h;
	int	first_row_len;

	if (!*map)
		return (0);
	h = 0;
	first_row_len = ft_strlen(map[0]);
	while (map[h])
	{
		if ((int)ft_strlen(map[h]) != first_row_len)
			return (0);
		h++;
	}
    return (1);
}
/*
* the first while loops check for the first and last row
* the second while loops check for the first and last column
*/
int	check_wall(t_data *data)
{
	int	h;
	int	w;
	int row_len;

	if (!data->map)
		return (0);
	h = 0;
	while (data->map[h])
		h++;
	// ft_printf("height: %d\n", h);//debug
	w = 0;
	while (data->map[0][w] && data->map[h - 1][w])
	{
		if (data->map[0][w] != '1' || data->map[h - 1][w] != '1')
			return (0);
		w++;
	}
	// ft_printf("width: %d\n", w);//debug
	h = 0;
	row_len = ft_strlen(data->map[h]);
	// ft_printf("row_len: %d\n", row_len);//debug
	while (data->map[h])
	{
		if (data->map[h][0] != '1' || data->map[h][row_len - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}

int	check_char(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (data->map[h])
	{
		w = 0;
		while (data->map[h][w])
		{
			if (data->map[h][w] != '0' && data->map[h][w] != '1' 
					&& data->map[h][w] != 'C' && data->map[h][w] != 'E' 
					&& data->map[h][w] != 'P')
				return (0);
			w++;
		}
		h++;
	}
	// ft_printf("h: %dw: %d\n", h, w);
	return (1);
}

/*
 * check the map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
*/
int	check_ecp(t_data *data)
{
	int	r;
	int	c;
	
	r = 0;
	while (data->map[r])
	{
		c = 0;
		while (data->map[r][c])
		{
			check_and_count(data, r, c);
			c++;
		}
		r++;
	}
	if (data->e_count != 1 && data->c_count < 1 && data->p_count != 1)
		return (0);
	return (1);
}
