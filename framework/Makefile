CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g3

NAME = libunit.a
NAME_BONUS = libunit_bonus.a

SRC_DIR_BONUS = src_bonus
SRC_DIR = src

OBJS_DIR = objs
OBJS_DIR_BONUS = objs_bonus

SRC = 	loader.c \
		launcher.c \
		launcher_parent_ps.c \
		launcher_child_ps.c \
		launcher_utils.c

SRC_BONUS = loader_bonus.c \
            launcher_bonus.c \
            launcher_parent_ps_bonus.c \
            launcher_child_ps_bonus.c \
            launcher_utils_bonus.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_BONUS))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJS_DIR_BONUS)/%.o, $(SRCS_BONUS))

all: libft $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

libft:
	make -C ../libft

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR_BONUS):
	@mkdir -p $(OBJS_DIR_BONUS)

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS_BONUS)

$(OBJS_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJS_DIR_BONUS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

clean_bonus:
	rm -rf $(OBJS_DIR_BONUS)

fclean_bonus: clean_bonus
	rm -f $(NAME_BONUS)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re libft