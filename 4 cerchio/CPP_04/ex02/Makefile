# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:08:05 by andrea            #+#    #+#              #
#    Updated: 2024/10/16 16:50:50 by aconciar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AAnimal

SRC = main.cpp \
	src/AAnimal.cpp \
	src/Dog.cpp \
	src/Cat.cpp \

OBJ = ${SRC:.cpp=.o}

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: ${NAME}

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}


${NAME}: ${OBJ}
		@${CC} ${CFLAGS} ${OBJ} -o ${NAME} && \
		echo "${GREEN}Compilation succeeded${NC}" && \
		echo '  (\,/)' && \
		echo '  oo   '"'"'//,        _' && \
		echo ',/_;~,        \,    / ' && \
		echo "\"'   \\    |    \\    !" && \
		echo "      ',|  \\    |__.'" && \
		echo "      '~  '~----''" || \
		echo "${RED}Compilation failed${NC}"

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
