/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_find_in_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:03:10 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/28 20:03:10 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_pos(t_list **stack, int limit, t_small *sm_bg);
void	ft_moves_to_extract(t_list **stack_b, t_small *sm_bg);
int		ft_find_big(t_list **stack_b);
int		ft_find_small(t_list **stack_b);
void	ft_find_big_small(t_list **stack_b, t_small *sm_bg);

void	ft_moves_to_extract(t_list **stack_b, t_small *sm_bg)
{
	int	t_sm;
	int	t_bg;
	int	size;

	size = ft_lstsize(*stack_b);
	if (sm_bg->small < size / 2)
		t_sm = sm_bg->small + 1;
	else
		t_sm = size - sm_bg->small;
	if (sm_bg->big < size / 2)
		t_bg = sm_bg->big;
	else
		t_bg = size - sm_bg->big;
	if (t_bg <= t_sm)
		sm_bg->small = 0;
	else
		sm_bg->big = 0;
}

int	ft_find_big(t_list **stack_b)
{
	t_list	*aux;
	int		pos;
	int		ret;
	int		max;

	pos = 1;
	ret = 1;
	aux = *stack_b;
	max = aux->index;
	while (aux)
	{
		if (aux->index > max)
		{
			max = aux->index;
			ret = pos;
		}
		pos++;
		aux = aux->next;
	}
	return (ret);
}

int	ft_find_small(t_list **stack_b)
{
	t_list	*aux;
	int		pos;
	int		ret;
	int		min;

	pos = 1;
	ret = 1;
	aux = *stack_b;
	min = aux->index;
	while (aux)
	{
		if (aux->index < min)
		{
			min = aux->index;
			ret = pos;
		}
		pos++;
		aux = aux->next;
	}
	return (ret);
}

void	ft_find_big_small(t_list **stack_b, t_small *sm_bg)
{
	sm_bg->big = ft_find_big(stack_b);
	sm_bg->small = ft_find_small(stack_b);
	ft_moves_to_extract(stack_b, sm_bg);
}
