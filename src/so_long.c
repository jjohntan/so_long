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

void	check_ber(char *av)
{
	int	len;
	
	len = ft_strlen(&av[1]) - 4;
	if (ft_strncmp(&av[len], ".ber", 4))
	{
		perror("Error");
		exit(1);
	}
}

int main(int ac, char **av)
{
	t_data	game;
	
	if (ac != 2)
	{
		ft_printf("Error argument!");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_bzero(&game, sizeof(t_data));
		check_ber(av[1]);
		check_map(&game, av);
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		
		// mlx_loop(mlx);
	}
}
