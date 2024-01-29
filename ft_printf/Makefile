# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 13:31:48 by dde-alme          #+#    #+#              #
#    Updated: 2023/11/07 13:32:30 by dde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT		=	./libft/libft.a
LIBFTDIR	=	./libft

SRCS	= \
	ft_printf.c \
	ft_printchar.c \
	ft_formats.c \
	ft_printstr.c \
	ft_putstr.c \
	ft_print_hex.c \
       	ft_putchar_fd.c \
	ft_print_ptr.c \
	ft_printnbr.c \
	ft_printpercent.c \
	ft_itoa.c \
	ft_print_unsigned.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror
CC	= cc
RM	= rm -f
AR	= ar rcs

all:		$(NAME)

makelibft:
			@make -C $(LIBFTDIR)
			@cp $(LIBFT) .
			@mv $(LIBFT) $(NAME)

$(NAME):	makelibft $(OBJS)
			@$(AR) $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)
			@cd $(LIBFTDIR) && make clean

fclean:		clean
			@$(RM) $(NAME)
			@cd $(LIBFTDIR) && make fclean

re:			fclean all

.PHONY:		all clean fclean re
