/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:19:48 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/10 16:34:14 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_swap(t_list **stack, char c, int i)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (i != 0)
		ft_printf("s%c\n", c);
}

void	ft_swap_both(t_list **stack1, t_list **stack2)
{
	ft_swap(stack1, 'a', 0);
	ft_swap(stack2, 'b', 0);
	write(1, "ss\n", 3);
}
