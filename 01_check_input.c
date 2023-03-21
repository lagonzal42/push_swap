/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:33:24 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 21:16:15 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_list	*ft_in_case_1(char *list);
t_list	*ft_in_case_2(char **list);
int		ft_check_nums(char **list);
int		ft_num_limits(char *num);

t_list	*ft_check_input(int argc, char **argl)
{
	t_list	*stack1;

	stack1 = 0;
	if (argc == 1)
		return (stack1);
	else if (argc == 2)
		stack1 = ft_in_case_1(argl[1]);
	else
		stack1 = ft_in_case_2(&argl[1]);
	return (stack1);
}

t_list	*ft_in_case_1(char *list)
{
	char	**splited;
	t_list	*stack;
	int		n;

	n = 0;
	splited = ft_split((const char *) list, ' ');
	if (!splited || !splited[0])
		return (NULL);
	while (splited[n])
		n++;
	stack = ft_in_case_2(splited);
	ft_double_free(splited);
	if (!stack)
		return (NULL);
	return (stack);
}

t_list	*ft_in_case_2(char **list)
{
	if (!(ft_check_nums(list)))
		return (NULL);
	return (ft_makelst(list));
}

int	ft_check_nums(char **list)
{
	int	n;
	int	m;

	n = -1;
	while (list[++n])
	{
		m = -1;
		if (!ft_num_form(list[n]))
			return (0);
		if (!ft_num_limits(list[n]))
			return (0);
		while (list[++m])
		{
			if (m != n && (!ft_strncmp(list[n], list[m], 11)))
				return (0);
		}
	}
	return (1);
}

int	ft_num_limits(char *num)
{
	int	len;

	if (num[0] == '+')
		num++;
	len = ft_numberlen(num);
	if (num[0] == '-')
	{
		if (len < 10)
			return (1);
		else if (len != 10)
			return (0);
		else if (0 < ft_strncmp(num, "-2147483648", 11))
			return (0);
	}
	else
	{
		if (len < 10)
			return (1);
		else if (len != 11)
			return (0);
		else if (0 < ft_strncmp(num, "2147483647", 11))
			return (0);
	}
	return (1);
}
