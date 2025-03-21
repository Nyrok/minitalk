# Compiler
CX = cc

# Compiler flags
CXFLAGS = -Wall -Wextra -Werror

NAME =		libftprintf.a
FILES = base_formatter.c \
		ft_printf.c \
		formatter.c \
		str_formatter.c \
		ptr_formatter.c

OBJS = ${FILES:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o:
	${CX} ${CXFLAGS} -I includes -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re