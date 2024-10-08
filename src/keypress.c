/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:36:06 by jetan             #+#    #+#             */
/*   Updated: 2024/08/27 19:12:01 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/* old_x/y use to fill empty space on the previous position*/
void	move_up(t_data *data)
{
	int	y;
	int	x;
	int	old_x;
	int	old_y;

	old_x = data->x;
	old_y = data->y;
	if (data->map[data->y - 1][data->x] != '1')
	{
		data->y--;
		y = data->y;
		x = data->x;
		check_collectible(data, x, y);
		check_space(data, x, y);
		check_exit(data, x, y);
		if (data->map[old_y][old_x] != 'E')
			data->map[old_y][old_x] = '0';
		data->move++;
		ft_printf("move: %d\n", data->move);
	}
}

void	move_down(t_data *data)
{
	int	y;
	int	x;
	int	old_x;
	int	old_y;

	old_x = data->x;
	old_y = data->y;
	if (data->map[data->y + 1][data->x] != '1')
	{
		data->y++;
		y = data->y;
		x = data->x;
		check_collectible(data, x, y);
		check_space(data, x, y);
		check_exit(data, x, y);
		if (data->map[old_y][old_x] != 'E')
			data->map[old_y][old_x] = '0';
		data->move++;
		ft_printf("move: %d\n", data->move);
	}
}

void	move_left(t_data *data)
{
	int	y;
	int	x;
	int	old_y;
	int	old_x;

	old_y = data->y;
	old_x = data->x;
	if (data->map[data->y][data->x - 1] != '1')
	{
		data->x--;
		y = data->y;
		x = data->x;
		check_collectible(data, x, y);
		check_space(data, x, y);
		check_exit(data, x, y);
		if (data->map[old_y][old_x] != 'E')
			data->map[old_y][old_x] = '0';
		data->move++;
		ft_printf("move: %d\n", data->move);
	}
}

void	move_right(t_data *data)
{
	int	y;
	int	x;
	int	old_y;
	int	old_x;

	old_y = data->y;
	old_x = data->x;
	if (data->map[data->y][data->x + 1] != '1')
	{
		data->x++;
		y = data->y;
		x = data->x;
		check_collectible(data, x, y);
		check_space(data, x, y);
		check_exit(data, x, y);
		if (data->map[old_y][old_x] != 'E')
			data->map[old_y][old_x] = '0';
		data->move++;
		ft_printf("move: %d\n", data->move);
	}
}

/*
 * ESC 53
 * W   13
 * S    1
 * A    0
 * D    2
*/
int	keypress(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_game(data);
	else if (keycode == 13 || keycode == 126)
		move_up(data);
	else if (keycode == 1 || keycode == 125)
		move_down(data);
	else if (keycode == 0 || keycode == 123)
		move_left(data);
	else if (keycode == 2 || keycode == 124)
		move_right(data);
	return (0);
}
