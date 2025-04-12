# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrea <andrea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 15:16:09 by aconciar          #+#    #+#              #
#    Updated: 2024/11/03 11:19:16 by andrea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm

SRC = main.cpp \
		src/AForm.cpp \
		src/Bureaucrat.cpp \
		src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/PresidentialPardonForm.cpp \

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
