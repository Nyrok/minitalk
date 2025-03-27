# Définition des variables
CX = cc
CXFLAGS = -Wall -Wextra -Werror
SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER = server
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT = client
LIB_PRINTF = ft_printf/libftprintf.a
LIB_FT = libft/libft.a

all: $(SERVER) $(CLIENT)

$(LIB_PRINTF):
	make -C ft_printf

$(LIB_FT):
	make -C libft

$(SERVER): $(SERVER_OBJ) $(LIB_PRINTF)
	$(CX) $(CXFLAGS) $(SERVER_OBJ) -o $(SERVER) $(LIB_PRINTF)

$(CLIENT): $(CLIENT_OBJ) $(LIB_PRINTF) $(LIB_FT)
	$(CX) $(CXFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(LIB_PRINTF) $(LIB_FT)

%.o: %.c
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ)
	make clean -C ft_printf
	make clean -C libft

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(LIB_PRINTF)
	rm -f $(LIB_FT)

re: fclean all

.PHONY: all clean fclean re
