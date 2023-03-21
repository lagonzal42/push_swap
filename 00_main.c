/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:30:49 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 20:02:37 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argl)
{
	t_list	**stack;

	if (argc > 1)
	{
		stack = malloc(sizeof(t_list **));
		*stack = ft_check_input(argc, argl);
		if (!*stack || !ft_index(stack))
		{
			write(0, "Error\n", 6);
			free(stack);
			return (1);
		}
		if (ft_is_ordered(stack, 0))
			ft_freelst(stack);
		else
		{
			ft_top_order(stack);
			//ft_print_lst(stack);
			ft_freelst(stack);
		}
	}
	return (0);
}
