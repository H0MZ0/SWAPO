CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_check.c	ft_free.c	ft_push_stack.c	ft_range.c	ft_retate.c	ft_reverse_retate.c	ft_split.c \
		ft_swap.c	helpers.c	parsing.c	pos_value.c	push_swap.c ft_big_sort.c \
			bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
