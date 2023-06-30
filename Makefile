NAME := push_swap
SRCS_DIRS:= ./
SRCS := createlist.c \
			errors.c\
			list_utils.c\
			moves.c\
			moves3.c\
			order_stacks.c\
			order3.c\
			push_swap.c\
			search_stacks.c\
			sorting_utils.c\

INCLUDES := ./ft_printf/ft_printf.h
OBJS := ${SRCS:.c=.o}
GCC := gcc
FLAGS := -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJS)
	cd ft_printf && make
	$(GCC) $(FLAGS) $(SRCS) -ggdb -o $(NAME) -lftprintf  -lft  -L ./ft_printf/  -L ./ft_printf/libft/  -o $(NAME)

test:
	cd ft_printf && make
	$(GCC) $(FLAGS) $(SRCS) -ggdb -o $(NAME) -lftprintf  -lft  -L ./ft_printf/  -L ./ft_printf/libft/  -o $(NAME)

clean:
	rm -f $(OBJS)
	cd ft_printf && make clean

fclean: clean
	rm -f $(NAME)
	cd ft_printf && make fclean

re: fclean all
