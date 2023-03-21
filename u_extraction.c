/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_extraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:46:50 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/28 21:46:50 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_extract_big(t_list **stack_a, t_list **stack_b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos != 1)
		{
			ft_rot(stack_b, 'b', 1);
			pos--;
		}
	}
	else
	{
		while (pos <= size)
		{
			ft_rev_rot(stack_b, 'b', 1);
			pos++;
		}
	}
	ft_push(stack_b, stack_a, 'a');
}

void	ft_extract_small(t_list **stack_a, t_list **stack_b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos != 1)
		{
			ft_rot(stack_b, 'b', 1);
			pos--;
		}
	}
	else
	{
		while (pos <= size)
		{
			ft_rev_rot(stack_b, 'b', 1);
			pos++;
		}
	}
	ft_push(stack_b, stack_a, 'a');
	ft_rot(stack_a, 'a', 1);
}
