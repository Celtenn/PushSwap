NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c \
			func.c \
			pushswap.c \
			quicksort_utils.c \
			quicksort.c \
			sort.c \
			rotate.c \
			rrotate.c \
			push.c \
			swap.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	@rm -f $(NAME) $(OBJS)

fclean : clean

re : fclean all

.PHONY: all clean fclean re