CC     = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
LIBFT_DIR   = ../libft
LIBUNIT_DIR = ../framework

NAME = lib_tests

SRCS = main.c \
			lib/00_launcher.c \
			lib/01_success.c \
			lib/02_fail.c \
			lib/03_sigsev.c \
			lib/04_sigbus.c \
			lib/05_timeout.c \
			lib/06_sigfpe.c \
			lib/07_sigabrt.c \
			lib/08_sigill.c \
			lib/09_sigpipe.c \
			lib/10_output.c


OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR)/includes -I$(LIBUNIT_DIR)/include

LIBS = $(LIBUNIT_DIR)/libunit_bonus.a $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make bonus -C $(LIBUNIT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean_bonus -C $(LIBUNIT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean_bonus -C $(LIBUNIT_DIR)

re: fclean all


test: all
	@./$(NAME) -s $(subst , ,$(SKIP))

.PHONY: all clean fclean re test
