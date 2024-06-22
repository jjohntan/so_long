/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:46:47 by jetan             #+#    #+#             */
/*   Updated: 2024/06/22 18:43:56 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	
	if (ac != 2)
	{
		ft_printf("Error argument!");
		exit(EXIT_FAILURE);
	}
	else
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		mlx_hook();
		mlx_loop(mlx);
	}
}