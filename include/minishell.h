/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:57:12 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/06 15:33:10 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				status;
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
	COMMAND = 1,
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
t_token				*new_token_lst(char *line, t_list *env_lst);
void				add_token_back(t_token **token_lst, t_token *new);
void				remove_empty_token_nodes(t_token **head);
void				clear_token_lst(t_token **token_lst, int reset);
void				token_lst_remove_if(t_token **head);
char				*find_env_in_lst(t_list *env_lst, char *env);
char				**find_env_node(t_list *env_lst, char *env);
void				remove_env_in_lst(t_list **env_lst, char *key);

// PARSER

int					find_next_quote(char *line);
int					validate_quotes(char *line);
char				*remove_quotes(char *line, int should_free);
int					tokenize(char *command, int previous_token_type);
int					lexical_analysis(t_token **token_lst);
int					syntax_analysis(t_token *token_lst);
int					command_syntax_analysis(t_token *token_lst);
int					pipe_syntax_analysis(t_token *token_lst);
int					redirect_syntax_analysis(t_token *token_lst);
int					lexer(t_token **token_lst);
int					parser(char *line, t_token **token_lst, t_list *env_lst);

// EXPANDER

void				expand_specific_env(char *line, char *expanded_line,
						t_position *position, t_list *env_lst);
void				process_env_expansion(char *line, char *expanded_line,
						t_list *env_lst);
char				*expander(char *line, t_list *env_lst);

// BUILTINS

int					my_cd(t_token *token);
int					my_echo(t_token *token);
int					my_env(t_token *token);
void				my_exit(t_token **token, t_list **env_lst);
int					my_exit_pipe(t_token **token, t_list **env_lst);
int					my_export(t_token *token);
int					my_pwd(t_token *token);
int					my_unset(t_token *token, t_list **env_lst);

// EXECUTOR

int					redirect_in(t_token *token);
int					redirect_out(t_token *token);
int					heredoc(t_token *token);
int					make_redirect(t_token *token);
int					is_builtin(t_token *token);
int					find_pipe(t_token *token);
int					my_pipe(t_token *token);
int					exec_command(t_token *token, t_list *env_lst);
int					exec(t_token **token, t_list **env_lst, int should_clean);
char				*validate_exec(char *command, t_list *env_lst);
void				exec_piped_command(t_token *token, t_list *env_lst);
void				exec_whitout_pipe(t_token *token, t_list **env_lst);
void				exec_builtin(t_token *token, t_list **env_lst, int builtin);
t_token				*clean_redirections(t_token **token_lst, int should_clean);
void				exec_pipe(t_token *token, t_list **env_lst);
void				exec_pipe_builtin(t_token *token, t_list **env_lst,
						int builtin);
void				close_pipe(int *fd);
void				close_all_fd(t_token *token);

// SIGNALS

void				signals_handler(void);
void				sigint_handler(int signal);
int					is_after_prompt(int is_after);

// UTILS

int					count_expanded_env_len(char *line, t_list *env_lst);
int					validate_env_name(char *line);
int					count_env_name_len(char *line);
int					count_len_after_expansion(char *line, t_list *env_lst);
int					count_command_len(char *line);
int					count_commands(t_token *node);
int					is_redirect(int token_type);
int					count_decimal(int n);
int					update_env(t_list *env_lst, char *key, char *new_value);
int					validate_arguments(t_token *token);
void				destroy_matrix(char **matrix);
char				**convert_env_lst_to_array_matrix(t_list *env);
char				**convert_commands_to_array_matrix(t_token *token);
void				wait_commands(t_token *token);
void				close_sentece_fd(t_token *token);
t_token				*find_next_command(t_token *token);
t_token				**find_next_command_address(t_token *token);

// PROMPT

char				*prompt(int get_buffer);

#endif
