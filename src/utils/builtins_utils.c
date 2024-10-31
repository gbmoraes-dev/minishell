#include "../../include/minishell.h"

int	update_env(t_list *env_lst, char *key, char *new_value)
{
	while (env_lst)
	{
		if (ft_strncmp(key, env_lst->content, ft_strlen(key)) == 0)
		{
			free(env_lst->content);
			env_lst->content = ft_strjoin(key, new_value);
			if (!env_lst->content)
				return (1);
		}
		env_lst = env_lst->next;
	}
	return (0);
}

int	validate_arguments(t_token *token)
{
	return (token && token->next && token->next->type == WORD &&
			token->next->next && token->next->next->type == WORD);
}

int	is_valid_numeric_string(char *s)
{
	if (!s || *s == '-')
		return (2);
	if (*s == '+')
		s++;
	if (!*s)
		return (1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

void	destroy_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

char	**convert_commands_to_array_matrix(t_token *token)
{
	t_token			*aux;
	char			**mat;
	unsigned int	mat_positions;
	unsigned int	i;

	if (!token)
		return (NULL);
	aux = token;
	i = -1;
	mat_positions = 0;
	while (aux && aux->type == WORD)
	{
		aux = aux->next;
		mat_positions++;
	}
	mat = ft_calloc(mat_positions + 1, sizeof(char *));
	if (!mat)
		return (NULL);
	while (++i < mat_positions)
	{
		mat[i] = ft_strdup(token->content);
		token = token->next;
	}
	return (mat);
}
