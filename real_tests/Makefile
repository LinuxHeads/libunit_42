CC     = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR   = ../libft
LIBUNIT_DIR = ../framework

NAME =  project_tests

SRCS = main.c \
	   ft_isdigit/00_launcher.c \
	   ft_isdigit/01_char_test.c \
	   ft_isdigit/02_null_test.c \
	   ft_isdigit/03_digit_test.c \
	   ft_isdigit/04_special_char_test.c \
	   ft_isalpha/00_launcher.c \
	   ft_isalpha/01_char_test.c \
	   ft_isalpha/02_null_test.c \
	   ft_isalpha/03_digit_test.c \
	   ft_isalpha/04_special_char_test.c \
	   ft_split/00_launcher.c \
	   ft_split/01_basic_test.c \
	   ft_split/02_null_test.c \
	   ft_split/03_empty_string.c \
	   ft_split/04_string_of_spaces.c \
	   ft_strcmp/00_launcher.c \
	   ft_strcmp/01_identical_string_test.c \
	   ft_strcmp/02_empty_string_test.c \
	   ft_strcmp/03_non_equal_strings.c \
	   ft_strcmp/04_non_equal_strings_2.c \
	   ft_atoi/00_launcher.c \
	   ft_atoi/01_basic_test.c \
	   ft_atoi/02_zero.c \
	   ft_atoi/03_min_int.c \
	   ft_atoi/04_max_int.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR)/includes -I$(LIBUNIT_DIR)/include

LIBS = $(LIBUNIT_DIR)/libunit.a $(LIBFT_DIR)/libft.a

all: $(NAME)

test: all
	@./$(NAME)

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

.PHONY: all clean fclean re test
