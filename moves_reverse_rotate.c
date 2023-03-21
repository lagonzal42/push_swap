/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:19:34 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/27 23:49:49 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_rev_rot(t_list **stack, char c, int i)
{
	t_list	*now;
	t_list	*prev;

	prev = *stack;
	now = prev->next;
	while (now->next)
	{
		prev = now;
		now = now->next;
	}
	prev->next = NULL;
	now->next = *stack;
	*stack = now;
	if (i != 0)
		ft_printf("rr%c\n", c);
}

void	ft_rev_rot_both(t_list **stack1, t_list **stack2)
{
	ft_rev_rot(stack1, 'a', 0);
	ft_rev_rot(stack2, 'b', 0);
	write(1, "rrr\n", 4);
}
