NAME		= push_swap

PRINTF_PATH	= libraries/ft_printf/
PRINTF_NAME	= libftprintf.a
PRINTF		=	$(PRINTF_PATH)$(PRINTF_NAME)

LIBFT_PATH	= libraries/ft_printf/libft/
LIBFT_NAME	= libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

INC		= -I ./includes/\
		  -I ./$(PRINTF_PATH)\
		  -I ./$(LIBFT_PATH)

SRC_DIR		= src/
OBJ_DIR		= obj/

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f

COMMANDS_DIR	= $(SRC_DIR)commands/push.c \
		  	$(SRC_DIR)commands/rev_rotate.c \
		  	$(SRC_DIR)commands/rotate.c \
		  	$(SRC_DIR)commands/sort_stacks.c \
		  	$(SRC_DIR)commands/sort_three.c \
		  	$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR	= $(SRC_DIR)push_swap/handle_errors.c \
		  	$(SRC_DIR)push_swap/init_a_to_b.c \
		  	$(SRC_DIR)push_swap/init_b_to_a.c \
		  	$(SRC_DIR)push_swap/push_swap.c \
		  	$(SRC_DIR)push_swap/split.c \
		  	$(SRC_DIR)push_swap/stack_init.c \
		  	$(SRC_DIR)push_swap/stack_utils.c

SRC		= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJ		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all:		$(PRINTF) $(LIBFT) $(NAME)

$(PRINTF):
			@echo "Making printf..."
			@make -sC $(PRINTF_PATH)

$(LIBFT):
			@echo "Making libft..."
			@make -sC $(LIBFT_PATH)

$(NAME):	$(OBJ) $(PRINTF) $(LIBFT)
			@echo "Compiling Push_Swap..."
			@$(CC) $(CFLAGS) $(INC) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)\
			-L$(PRINTF_PATH) -L$(LIBFT_PATH)
			@echo "Push_Swap ready!"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)
			@make clean -C $(PRINTF_PATH)
			@make clean -C $(LIBFT_PATH)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(PRINTF) $(LIBFT)

re:		fclean all

.PHONY:		all clean fclean re
