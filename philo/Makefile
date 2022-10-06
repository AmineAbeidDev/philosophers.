CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRC = utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_lstlast.c \
	utils/ft_lstnew.c utils/ft_lstsize.c utils/gear.c \
	utils/routine_gear.c utils/philosophers.c main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all