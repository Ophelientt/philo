NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_PATH)

LIBFT_PATH = Libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

SRCS = monitor.c messages.c utils.c main.c initialisation.c free.c mutex.c philo.c\

OBJS = $(SRCS:.c=.o)

all: subsystems $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

subsystems:
	@make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re