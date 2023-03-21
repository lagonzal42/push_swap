/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:19:24 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/01 00:34:32 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void	ft_push(t_list **stack1, t_list **stack2, char c)
{
	t_list	*aux;

	aux = *stack1;
	*stack1 = aux->next;
	aux->next = *stack2;
	*stack2 = aux;
	ft_printf("p%c\n", c);
}
