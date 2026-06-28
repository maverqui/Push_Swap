# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorossel <jorossel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 12:13:18 by maeverqu          #+#    #+#              #
#    Updated: 2026/06/28 16:16:47 by jorossel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

SRCS	= srcs/core/compute_disorder.c \
		  srcs/core/main.c \
		  srcs/parsing/is_valid.c \
		  srcs/utils/utils.c \
		  srcs/utils/utils2.c \
		  srcs/algo/bubble_sort.c \
		  srcs/algo/chunk_sort.c \
		  srcs/algo/radix_sort.c \
		  srcs/operations/push.c \
		  srcs/operations/reverse_rotate.c \
		  srcs/operations/rotate.c \
		  srcs/operations/swap.c
		 
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
