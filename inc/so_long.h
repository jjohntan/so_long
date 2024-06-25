/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:03:54 by jetan             #+#    #+#             */
/*   Updated: 2024/06/24 17:30:07 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>


typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}	t_data;

void	check_ber(char **av);

#endif