NAME = minishell

SRCS =	main.c utils/parser_utils.c utils/expander_utils.c
SRCS += utils/prompt.c parser/parser.c parser/lexer.c
SRCS += parser/analysis.c parser/quotes.c parser/tokenize.c
SRCS += list/env_lst.c list/lst_clear.c list/node.c
SRCS += list/token_lst.c expander/expander.c signals/signal.c

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
