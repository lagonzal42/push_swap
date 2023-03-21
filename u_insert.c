/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:30:21 by lagonzal          #+#    #+#             */
/*   Updated: 2023/01/17 12:30:21 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_insert_back(t_list **stack_a, t_list **stack_b, int n)
{
	int	a_size;
	int	r;

	r = 1;
	a_size = ft_lstsize(*stack_a);
	while (a_size > n - 1)
	{
		ft_rev_rot(stack_a, 'a', 1);
		r++;
		n++;
	}
	ft_push(stack_b, stack_a, 'a');
	while (r--)
		ft_rot(stack_a, 'a', 1);
}
