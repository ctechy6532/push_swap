# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctechy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 13:44:09 by ctechy            #+#    #+#              #
#    Updated: 2022/10/14 13:44:11 by ctechy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f
SRC =	srcs/main.c \
		srcs/check.c \
		srcs/utils_pile.c \
		srcs/operation_push.c \
		srcs/operation_reverse.c \
		srcs/operation_rotate.c \
		srcs/operation_swap.c \
		srcs/operation.c \
		srcs/pile_init.c \
		srcs/utils.c \
		srcs/simple.c \
		srcs/atoil.c \
		srcs/error.c \


OBJS = ${SRC:.c=.o}
LIBFT = make -C libft/
HEADER = -Iinclude -I./libft.h

.c.o :
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : ${OBJS}
		@$(LIBFT)
		@$(CC) $(OBJS) ./libft/libft.a -o $(NAME)
clean :
		@${RM} ${OBJS} libft/*.o
		@echo "clean all files *.o"

fclean : clean
		@${RM} ${NAME} libft/*.o libft/*.a
		@echo "clean libft.a"

re : fclean all

.PHONY : all clean fclean re
