/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_numlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:20:49 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 19:38:29 by lagonzal         ###   ########.fr       */
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
	printf("n = %d\n", n);
	while (num[n] && (num[n] == '+' || num[n] == '-' || num[n] == '0'))
		n++;
	printf("n = %d\n", n);
	while (num[n] && num[n] >= '0' && num[n] <= '9')
	{
		n++;
		m++;
	}
	printf("m = %d\n", m);
	if (m == 0)
		m  = 1;
	return (m || 1);
}
