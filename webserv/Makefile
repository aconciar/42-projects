# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrea <andrea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 14:36:14 by andrea            #+#    #+#              #
#    Updated: 2025/01/04 14:08:51 by andrea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

SRCS = select.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: ${NAME}

${NAME}: ${SRCS}
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME} && \
	echo '${GREEN}  / _ \' && \
	echo '\_\(_)/_/' && \
	echo ' _//"\\_' && \
	echo '  /   \ ${NC}' || \
	(echo '${RED}  / _ \' && \
	echo '\_\(_)/_/' && \
	echo ' _//"\\_' && \
	echo '  /   \ ${NC}')

clean:
	@echo "Nothing to clean. No object files created."

fclean:
	rm -f ${NAME}

re: fclean all

run: all
	clear && ./${NAME}

.PHONY: all clean fclean re
