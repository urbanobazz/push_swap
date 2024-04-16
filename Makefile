NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
HFILE = push_swap.h
LIBFTDIR = libft/
INCLUDE = -L ./libft -lft
OBJS = ${SRC:.c=.o}
SRC =	main.c\
		./moves/push.c\
		./moves/swap.c\
		./moves/rotate.c\
		./moves/rev_rotate.c\
		./input/input_check.c\
		./stack/make_stack.c\
		./stack/stack_utils.c\
		./stack/stack_index.c\
		./sort/big_sort.c\
		./sort/small_sort.c\


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) $(INCLUDE)

clean:
	rm -f $(OBJS)
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus
