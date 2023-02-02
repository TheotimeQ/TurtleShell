/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:24 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/19 10:23:01 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static void	eof_caught(t_sh *sh)
{
	rl_clear_history();
	ft_putendl_fd("exit", 1);
	free_exit_sh(sh, sh->last_ret);
}

static void	line_parsing(t_sh *sh, char *line)
{
	if (ft_strlen(line) > 0)
	{
		if (check_syntax(line))
		{
			add_history(line);
			proc_parsing(sh, line);
		}
		else
			add_history(line);
	}
}

void	prompt_loop(t_sh *sh)
{
	char				*line;
	struct sigaction	action;

	if (!catch_signal(&action))
		free_exit_sh(sh, 0);
	while (1)
	{
		termios_init(sh);
		g_cmd_running = 0;
		line = readline("🐢> ");
		if (!line)
			eof_caught(sh);
		line_parsing(sh, line);
		free(line);
	}
}
