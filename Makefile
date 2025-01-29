CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_check.c	ft_free.c	ft_push_stack.c	ft_range.c	ft_retate.c	ft_reverse_retate.c	ft_split.c \
		ft_swap.c	helpers.c	parsing.c	pos_value.c	push_swap.c
OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# %.o:
# 	@$(CC) $(CFLAGS) -c $*.c

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
