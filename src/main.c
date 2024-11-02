#include "../include/minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	char *line;
	t_list *env_lst;
	t_token *token_lst;

	env_lst = new_env_lst();
	token_lst = NULL;
	signals_handler();
	while (1)
	{
		line = prompt(env_lst);
		if (!line)
		{
			ft_putstr_fd(RED "\nminishell: logging out\n" RESET, STDOUT_FILENO);
			my_exit(&token_lst, &env_lst);
		}
		if (parser(line, &token_lst, env_lst))
		{
			clear_token_lst(&token_lst, 1);
			continue ;
		}
		exec(&token_lst, &env_lst, 0);
		wait_commands(token_lst);
		clear_token_lst(&token_lst, 1);
	}
	return (0);
}
