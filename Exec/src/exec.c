/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:08 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 10:29:17 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static void	wait_process(t_minishell *sh)
{
	int		status;
	int		i;

	i = 0;
	while (sh->forked && i < sh->to_exec->nb_cmd && sh->to_exec->all_cmd)
	{
		if (sh->to_exec->all_cmd[i])
		{
			waitpid(sh->to_exec->all_cmd[i]->pid, &status, 0);
			sh->to_exec->all_cmd[i]->ret = WEXITSTATUS(status);
			sh->last_ret = WEXITSTATUS(status);
			if (sh->to_exec->all_cmd[i]->input_fd > 1)
				close(sh->to_exec->all_cmd[i]->input_fd);
			if (sh->to_exec->all_cmd[i]->output_fd > 1)
				close(sh->to_exec->all_cmd[i]->output_fd);
		}
		i++;
	}
}

int	exec(t_minishell *sh)
{
	create_pipes(sh);
	assign_pipe(sh);
	update_path(sh);
	sh->forked = 1;
	if (!sh || !sh->to_exec || !sh->to_exec->all_cmd)
		return (1);
	exec_cmds(sh);
	close_pipes(sh);
	wait_process(sh);
	free(sh->pipes);
	sh->pipes = NULL;
	if (sh->to_exec->nb_cmd == 1 && g_cmd_running > 100)
		sh->last_ret = g_cmd_running;
	if (sh->to_exec->nb_cmd == 1 && g_cmd_running == 200)
		sh->last_ret = 1;
	if (sh->last_ret > 255)
		sh->last_ret = 0;
	return (sh->last_ret);
}
