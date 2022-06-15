/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:57:33 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/15 10:57:35 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	get_map_size(char *file)
{
	int		fd;
	int		i;
	char	temp;

	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, &temp, 1))
		i++;
	i += 1;
	close(fd);
	return (i);
}

char	*init_map(char *file, int map_size)
{
	int		fd;
	char	*map;
	int		i;
	char	temp;

	i = 0;
	map = malloc((map_size + 1) * sizeof(char));
	fd = open(file, O_RDONLY);
	while (read(fd, &temp, 1))
	{
		map[i] = temp;
		i++;
	}
	close(fd);
	return (map);
}

node	*create_elem(int data)
{
	node	*temp;

	temp = malloc(sizeof(node));
	if (temp)
	{
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		temp->top = NULL;
		temp->bot = NULL;
	}
	return (temp);
}
