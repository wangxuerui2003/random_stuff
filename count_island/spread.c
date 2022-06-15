/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:57:48 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/15 17:23:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spread(int pos, char *map, int current, int line_len)
{
	node	*head;

	head = create_elem(current);
	map[pos] = current + '0';
	if (head->left == NULL && map[pos - 1] == 'X')
	{
		head->left = create_elem(current);
		map[pos] = current + '0';
		spread(pos - 1, map, current, line_len);
	}	
	if (head->right == NULL && map[pos + 1] == 'X')
	{
		head->right = create_elem(current);
		map[pos] = current + '0';
		spread(pos + 1, map, current, line_len);
	}
	if ((pos - line_len - 1) >= 0)
	{
		if (head->top == NULL && map[pos - line_len - 1] == 'X')
		{
			head->top = create_elem(current);
			map[pos] = current + '0';
			spread(pos - line_len - 1, map, current, line_len);
		}
	}
	if ((pos + line_len + 1) <= ft_strlen(map))
	{
		if (head->bot == NULL && map[pos + line_len + 1] == 'X')
		{
			head->bot = create_elem(current);
			map[pos] = current + '0';
			spread(pos + line_len + 1, map, current, line_len);
		}
	}
	free_tree(head);
}

void	free_tree(node *head)
{
	if (head->left)
		free_tree(head->left);
	if (head->right)
		free_tree(head->right);
	if (head->top)
		free_tree(head->top);
	if (head->bot)
		free_tree(head->bot);
	free(head);
}
