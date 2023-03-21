/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_num_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:16:27 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 17:11:14 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	ft_num_form(char *num)
{
	int	n;

	n = 0;
	if (num[n] == '-' || num[n] == '+')
		n++;
	if (num[n] == '\0')
		return (0);
	while (num[n])
	{
		if (!(ft_isdigit(num[n])))
			return (0);
		n++;
	}
	return (1);
}

t_list	**ft_index(t_list **stack)
{
	t_list	*aux1;
	t_list	*aux2;
	int		flag;

	aux1 = *stack;
	flag = 0;
	while (aux1 && !flag)
	{
		aux2 = aux1->next;
		while (aux2 && !flag)
		{
			if (aux1->content > aux2->content)
				aux1->index += 1;
			else if (aux1->content == aux2->content)
				flag = 1;
			else
				aux2->index += 1;
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
	if (flag)
		return (NULL);
	return (stack);
}
