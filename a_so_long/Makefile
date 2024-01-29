# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 12:14:21 by dde-alme          #+#    #+#              #
#    Updated: 2024/01/22 12:07:56 by dde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH	=	./libraries/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX	=	$(MINILIBX_PATH)/libmlx.a

SRC_FILES	=	so_long.c \

SRC_DIR		=	sources

HEADER		=	$(SRC_DIR)/so_long.h

SOURCES		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJECTS		=	$(SOURCES:.c=.o)

NAME		=	so_long

CC		=	cc
RM		=	rm -f

CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L. -lXext -L. -lX11

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


all: 		$(NAME)

$(NAME):	$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):			
			$(MAKE) -C $(MINILIBX_PATH)

clean:
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MINILIBX_PATH) clean
			$(RM) $(OBJECTS)

fclean:		clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re libft minilibx
