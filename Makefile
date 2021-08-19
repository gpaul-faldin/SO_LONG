# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/08/19 05:21:28 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/utils.c		\
		./srcs/copy_map.c	\
		./srcs/map_init.c	\
		./srcs/check_map.c	\
		./srcs/text_init.c	\
		./srcs/initial_render.c	\
		./srcs/key_press.c			\
		./srcs/move_rend.c			\
		./srcs/update_rend.c		\
		./srcs/free_alloc.c

SRCS_BONUS = 

SRCS_MANDATORY = ./srcs/main.c \

OBJS 		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_BONUS:.c=.o}
OBJS_M		= ${SRCS_MANDATORY:.c=.o}

UNAME		:= $(shell uname)


INCLUDES = -I includes/ -I libft/
LIB = -Llibft -lft
PATH_MLX	= mlx
CC 			= gcc -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) ${OBJS_M}
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(INCLUDES) -o ${OBJS_M} $(FLAGS)
$(LIB) :
	@(make -C libft)

bonus:		${OBJS} ${OBJS_B}
			make -C $(PATH_MLX)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_B} $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS} ${OBJS_M} ${OBJS_B}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re
