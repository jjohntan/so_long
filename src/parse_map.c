/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:29:15 by jetan             #+#    #+#             */
/*   Updated: 2024/08/21 14:40:32 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
* 
*/
char	**parse_map(char *av)
{
	int		fd;
	char	*read_map;
	char	*load_map;
	char	*tmp;
	char	**map;
	
	read_map = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return NULL;
	load_map = ft_strdup("");
	while (1)
	{
		read_map = get_next_line(fd);
		if (!read_map)
			break;
		tmp = load_map;
		load_map = ft_strjoin(tmp, read_map);
		free(read_map);
		free(tmp);
	}
	map = ft_split(load_map, '\n');
	free(load_map);
	close(fd);
	return (map);
}
// int main()
// {
//     char **map;
//     int i;

//     map = parse_map("test_map.txt");
// 	i = 0;
//     while (map[i] != NULL)
//     {
//         ft_printf("%s\n", map[i]);
//         free(map[i]);
// 		i++;
//     }
//     free(map);
// }