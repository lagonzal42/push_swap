/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_make_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:23:59 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/10 17:30:17 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_list	*ft_create(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = num;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_list	*ft_makelst(char **lst)
{
	t_list	*first;
	t_list	*aux;
	t_list	*temp;
	int		n;

	n = 0;
	first = ft_create(ft_atoi(lst[0]));
	aux = first;
	while (lst[++n])
	{
		temp = ft_create(ft_atoi(lst[n]));
		aux->next = temp;
		aux = aux->next;
	}
	return (first);
}

t_list	*ft_freelst(t_list **lst)
{
	t_list	*now;
	t_list	*prev;

	prev = *lst;
	now = prev->next;
	while (now != NULL)
	{
		free(prev);
		prev = now;
		now = now->next;
	}
	free(prev);
	return (free(lst), NULL);
}
