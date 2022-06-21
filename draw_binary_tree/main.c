/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:59:28 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/16 14:18:50 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int		i;
	t_node	*head;
	t_node	*temp;

	i = 2;
	if (ac > 1)
	{
		head = create_new_node(av[1]);
		temp = head;
		while (i < ac)
		{
			insert_node(temp, av[i]);
			i++;
		}
	print_tree(head);
	}
	write(1, "\n", 1);
	return (0);
}
