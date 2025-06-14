NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = minishell.c \
		parser.c \
		lexer.c \
		utils.c \
		executer.c \
		expander.c \
		builtins.c \
		signal.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)  -lreadline

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re