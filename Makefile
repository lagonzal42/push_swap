# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 13:19:53 by lagonzal          #+#    #+#              #
#    Updated: 2023/03/21 19:35:38 by lagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 00_main.c\
		01_check_input.c\
		02_is_ordered.c\
		03_num_format.c\
		04_top_order.c\
		05_order_small.c\
		06_order_mid.c\
		07_order_big.c\
		moves_push.c\
		moves_reverse_rotate.c\
		moves_rotate.c\
		moves_swap.c\
		u_extraction.c\
		u_find_in_chunk.c\
		u_make_free.c\
		u_print_lst.c\
		u_insert.c\
		u_numlen.c


OBJS = 00_main.o\
		01_check_input.o\
		02_is_ordered.o\
		03_num_format.o\
		04_top_order.o\
		05_order_small.o\
		06_order_mid.o\
		07_order_big.o\
		moves_push.o\
		moves_reverse_rotate.o\
		moves_rotate.o\
		moves_swap.o\
		u_extraction.o\
		u_find_in_chunk.o\
		u_make_free.o\
		u_print_lst.o\
		u_insert.o\
		u_numlen.o

LIB_DIR = libft

LIB = libft.a

INCLUDE = -I $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -fr

CC = gcc

%o:%c
	@$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "Compiling LIBFT..."
	@$(MAKE) -C   $(LIB_DIR)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIB_DIR)/$(LIB)

clean:
	@echo "cleaning objects"
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	@echo "cleaning executable"
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re