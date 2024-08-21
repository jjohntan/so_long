/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:03:54 by jetan             #+#    #+#             */
/*   Updated: 2024/08/21 13:44:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./pictures/wall.xpm"
# define EMPTY "./pictures/empty.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/exit.xpm"
# define COLLECT "./pictures/collect.xpm"
# define WIN "./pictures/winner.xpm"

// # include <mlx.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
// # include "../minilibx-linux/mlx.h"
# include <mlx.h>

typedef struct s_data
{
	void	*player;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*empty;
	int height;
	int width;
	int	move;
	int c_count;
	int	e_count;
	int p_count;
	int x;
	int y;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}	t_data;

void	check_ber(char *av);
void	check_map(t_data *data);
char	**read_map(char *av);
//check map
int	check_rectangular(char **map);
int	check_wall(t_data *data);
int	check_char(t_data *data);
int	check_ecp(t_data *data);
void	check_and_count(t_data *data, int r, int c);
int	check_row_and_column(t_data *data, int h, int w);

#endif