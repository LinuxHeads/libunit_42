CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I../framework/include -I. -g3
NAME    = tests

LIBUNIT = ../framework/libunit.a
LIBFT   = ../libft/libft.a

SRC     = 	main.c \
			lib/00_launcher.c \
			lib/01_success.c \
			lib/02_fail.c \
			lib/03_sigsev.c \
			lib/04_sigbus.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft
	make -C ../framework
	$(CC) $(CFLAGS) $(OBJ) $(LIBUNIT) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test
