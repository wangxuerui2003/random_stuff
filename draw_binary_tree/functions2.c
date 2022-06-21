/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:20:57 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/16 14:48:22 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insert_node(t_node *temp, char *data)
{
	if (temp == NULL)
	{
		temp = create_new_node(data);
		return ;
	}
	if (ft_strcmp(temp->data, data) > 0)
	{
		if (temp->left == NULL)
		{
			temp->left = create_new_node(data);
			return ;
		}
		insert_node(temp->left, data);
	}
	else if (ft_strcmp(temp->data, data) < 0)
	{
		if (temp->right == NULL)
		{
			temp->right = create_new_node(data);
			return ;
		}
		insert_node(temp->right, data);
	}
}

int	calc_depth(t_node *head, int depth)
{
	if (head->left == NULL && head->right == NULL)
		return (depth);
	if (head->left && head->right)
	{
		if (calc_depth(head->left, depth + 1) > calc_depth(head->right, depth + 1))
			return (calc_depth(head->left, depth + 1));
		return (calc_depth(head->right, depth + 1));
	}
	if (head->left)
		return (calc_depth(head->left, depth + 1));
	return (calc_depth(head->right, depth + 1));
}

void	print_spaces(int num)
{
	int	i;

	i = -1;
	while (++i < num)
		write(1, " ", 1);
}

void	print_level(t_node *node, int level)
{
	if (level == 0)
	{
		ft_putstr(node->data);
		ft_putstr("   ");
		return ;
	}
	print_level(node->left, level - 1);
	print_level(node->right, level - 1);
}

void	print_tree(t_node *head)
{
	int	depth;
	int	i;

	depth = calc_depth(head, 1);
	i = 0;
	while (i < depth)
	{
		print_spaces(depth - i * 2);
		print_level(head, i);
		write(1, "\n", 1);
		print_spaces(depth - i);
		i++;
		write(1, "/ \\\n", 4);
	}
}
