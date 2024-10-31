#include "../../include/minishell.h"

char	*prompt(t_list *env)
{
	const char	*user;
	char		*prompt;
	char		*line;
	int			len;

	user = find_env_in_lst(env, "USER");
	if (!user)
		user = "user";
	len = ft_strlen(GREEN) + ft_strlen(user) + ft_strlen("@minishell $> ")
		+ ft_strlen(RESET) + 1;
	prompt = (char *)malloc(len);
	if (!prompt)
		return (NULL);
	ft_strlcpy(prompt, GREEN, len);
	ft_strlcat(prompt, user, len);
	ft_strlcat(prompt, "@minishell $> ", len);
	ft_strlcat(prompt, RESET, len);
	line = readline(prompt);
	free(prompt);
	return (line);
}
