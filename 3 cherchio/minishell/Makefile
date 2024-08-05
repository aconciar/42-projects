NAME		= minishell
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
CPPFLAGS	= -Iinclude -Ilibft
LDFLAGS		= -Llibft
LINKS		= -lft -lm -lpthread -lreadline
RM			= rm -f
MAKEFLAGS   := --no-print-directory

LIBFT		= libft/libft.a

SRC_DIR		= src
OBJ_DIR		= .dir
SRCS		:= main.c \
				parcing/ft_syntax_error.c \
				parcing/ft_split_cmd.c \
				parcing/ft_new_word.c \
				parcing/ft_open_quotes.c \
				parcing/ft_expand.c \
				parcing/ft_tokenize_mini.c \
				parcing/ft_tokenize.c \
				parcing/ft_tokenize_utils.c \
				parcing/ft_is_command.c \
				parcing/ft_fd.c \
				parcing/ft_parsing.c \
				builtins/ft_builtins.c \
				builtins/ft_builtins_no_process.c \
				builtins/ft_getenv.c \
				builtins/ft_setenv_unsetenv.c \
				builtins/ft_export_utils.c \
				builtins/ft_exit.c \
				builtins/ft_cd.c \
				builtins/ft_export.c \
				builtins/ft_unset.c \
				builtins/ft_echo.c \
				signal/ft_signal.c \
				execution/ft_command.c \
				execution/ft_execute_token.c \
				execution/ft_redirect.c \
				execution/ft_open_files.c \
				execution/ft_execute.c \
				execution/ft_create_cmd.c \
				execution/ft_path_functions.c \
				execution/ft_exec_pipe.c \
				execution/ft_exec_pipezero.c \
				utils/ft_utils.c \
				utils/ft_free_n_err.c \
				utils/ft_copy_envp.c \
				utils/ft_strcpy.c \
				list_functions/ft_create_node.c \
				list_functions/ft_list_addback.c \
				list_functions/ft_free_list.c \
				list_functions/ft_list_addfront.c \
				list_functions/ft_list_last.c \
				list_functions/ft_list_size.c \
				list_functions/ft_list_find_node.c \
				list_functions/ft_list_clear.c \
				list_functions/ft_listdel_one.c \

OBJS		:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJ_DIR)/, $(OBJS))

all: $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@[ -f $(LIBFT) ] || make -C libft/
	$(info ${BOLD}Creating  -> ${YELLOW}libft.a${NO_COLOR})
	$(CC) $(OBJS) $(LDFLAGS) $(CFLAGS) $(LINKS) -o $(NAME)
	echo "${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}"

valgrind: $(NAME)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes --suppressions=readline.supp ./$(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make clean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
.SILENT:

RED			:= ${shell tput setaf 1}
BLUE		:= ${shell tput setaf 4}
YELLOW		:= ${shell tput setaf 3}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}