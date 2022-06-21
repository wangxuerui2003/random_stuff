/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:56:16 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/16 08:57:46 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*create_new_node(char *data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (temp)
	{
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}
	return (temp);
}
