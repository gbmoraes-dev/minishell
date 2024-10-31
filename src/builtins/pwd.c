#include "../../include/minishell.h"

int	my_pwd(t_token *token)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	ft_putstr_fd(pwd, token->fd_out);
	ft_putchar_fd('\n', token->fd_out);
	free(pwd);
	return (0);
}
