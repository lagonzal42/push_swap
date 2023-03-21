/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:19:57 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/21 19:34:47 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_small
{
	int				big;
	int				small;

}	t_small;

// Functions for moving the elements froms one stack to another

void	ft_swap(t_list **stack, char c, int i);
void	ft_swap_both(t_list **stack1, t_list **stack2);
void	ft_push(t_list **stack1, t_list **stack2, char c);
void	ft_rot(t_list **stack, char c, int i);
void	ft_rot_both(t_list **stack1, t_list **stack2);
void	ft_rev_rot(t_list **stack, char c, int i);
void	ft_rev_rot_both(t_list **stack1, t_list **stack2);

// Functions for checking the input

t_list	*ft_check_input(int argc, char **argl);
int		ft_num_form(char *num);
t_list	**ft_index(t_list **stack);
int	ft_numberlen(char *num);

//Order

void	ft_top_order(t_list **stack_a);
void	ft_order_3(t_list **stack, int size);
void	ft_order_5(t_list **stack_a, t_list **stack_b, int lstsize);
void	ft_order_mid(t_list **stack_a, t_list **stack_b, int size, int t_max);
void	ft_order_big(t_list **stack_a, t_list **stack_b, int size, int t_max);

/*======================== UTILS ========================*/

void	ft_print_lst(t_list **stack);

// Functions for creating or destroying the list

t_list	*ft_makelst(char **lst);
t_list	*ft_freelst(t_list **lst);

//Functions for extracting key elements

void	ft_extract_small(t_list **stack_a, t_list **stack_b, int pos, int size);
void	ft_extract_big(t_list **stack_a, t_list **stack_b, int pos, int size);
void	ft_insert_back(t_list **stack_a, t_list **stack_b, int n);

//Finding biggest and smallest nodes in stack_b

void	ft_find_big_small(t_list **stack_b, t_small *sm_bg);
int		ft_is_ordered(t_list **stack, int mode);

#endif
