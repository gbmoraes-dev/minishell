/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:06 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 21:17:51 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
