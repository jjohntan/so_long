/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:48:45 by jetan             #+#    #+#             */
/*   Updated: 2024/08/21 13:49:35 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * check the character and increase the count
 * set the starting positon
*/
void	check_and_count(t_data *data, int r, int c)
{
	if (data->map[r][c] == 'E')
		data->e_count++;
	else if (data->map[r][c] == 'C')
		data->c_count++;
	else if (data->map[r][c] == 'P')
	{
		data-> y = r;
		data-> x = c;
		data->p_count++;
	}
}

/*
 * check the map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
*/
int	check_ecp(t_data *data)
{
	int	r;
	int	c;
	
	r = 0;
	while (data->map[r])
	{
		c = 0;
		while (data->map[r][c])
		{
			check_and_count(data, r, c);
			c++;
		}
		r++;
	}
	if (data->e_count != 1 && data->c_count < 1 && data->p_count != 1)
		return (0);
	return (1);
}