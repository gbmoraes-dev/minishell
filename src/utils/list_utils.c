#include "../../include/minishell.h"

char	**convert_env_lst_to_array_matrix(t_list *env_lst)
{
	char	**matrix;
	int		i;
	int		matrix_len;

	matrix_len = ft_lstsize(env_lst);
	if (!matrix_len)
		return (NULL);
	matrix = ft_calloc(matrix_len + 1, sizeof(char *));
	matrix[matrix_len] = NULL;
	i = 0;
	while (env_lst)
	{
		matrix[i] = ft_strdup(env_lst->content);
		if (!matrix[i])
		{
			destroy_matrix(matrix);
			return (NULL);
		}
		env_lst = env_lst->next;
		i++;
	}
	return (matrix);
}
