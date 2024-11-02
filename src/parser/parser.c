/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:02 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/01 22:07:03 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
