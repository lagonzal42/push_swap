/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_top_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:06:16 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 17:11:32 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "stdio.h"

void	ft_top_order(t_list **stack_a)
{
	int		n;
	t_list	*stack_b;

	stack_b = NULL;
	n = ft_lstsize(*stack_a);
	if (n > 1)
	{
		if (n < 4)
			ft_order_3(stack_a, n);
		else if (n < 6)
			ft_order_5(stack_a, &stack_b, n);
		else if (n < 101)
			ft_order_mid(stack_a, &stack_b, n, 2);
		else
			ft_order_big(stack_a, &stack_b, n, 4);
	}
}
