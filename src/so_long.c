/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:46:47 by jetan             #+#    #+#             */
/*   Updated: 2024/08/24 17:16:14 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map(t_data *data)
{
	if (check_rectangular(data) == 0 || check_wall(data) == 0
		|| check_char(data) == 0 || check_ecp(data) == 0)
	{
		// free();
		ft_printf("Error. invalid map\n");
		exit(EXIT_FAILURE);
	}
	// flood_fill();
}

void	check_ber(char *av)
{
	int	len;

	len = ft_strlen(av) - 4;
	if (ft_strncmp(&av[len], ".ber", 4) != 0)
	{
		ft_printf("Error. invalid format\n");
		exit(EXIT_FAILURE);
	}
}

void	get_map_size(t_data *data)
{
	while (data->map[data->height])
		data->height++;
	while (data->map[0][data->width])
		data->width++;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error argument!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_bzero(&data, sizeof(t_data));
		check_ber(av[1]);
		data.map = parse_map(av[1]);
		check_map(&data);
		get_map_size(&data);
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, data.width * SIZE,
				data.height * SIZE, "so_long");
		put_img_to_char(&data);
		put_img_to_win(&data);
		mlx_hook(data.win_ptr, 2, (1L << 0), keypress, &data);
		mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
		mlx_loop_hook(data.mlx_ptr, frame, &data);
		mlx_loop(data.mlx_ptr);
	}
}
