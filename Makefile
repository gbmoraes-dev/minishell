NAME = minishell

SRCS =	main.c utils/parser_utils.c utils/expander_utils.c
SRCS += parser/parser.c parser/lexer.c parser/analyzer.c
SRCS += parser/quotes.c parser/tokenize.c list/env_lst.c
SRCS += list/lst_clear.c list/node.c list/token_lst.c
SRCS += expander/expander.c

SRCS := $(addprefix ./src/, $(SRCS))

LIBFT_PATH = ./lib/libft

LIBFT = $(LIBFT_PATH)/libft.a

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

CPPFLAGS = -I /opt/homebrew/Cellar/readline/8.2.1/include

CPPFLAGS += -I ~/.brew/opt/readline/include

LDFLAGS += -L ~/.brew/opt/readline/lib

LIBFT_LINK = -L$(LIBFT_PATH) -lft

CPPFLAGS = -I /opt/homebrew/Cellar/readline/8.2.1/include

CPPFLAGS += -I ~/.brew/opt/readline/include

LDFLAGS += -L ~/.brew/opt/readline/lib

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lreadline $(CPPFLAGS) $(LDFLAGS) $(LIBFT_LINK)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)

re: clean all

.PHONY:
	all re clean fclean
