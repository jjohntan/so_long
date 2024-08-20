/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:52:43 by jetan             #+#    #+#             */
/*   Updated: 2024/08/20 16:53:32 by jetan            ###   ########.fr       */
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