CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = ft_check.c ft_free.c ft_push_stack.c ft_range.c ft_retate.c ft_reverse_retate.c ft_split.c \
      ft_swap.c helpers.c parsing.c pos_value.c ft_big_sort.c push_swap.c

BONUS_SRC = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c ft_check.c ft_free.c \
            ft_push_stack.c ft_range.c ft_retate.c ft_reverse_retate.c ft_split.c ft_swap.c \
            helpers.c parsing.c pos_value.c ft_big_sort.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
