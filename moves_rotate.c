/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:19:41 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/10 17:53:18 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_rot(t_list **stack, char c, int i)
{
	t_list	*first;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
	if (i != 0)
		ft_printf("r%c\n", c);
}

void	rot_both(t_list **stack1, t_list **stack2)
{
	ft_rot(stack1, 'a', 0);
	ft_rot(stack2, 'b', 0);
	write(1, "rr\n", 3);
}
