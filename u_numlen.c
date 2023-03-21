/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_numlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:20:49 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 19:48:27 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	ft_numberlen(char *num)
{
	int	n;
	int	m;

	m = 0;
	n = 0;
	while (num[n] && (num[n] == '+' || num[n] == '-' || num[n] == '0'))
		n++;
	while (num[n] && num[n] >= '0' && num[n] <= '9')
	{
		n++;
		m++;
	}
	if (m == 0)
		m  = 1;
	return (m);
}
