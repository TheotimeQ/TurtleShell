/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_docs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:01:00 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 12:05:44 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_cmd_running == 2)
		{
			rl_replace_line("", 0);
			write(1, "\n", 1);
			exit(10);
		}
	}
	if (signo == SIGQUIT)
	{
		if (g_cmd_running == 2)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

int	catch_signal_hdoc(struct sigaction *action)
{
	action->sa_handler = &sig_handler;
	action->sa_flags = SA_RESTART;
	if (sigaction(SIGINT, action, NULL) == -1)
		return (perror("Error : ctrl-C"), 0);
	if (sigaction(SIGQUIT, action, NULL) == -1)
		return (perror("Error : ctrl-/"), 0);
	return (1);
}
