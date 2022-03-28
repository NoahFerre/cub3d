NAME = cube
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = $(wildcard srcs/*.c) \
	$(wildcard srcs/parsing/*.c) \
	$(wildcard srcs/parsing/check/*.c) \
	$(wildcard srcs/utils/*.c)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I./libft -I./includes -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

./libft/libft.a:
	$(MAKE) -C ./libft bonus
	cp libft/libft.a $(NAME)

clean:
	$(MAKE) -C ./libft $@
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft $@
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re