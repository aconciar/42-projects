# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 14:36:14 by andrea            #+#    #+#              #
#    Updated: 2025/03/17 18:30:49 by aconciar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv
SRC_PATH = ./srcs
INCLUDES = -I./headers
VERBOSE = -D VERBOSE_MODE=1
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

SRCS = ${SRC_PATH}/CGI.cpp \
	${SRC_PATH}/main.cpp \
	${SRC_PATH}/Parser.cpp \
	${SRC_PATH}/ParserUtils.cpp \
	${SRC_PATH}/Request.cpp \
	${SRC_PATH}/Response.cpp \
	${SRC_PATH}/ResponseUtils.cpp \
	${SRC_PATH}/Router.cpp \
	${SRC_PATH}/Server.cpp \
	${SRC_PATH}/ServerUtils.cpp \
	${SRC_PATH}/ServerConfig.cpp \
	${SRC_PATH}/ServerManager.cpp 

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g ${INCLUDES}

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: ${NAME} generate_default_config 

generate_default_config:
	@if [ ! -f ./utils/configs/default_config.conf ]; then \
		echo "Generating default config file..."; \
		current_dir=$$(pwd); \
		utils="$$current_dir"; \
		echo "server {" 							> ./default_config.conf; \
		echo "	listen 			localhost:8080;" 	>> ./default_config.conf; \
		echo "	root 			$$utils;" 			>> ./default_config.conf; \
		echo "	directory_listing 	on;" 		>> ./default_config.conf; \
		echo "}" 									>> ./default_config.conf; \
	else \
		echo "Config file already exists."; \
	fi

${NAME}: ${SRCS}
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME} && \
	echo '${GREEN}  / _ \' && \
	echo '\_\(_)/_/' && \
	echo ' *//"\\*' && \
	echo ' /     \ ${NC}' || \
	(echo '${RED}  / _ \' && \
	echo '\_\(_)/_/' && \
	echo ' *//"\\*' && \
	echo ' /     \ ${NC}')

verbose: ${SRCS}
	@${CC} ${CFLAGS} ${VERBOSE} ${SRCS} -o ${NAME} && \
	echo "-- VERBOSE MODE --" && \
	echo '${GREEN}  / _ \' && \
	echo '\_\(_)/_/' && \
	echo ' *//"\\*' && \
	echo ' /     \ ${NC}' || \
	(echo '${RED}  / _ \' && \
	echo '\_\(_)/_/' && \
	echo ' *//"\\*' && \
	echo ' /     \ ${NC}')

valgrind: ${SRCS}
	${VALGRIND} ./${NAME} ./${F}

clean:
	@echo "Nothing to clean. No object files created."

fclean:
	@if [ -f ./default_config.conf ]; then \
		rm ./default_config.conf; \
	fi
	/bin/rm -f ${NAME}

re: fclean all

run: all
	clear && ./${NAME} ./${F}

.PHONY: all clean fclean re
