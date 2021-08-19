# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 20:00:48 by gpaul             #+#    #+#              #
#    Updated: 2021/08/19 20:35:43 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCSDIR = srcs
OBJSDIR = .objs
SRCS =	main.c		\
		utils.c		\
		ft_split.c		\
		ft_putstr_fd.c	\
		copy_map.c	\
		map_init.c	\
		check_map.c	\
		text_init.c	\
		initial_render.c	\
		key_press.c			\
		move_rend.c			\
		update_rend.c		\
		free_alloc.c

OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DPDCS = $(OBJS:.o=.d)
INCLUDES = -I includes/ -I mlx/
CFLAGS = -Wall -Wextra -Werror -flto -O2 -march=native
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

-include $(DPDCS)

$(NAME) : $(LIB) $(OBJS) 
	@(gcc $(MLX) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME))

$(LIB) :
	$(MAKE) -C mlx

$(OBJSDIR)/%.o : $(SRCSDIR)/%.c | $(OBJSDIR)
	@(echo "Compiling -> $^")
	@(gcc $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@)

$(OBJSDIR) :
	@(mkdir -p .objs)

clean :
	@(rm -f $(NAME))
	$(MAKE) clean -C mlx

fclean : clean
	@(rm -rf $(OBJSDIR))
re : fclean all

fg : $(LIB) $(OBJS)
	@(gcc $(MLX) $(CFLAGS) -g3 -fsanitize=address $(OBJS) $(LIB) $(MLX_COMP) $(INCLUDES)  -o $(NAME) )
