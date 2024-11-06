/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:58:03 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/06 15:31:16 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	char	*line;
	t_list	*env_lst;
	t_token	*token_lst;

	env_lst = new_env_lst();
	token_lst = NULL;
	signals_handler();
	while (1)
	{
		line = prompt(0);
		if (!line)
		{
			ft_putstr_fd(RED "\nminishell: logging out\n" RESET, STDOUT_FILENO);
			my_exit(&token_lst, &env_lst);
		}
		if (parser(line, &token_lst, env_lst))
		{
			clear_token_lst(&token_lst, 1);
			continue ;
		}
		exec(&token_lst, &env_lst, 0);
		wait_commands(token_lst);
		clear_token_lst(&token_lst, 1);
	}
	return (0);
}
