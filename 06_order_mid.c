/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:09:55 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/25 12:09:55 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	ft_pb(t_list **stack_a, t_list **stack_b, t_small *min_max, int t);
static int	ft_some_left(t_list **stack_a, int min, int max);
static void	ft_push_back(t_list **stack_a, t_list **stack_b);
static void	ft_rearrange(t_list **stack_a, int max, int t, int max_times);

void	ft_order_mid(t_list **stack_a, t_list **stack_b, int size, int t_max)
{
	int				median;
	int				t;
	struct s_small	min_max;

	median = size / t_max;
	t = 1;
	min_max.small = 0;
	min_max.big = median;
	while (t <= t_max)
	{
		ft_pb(stack_a, stack_b, &min_max, t);
		ft_push_back(stack_a, stack_b);
		ft_rearrange(stack_a, min_max.big, t, t_max);
		t++;
		min_max.small += median;
		min_max.big += median;
	}
}

static void	ft_pb(t_list **stack_a, t_list**stack_b, t_small *min_max, int t)
{
	t_list	*aux;
	int		rot;

	rot = 0;
	while (ft_some_left(stack_a, min_max->small, min_max->big))
	{
		aux = *stack_a;
		if (aux->index >= min_max->small && aux->index < min_max->big)
			ft_push(stack_a, stack_b, 'b');
		else if (aux->index >= min_max->big)
		{	
			ft_rot(stack_a, 'a', 1);
			rot++;
		}
	}
	while (t != 1 && rot--)
	{
		ft_rev_rot(stack_a, 'a', 1);
	}
}

static int	ft_some_left(t_list **stack_a, int min, int max)
{
	t_list	*aux;

	aux = *stack_a;
	while (aux)
	{
		if (aux->index >= min && aux->index < max)
			return (1);
		aux = aux->next;
	}
	return (0);
}

static void	ft_rearrange(t_list **stack_a, int max, int t, int max_times)
{
	t_list	*aux;

	aux = *stack_a;
	if (t != max_times)
	{	
		while (aux->index < max)
		{
			ft_rot(stack_a, 'a', 1);
			aux = *stack_a;
		}
	}
	else
	{
		while (aux->index != 0)
		{
			ft_rot(stack_a, 'a', 1);
			aux = *stack_a;
		}
	}
}

static void	ft_push_back(t_list **stack_a, t_list **stack_b)
{
	struct s_small	sm_bg;
	int				size;

	size = ft_lstsize(*stack_b);
	while (size > 1)
	{
		ft_find_big_small(stack_b, &sm_bg);
		if (sm_bg.big != 0)
			ft_extract_big(stack_a, stack_b, sm_bg.big, size);
		else
			ft_extract_small(stack_a, stack_b, sm_bg.small, size);
		size--;
	}
	ft_push(stack_b, stack_a, 'a');
}
