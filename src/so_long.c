/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:46:47 by jetan             #+#    #+#             */
/*   Updated: 2024/07/07 19:01:56 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	check_map(t_data *data)
{
	if (check_rectangular(data->map) == 0  || check_wall(data) == 0 
			|| check_char(data) == 0)
	{
		// free();
		ft_printf("Error.invalid map\n");
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

void	ft_init_data(t_data *data)
{
	data->p_count = 0;
	data->c_count = 0;
	data->e_count = 0;
	data->x = 0;
	data->y = 0;
	data->move = 0;
	data->height = 0;
	data->width = 0;
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
		ft_init_data(&data);
		check_ber(av[1]);
		data.map = read_map(av[1]);
		check_map(&data);
		// window(&data);
		// control(&data);
		// mlx_loop(data.mlx_ptr);
	}
}