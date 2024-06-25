/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:29:15 by jetan             #+#    #+#             */
/*   Updated: 2024/06/25 09:35:32 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_ber(char **av)
{
	int	len;
	
	len = ft_strlen(av[1] - 4);
	if (ft_strncmp(av[1] + len, ".ber", 4))
	{
		perror("Error");
		exit(1);
	}
}

char	read_map(t_data *game, char *av)
{
	int		fd;
	char	*read_map;
	char	*load_map;
	
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
		load_map = ft_strjoin(load_map, read_map);
		free(read_map);
	}
}