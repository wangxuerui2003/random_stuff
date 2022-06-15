/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:58:08 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/15 17:24:18 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	char	*map;
	int		map_size;
	int		i;
	int		occupied;
	int		line_len;

	i = -1;
	map_size = 0;
	occupied = 0;
	if (ac == 2)
	{
		map_size = get_map_size(av[1]);
		map = init_map(av[1], map_size);
		line_len = get_line_len(map);
		while (map[++i])
			if (map[i] == 'X')
				spread(i, map, occupied++, line_len);
		ft_putstr(map);
	}
	write(1, "\n", 1);
	return (0);
}
