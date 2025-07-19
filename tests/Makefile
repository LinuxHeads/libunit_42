CC     = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR   = ../libft
LIBUNIT_DIR = ../framework

NAME = lib_tests
NAME_BONUS = lib_tests_bonus

SRCS = main.c \
       lib/00_launcher.c \
       lib/01_success.c \
       lib/02_fail.c \
       lib/03_sigsev.c \
       lib/04_sigbus.c \

SRCS_BONUS = main.c \
			lib/00_launcher_bonus.c \
			lib/01_success.c \
			lib/02_fail.c \
			lib/03_sigsev.c \
			lib/04_sigbus.c \
			lib/05_timeout.c \
			lib/06_sigfpe.c \
			lib/07_sigabrt.c \
			lib/08_sigill.c \
			lib/09_sigpipe.c


OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR)/includes -I$(LIBUNIT_DIR)/include

LIBS = $(LIBUNIT_DIR)/libunit.a $(LIBFT_DIR)/libft.a

LIBS_BONUS = $(LIBUNIT_DIR)/libunit_bonus.a $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBUNIT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBUNIT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(LIBUNIT_DIR)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C $(LIBFT_DIR)
	@make bonus -C $(LIBUNIT_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES) $(LIBS_BONUS) -o $(NAME_BONUS)

clean_bonus:
	@rm -f $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@make clean_bonus -C $(LIBUNIT_DIR)

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean_bonus -C $(LIBUNIT_DIR)


re_bonus: fclean_bonus bonus

test: all
	@./$(NAME) -s $(subst , ,$(SKIP))

test_bonus: bonus
	@./$(NAME_BONUS) -s $(subst , ,$(SKIP))

.PHONY: all clean fclean re test bonus clean_bonus fclean_bonus re_bonus test_bonus
