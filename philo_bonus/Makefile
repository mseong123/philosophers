SRCS_NAME = philo_bonus ft_atoi ft_itoa philo_utils philo_utils2 init operations

SRCS = $(SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<	

$(NAME): $(OBJECTS)
	cc $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
