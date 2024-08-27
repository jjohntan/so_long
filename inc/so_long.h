/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:03:54 by jetan             #+#    #+#             */
/*   Updated: 2024/08/27 15:45:27 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
// # include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define SIZE 50

typedef struct s_data
{
	void	*space;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		height;
	int		width;
	int		move;
	int		c_count;
	int		tmp_c_count;
	int		e_count;
	int		p_count;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**tmp_map;
	int		valid_map;
	int		exit_found;
}	t_data;

void	check_ber(char *av);
void	check_map(t_data *data);
char	**parse_map(char *av);
void	free_map(char **map);
void	print_error_msg(char *str);
//check map
int		check_rectangular(t_data *data);
int		check_wall(t_data *data);
int		check_char(t_data *data);
int		check_ecp(t_data *data);
int		check_row_and_column(t_data *data, int h, int w);
int		frame(t_data *data);
void	flood_fill(t_data *data, int x, int y);
//put image
void	put_img_to_win(t_data *data);
void	put_img_to_char(t_data *data);
void	open_window(t_data *data);
//keypress
int		keypress(int keycode, t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	check_collectible(t_data *data, int x, int y);
void	check_space(t_data *data, int x, int y);
void	check_exit(t_data *data, int x, int y);
int		exit_game(t_data *data);

#endif