/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:30:25 by lagonzal          #+#    #+#             */
/*   Updated: 2022/12/30 12:30:25 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "stdio.h"

int	ft_cont_in_pos(t_list **stack, int n)
{
	t_list	*aux;

	aux = *stack;
	while (n > 1 && aux)
	{
		aux = aux->next;
		n -= 1;
	}
	if (aux)
		return (aux->content);
	else
		return (0);
}

void	ft_order_3(t_list **stack, int size)
{
	if (size > 2)
	{
		if (ft_cont_in_pos(stack, 1) > ft_cont_in_pos(stack, 3))
		{
			if (ft_cont_in_pos(stack, 2) < ft_cont_in_pos(stack, 3))
				ft_rev_rot(stack, 'a', 1);
			else if (ft_cont_in_pos(stack, 1) > ft_cont_in_pos(stack, 2))
				ft_swap(stack, 'a', 1);
			ft_rev_rot(stack, 'a', 1);
		}
		else if (ft_cont_in_pos(stack, 3) < ft_cont_in_pos(stack, 2)
			|| ft_cont_in_pos(stack, 2) > ft_cont_in_pos(stack, 1))
		{
			if (ft_cont_in_pos(stack, 3) < ft_cont_in_pos(stack, 2))
				ft_rev_rot(stack, 'a', 1);
			ft_swap(stack, 'a', 1);
		}
	}
	else if (size > 1)
	{
		if (ft_cont_in_pos(stack, 2) < ft_cont_in_pos(stack, 1))
			ft_swap(stack, 'a', 1);
	}
}

int	ft_find_ins(t_list **stack_a, t_list **stack_b)
{
	int		n;
	t_list	*a;
	t_list	*b;

	b = *stack_b;
	a = *stack_a;
	n = 1;
	while (a && a->content < b->content)
	{
		a = a->next;
		n++;
	}
	return (n);
}

void	ft_order_5(t_list **stack_a, t_list **stack_b, int lstsize)
{
	int		n;

	while (lstsize-- > 3)
		ft_push(stack_a, stack_b, 'b');
	ft_order_3(stack_a, ft_lstsize(*stack_a));
	while (ft_lstsize(*stack_b))
	{
		n = ft_find_ins(stack_a, stack_b);
		if ((n == 1) || (n > ft_lstsize(*stack_a)) || (n == 2))
		{
			ft_push(stack_b, stack_a, 'a');
			if (n > lstsize)
				ft_rot(stack_a, 'a', 1);
			else if (n == 2)
				ft_swap(stack_a, 'a', 1);
		}
		else
			ft_insert_back(stack_a, stack_b, n);
		lstsize++;
	}
}
