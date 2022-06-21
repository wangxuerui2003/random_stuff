/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:57:51 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/16 14:17:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*data;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

void	print_tree(t_node *head);
t_node	*create_new_node(char *data);
int	ft_strcmp(char *str1, char *str2);
int	calc_depth(t_node *head, int depth);
void	insert_node(t_node *temp, char *data);
void	ft_putstr(char *str);
void	print_tree_test(t_node *head);

#endif
