/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:09 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 21:16:12 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	char			**matrix;
	unsigned int	positions;
	unsigned int	i;

	if (!token)
		return (NULL);
	aux = token;
	i = -1;
	positions = 0;
	while (aux && aux->type == COMMAND)
	{
		aux = aux->next;
		positions++;
	}
	matrix = ft_calloc(positions + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	while (++i < positions)
	{
		matrix[i] = ft_strdup(token->content, 0);
		token = token->next;
	}
	return (matrix);
}

char	**convert_env_lst_to_array_matrix(t_list *env)
{
	char	**matrix;
	int		size;
	int		i;

	size = ft_lstsize(env);
	if (!size)
		return (NULL);
	matrix = ft_calloc(size + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[size] = NULL;
	i = 0;
	while (env)
	{
		matrix[i] = ft_strdup(env->content, 0);
		if (!matrix[i])
		{
			destroy_matrix(matrix);
			return (NULL);
		}
		env = env->next;
		i++;
	}
	return (matrix);
}
