#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <locale.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

typedef struct s_token
{
	char			*content;
	unsigned int	type;
	int				fd_in;
	int				fd_out;
	int				exit_status;
	pid_t			pid;
	struct s_list	*env_lst;
	struct s_token	*head;
	struct s_token	*next;
}					t_token;

typedef struct s_position
{
	int				i;
	int				j;
}					t_position;

typedef enum e_token_type
{
	WORD = 1,
	PIPE = 2,
	REDIRECT_IN = 4,
	REDIRECT_OUT = 8,
	REDIRECT_FILE = 16,
	APPEND = 32,
	HEREDOC = 64,
}					t_token_type;

enum				e_builtin_type
{
	MY_ECHO = 256,
	MY_CD = 512,
	MY_PWD = 1024,
	MY_EXPORT = 2048,
	MY_UNSET = 4096,
	MY_ENV = 8192,
	MY_EXIT = 16384,
};

// LIST

t_list				*new_env_lst(void);
t_token				*new_token_node(void *token);
t_token				*last_token_in_lst(t_token *lst);
t_token				*new_token_lst(char *line, t_list *env_lst);
void				add_token_back(t_token **lst, t_token *new);
void				remove_empty_token_nodes(t_token **head);
void				clear_token_lst(t_token **lst, int reset);
void				token_lst_remove_if(t_token **head);
char				*find_env_in_lst(t_list *env_node, char *env);

// PARSER

int					find_next_quote(char *line);
int					validate_quotes(char *line);
char				*remove_quotes(char *line, int should_free);
int					tokenize(char *word, int previous_token_type);
int					lexical_analysis(t_token **token_lst);
int					syntax_analysis(t_token *token_lst);
int					command_syntax_analysis(t_token *token_lst);
int					pipe_syntax_analysis(t_token *token_lst);
int					redirect_syntax_analysis(t_token *token_lst);
int					lexer(t_token **token_lst);
int					parser(char *line, t_token **token_lst, t_list *env);

// EXPANDER

int					count_expanded_env_len(char *line, t_list *env);
int					validate_env_name(char *line);
int					count_env_name_len(char *line);
int					count_len_after_expansion(char *line, t_list *env);
void				expand_specific_env(char *line, char *expanded_line,
						t_position *position, t_list *env);
void				process_env_expansion(char *line, char *expanded_line,
						t_list *env);
char				*expander(char *line, t_list *env);

// BUILTINS

// EXECUTOR

// SIGNALS

void				set_sighandle(void);
void				sigint_handle(int signal);

// UTILS

char				*prompt(void);
int					count_word_len(char *line);
int					count_commands(t_token *node);
int					is_redirect(int token_type);
int					count_decimal(int n);

#endif
