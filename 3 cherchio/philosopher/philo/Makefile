FLAGS:= -Wall -Werror -Wextra -pthread -g
CC:= cc

NAME:= philo

FUNCTIONS = src/main.c \
			src/atoi_itoa.c \
			src/parse_init.c \
			src/philo_utils.c \
			src/ft_dead.c \
			src/routine.c

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) -o $(NAME)


clean:
	rm -f $(FUNCTIONS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
