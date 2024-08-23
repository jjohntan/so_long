/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:11:41 by jetan             #+#    #+#             */
/*   Updated: 2024/08/23 14:14:30 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_collectible(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x] = 'P';
		data->c_count--;
	}
}

void	check_space(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0')
	{
		data->map[y][x] = '0';
		data->map[y][x] = 'P';
	}
}

void	check_exit(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E' && data->c_count == 0)
	{
		data->e_count = 1;
	}
}

int	exit_game(t_data *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}
