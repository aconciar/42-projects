# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:43:07 by aconciar          #+#    #+#              #
#    Updated: 2024/10/15 15:28:08 by aconciar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack

SRC = main.cpp

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
