/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:43:01 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 10:28:16 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static void	sig_quit(int signo)
{
	if (signo == SIGQUIT)
	{
		if (g_cmd_running == 0)
		{
			rl_on_new_line();
			rl_redisplay();
		}
		if (g_cmd_running == 1)
		{
			rl_replace_line("", 0);
			write(1, "^\\Quit: 3\n", 10);
			g_cmd_running = 131;
		}
	}
}

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_cmd_running == 0)
		{
			rl_replace_line("", 0);
			write(1, "\n", 1);
			rl_on_new_line();
			rl_redisplay();
		}
		if (g_cmd_running == 1)
		{
			rl_replace_line("", 0);
			write(1, "^C\n", 3);
			g_cmd_running = 130;
		}
	}
	sig_quit(signo);
}

int	catch_signal(struct sigaction *action)
{
	action->sa_handler = &sig_handler;
	action->sa_flags = SA_RESTART;
	if (sigaction(SIGINT, action, NULL) == -1)
		return (perror("Error : ctrl-C"), 0);
	if (sigaction(SIGQUIT, action, NULL) == -1)
		return (perror("Error : ctrl-/"), 0);
	return (1);
}
