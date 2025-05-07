# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrea <andrea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 14:53:14 by andrea            #+#    #+#              #
#    Updated: 2024/10/19 21:02:14 by andrea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC = main.cpp \
	RPN.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRC} -o ${NAME} && \
	echo "${GREEN}Compilation succeeded${NC}" && \
	echo '  (\,/)' && \
	echo '  oo   '"'"'//,        _' && \
	echo ',/_;~,        \,    / ' && \
	echo "\"'   \\    |    \\    !" && \
	echo "      ',|  \\    |__.'" && \
	echo "      '~  '~----''" || \
	echo "${RED}Compilation failed${NC}"

clean:
	@echo "Nothing to clean. No object files created."

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

