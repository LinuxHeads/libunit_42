CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g3
# LINK = -L./libft -lft
NAME = libunit.a

SRC_DIR = src
OBJS_DIR = objs

SRC = loader.c launcher.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

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

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft