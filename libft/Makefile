NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_strchr.c ft_strlen.c ft_strncmp.c ft_strcmp.c ft_strrchr.c ft_tolower.c \
		 ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c \
		 ft_memcmp.c ft_memmove.c ft_atoi.c ft_strlcpy.c ft_strlcat.c \
		 ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	 	 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
         ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
         ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
         ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
         ft_uitoa.c get_next_line_bonus.c get_next_line.c hitoa.c \
         utils1.c utils2.c ft_printf.c ft_atoi_base.c ft_remove_char.c \
         get_next_line_1.c

OFILES = $(addprefix obj/, $(SRCS:.c=.o))
DSRCS  =: $(addprefix srcs/, $(SRCS))

all: obj $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $?

obj/%.o : srcs/%.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

obj:
	@mkdir -p obj

clean:
	rm -rf $(OFILES)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
