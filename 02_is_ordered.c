/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ordered.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:15:39 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/25 12:15:39 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ordered(t_list **stack, int mode)
{
	t_list	*now;
	t_list	*next;

	now = *stack;
	next = now->next;
	if (mode == 0)
	{
		while (next)
		{
			if (now->content > next->content)
				return (0);
			now = now->next;
			next = next->next;
		}
		return (1);
	}
	while (next)
	{
		if (now->content < next->content)
			return (0);
		now = now->next;
		next = next->next;
	}
	return (1);
}
