# Définition des variables
CX = cc
CXFLAGS = -Wall -Wextra -Werror
SRCS = server.c
OBJ = $(SRCS:.c=.o)
NAME = server
LIBFT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(LIBFT_PRINTF):
	make -C ft_printf

# Compilation du serveur
$(NAME): $(OBJ) $(LIBFT_PRINTF)
	$(CX) $(CXFLAGS) $(OBJ) -o $(NAME) $(LIBFT_PRINTF)

%.o: %.c
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
