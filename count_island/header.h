/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:57:55 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/15 10:58:32 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*top;
	struct s_node	*bot;
}	node;

int		get_map_size(char *file);
char	*init_map(char *file, int map_size);
node	*create_elem(int data);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		get_line_len(char *map);
void	spread(int pos, char *map, int current, int line_len);

#endif
