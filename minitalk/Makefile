LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a

CC = cc
CCFLAGS = cc -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all:	$(SERVER) $(CLIENT)

$(SERVER): $(SRCS_SERVER) $(LIBFT_ARCHIVE)
		$(CC) $(CCFLAGS) -o $@ $(SRCS_SERVER) -L$(LIBFT_PATH) -lft

$(CLIENT): $(SRCS_CLIENT) $(LIBFT_ARCHIVE)
		$(CC) $(CCFLAGS) -o $@ $(SRCS_CLIENT) -L$(LIBFT_PATH) -lft

$(LIBFT_ARCHIVE):
		$(MAKE) -C $(LIBFT_PATH)

clean:
		$(MAKE) -C $(LIBFT_PATH) clean

fclean:	clean
		$(MAKE) -C $(LIBFT_PATH) fclean
		rm -f $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:	all clean fclean re
