/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:29:15 by jetan             #+#    #+#             */
/*   Updated: 2024/07/07 19:01:33 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	read_map(char *av)
{
	int		fd;
	char	*read_map;
	char	*load_map;
	char	**map;
	
	load_map = ft_strdup("");
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	while (read_map)
	{
		read_map = get_next_line(fd);
		if (!read)
			break;
		free(read_map);
		load_map = ft_strjoin(load_map, read_map);
	}
	map = ft_split(load_map, "\n");
	free(read_map);
	close(fd);
	return (map);
}

int	check_map(t_data *game, char **av)
{
	char	**map;
	
	map = readmap(av[1]);
	if (!map)
		return (0);
	if (check_rectangle(game) != 0)
		return (1);
	return (0);
}