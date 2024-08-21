/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:46:47 by jetan             #+#    #+#             */
/*   Updated: 2024/08/21 14:44:45 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	check_map(t_data *data)
{
	if (check_rectangular(data->map) == 0  || check_wall(data) == 0 
			|| check_char(data) == 0 || check_ecp(data) == 0)
	{
		// free();
		ft_printf("Error. invalid map\n");
		exit(EXIT_FAILURE);
	}
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

int main(int ac, char **av)
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
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "so_long");
		// mlx_hook(data.win_ptr, 2, (1L<<0), keypress, &data);
		// mlx_hook(data.win_ptr, 17, 0, destroy, &data);
		mlx_loop(data.mlx_ptr);
	}
}
