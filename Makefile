# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 20:00:48 by gpaul             #+#    #+#              #
#    Updated: 2021/08/19 05:39:53 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/utils.c			\
		./srcs/ft_split.c		\
		./srcs/ft_putstr_fd.c	\
		./srcs/copy_map.c	\
		./srcs/map_init.c	\
		./srcs/check_map.c	\
		./srcs/text_init.c	\
		./srcs/initial_render.c	\
		./srcs/key_press.c			\
		./srcs/move_rend.c			\
		./srcs/update_rend.c		\
		./srcs/free_alloc.c

SRCS_MANDATORY = ./srcs/main.c \

OBJS 		= ${SRCS:.c=.o}
OBJS_M		= ${SRCS_MANDATORY:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
CC 			= gcc -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) ${OBJS_M}
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_M} $(FLAGS)
clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS} ${OBJS_M} ${OBJS_B}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re