#include "../../include/minishell.h"

int	lexer(t_token **token_lst)
{
	if (!token_lst)
		return (1);
	if (lexical_analysis(token_lst))
		return (1);
	if (syntax_analysis(*token_lst))
		return (1);
	if (command_syntax_analysis(*token_lst))
		return (1);
	return (0);
}
