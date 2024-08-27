/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:46:47 by jetan             #+#    #+#             */
/*   Updated: 2024/08/27 15:53:05 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map(t_data *data)
{
	if (check_rectangular(data) == 0 || check_wall(data) == 0
		|| check_char(data) == 0 || check_ecp(data) == 0)
		print_error_msg("Error. invalid map\n");
	flood_fill(data, data->x, data->y);
	if (data->valid_map == 0)
		print_error_msg("Error. invalid path\n");
}

void	check_ber(char *av)
{
	int	len;

	len = ft_strlen(av) - 4;
	if (ft_strncmp(&av[len], ".ber", 4) != 0)
		print_error_msg("Error. invalid format\n");
}

void	get_map_size(t_data *data)
{
	while (data->map[data->height])
		data->height++;
	while (data->map[0][data->width])
		data->width++;
}

void	print_error_msg(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		print_error_msg("Error argument!\n");
	else
	{
		ft_bzero(&data, sizeof(t_data));
		check_ber(av[1]);
		data.map = parse_map(av[1]);
		if (data.map == NULL)
			print_error_msg("Error no such map\n");
		data.tmp_map = parse_map(av[1]);
		get_map_size(&data);
		check_map(&data);
		open_window(&data);
		mlx_hook(data.win_ptr, 2, (1L << 0), keypress, &data);
		mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
		mlx_loop_hook(data.mlx_ptr, frame, &data);
		mlx_loop(data.mlx_ptr);
	}
}
