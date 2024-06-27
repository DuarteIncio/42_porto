# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 11:22:49 by dde-alme          #+#    #+#              #
#    Updated: 2024/06/05 10:59:28 by dde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	fractol

CC	=	cc
CCFLAGS	=	-Werror - Wextra -Wall

MLX_PATH	= libraries/minilibx-linux/
MLX_NAME	= libmlx_Linux.a
MLX		= 	$(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libraries/libft/
LIBFT_NAME	= libft.a
LIBFT		= 	$(LIBFT_PATH)$(LIBFT_NAME)

INC		= -I ./includes/\
		  -I ./$(LIBFT_PATH)\
		  -I ./$(MLX_PATH)

SRC_PATH	= src/
SRC		= main.c \
		  init.c \
		  render.c \
		  math_utils.c \
		  events.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all:	$(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@echo "Making MinilibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
		@echo "Compiling fractol..."
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC)\
		-L$(MLX_PATH) -lmlx_Linux -L$(LIBFT_PATH) -lft -lXext -lX11 -lm
		@echo "Fractol is ready!"

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) $(LIBFT_NAME)

re: fclean all

.PHONY:		all clean fclean re
