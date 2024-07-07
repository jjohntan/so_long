/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:20:03 by jetan             #+#    #+#             */
/*   Updated: 2024/07/07 16:34:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_rectangle(char **map)
{
	int	i;
	int	first_row_len;
	
	if (!*map || !map[0])
		return (0);
	i = 0;
	first_row_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_row_len)
			return (0);
		i++;
	}
	return (1);
}
