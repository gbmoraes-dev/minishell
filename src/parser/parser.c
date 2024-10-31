#include "../../include/minishell.h"

int	parser(char *line, t_token **token_lst, t_list *env)
{
	int	status;

	status = 0;
	*token_lst = NULL;
	if (line[0])
		add_history(line);
	if (validate_quotes(line))
	{
		printf("Syntax error: There is an unclosed quote\n");
		free(line);
		return (-1);
	}
	*token_lst = new_token_lst(line, env);
	status = lexer(token_lst);
	free(line);
	return (status);
}
