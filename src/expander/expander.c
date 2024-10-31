#include "../../include/minishell.h"

char	*expander(char *line, t_list *env)
{
	char	*expanded_line;

	expanded_line = ft_calloc(count_len_after_expansion(line, env) + 1,
								sizeof(char));
	if (!expanded_line)
		return (NULL);
	process_env_expansion(line, expanded_line, env);
	free(line);
	return (expanded_line);
}

void	process_env_expansion(char *line, char *expanded_line, t_list *env)
{
	t_position	position;
	char		should_expand;
	char		in_double_quotes;

	position = (t_position){0};
	should_expand = 1;
	in_double_quotes = 1;
	while (line[position.i])
	{
		if (line[position.i] == '\"' && should_expand)
			in_double_quotes ^= 1;
		if (line[position.i] == '\'' && in_double_quotes)
			should_expand ^= 1;
		if (line[position.i] == '$' && should_expand
			&& !validate_env_name(&line[position.i]))
			expand_specific_env(line, expanded_line, &position, env);
		else
		{
			expanded_line[position.j] = line[position.i];
			position.i++;
			position.j++;
		}
	}
	return ;
}

void	expand_specific_env(char *line, char *expanded_line,
		t_position *position, t_list *env)
{
	extern unsigned int	g_exit_status;
	char				*value;
	int					env_len;

	if (line[position->i + 1] == '?')
	{
		if (g_exit_status == 0)
			env_len = 1;
		else
			env_len = count_decimal(g_exit_status);
		value = ft_itoa(g_exit_status);
		ft_memcpy(&expanded_line[position->j], value, env_len);
	}
	else
	{
		value = ft_substr(&line[position->i], 1,
				count_env_name_len(&line[position->i]));
		env_len = ft_strlen(find_env_in_lst(env, value));
		ft_memcpy(&expanded_line[position->j], find_env_in_lst(env, value),
				env_len);
	}
	position->i += count_env_name_len(&line[position->i]) + 1;
	position->j += env_len;
	free(value);
	return ;
}
