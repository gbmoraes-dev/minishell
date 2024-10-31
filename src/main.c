#include "../include/minishell.h"

// ---------------------------------------------------------------------------

/*

// TESTE TOKENIZAÇÃO

unsigned int	g_exit_status = 0;

static void	print_token_list(t_token *token_lst)
{
	printf("\n=== Token List ===\n");
	while (token_lst)
	{
		printf("Content: '%s'\n", token_lst->content);
		printf("Type: %d\n", token_lst->type);
		printf("-------------\n");
		token_lst = token_lst->next;
	}
}

int	main(void)
{
	char	*line;
	t_list	*env_lst;
	t_token	*token_lst;

	env_lst = new_env_lst();
	token_lst = NULL;
	signals_handler();
	while (1)
	{
		line = prompt(env_lst);
		if (!line)
		{
			ft_putstr_fd(RED "\nminishell: logging out\n" RESET, STDOUT_FILENO);
			break ;
		}
		add_history(line);
		if (validate_quotes(line))
		{
			printf("Error: Unclosed quotes\n");
			free(line);
			continue ;
		}
		token_lst = new_token_lst(line, env_lst);
		free(line);
		if (lexer(&token_lst))
		{
			clear_token_lst(&token_lst, 1);
			continue ;
		}
		print_token_list(token_lst);
		clear_token_lst(&token_lst, 1);
	}
	ft_lstclear(&env_lst, free);
	return (0);
}
*/

// ---------------------------------------------------------------------------

/*

// TESTE DE EXPANSÃO DE VARIÁVEIS DE AMBIENTE

unsigned int	g_exit_status = 0;

int	main(void)
{
	t_list	*env;
	char	*line;
	char	*expanded_line;

	env = new_env_lst();
	if (!env)
	{
		printf("Erro ao criar a lista de variáveis de ambiente.\n");
		return (1);
	}
	line = strdup("Hello $USER, welcome to $HOME!");
	expanded_line = expander(line, env);
	if (expanded_line)
	{
		printf("Resultado da Expansão 1: %s\n", expanded_line);
		free(expanded_line);
	}
	else
		printf("Erro na Expansão 1.\n");
	g_exit_status = 42;
	line = strdup("The last command exited with status $?");
	expanded_line = expander(line, env);
	if (expanded_line)
	{
		printf("Resultado da Expansão 2: %s\n", expanded_line);
		free(expanded_line);
	}
	else
		printf("Erro na Expansão 2.\n");
	line = strdup("Usuário \"$USER\" em '$HOME'!");
	expanded_line = expander(line, env);
	if (expanded_line)
	{
		printf("Resultado da Expansão 3: %s\n", expanded_line);
		free(expanded_line);
	}
	else
		printf("Erro na Expansão 3.\n");
	ft_lstclear(&env, free);
	return (0);
}
*/
