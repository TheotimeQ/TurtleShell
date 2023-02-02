/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:56:38 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 10:00:56 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	close_pipes(t_minishell *sh)
{
	int	i;

	i = 0;
	while (i < (sh->to_exec->nb_cmd - 1) * 2)
		close(sh->pipes[i++]);
}

void	create_pipes(t_minishell *sh)
{	
	int	id_pipe;
	int	fd_pipe;
	int	tmp;

	sh->pipes = malloc(sizeof(int) * (sh->to_exec->nb_cmd - 1) * 2);
	if (sh->pipes == NULL)
		free_exit_sh(sh, 1);
	id_pipe = 0;
	while (id_pipe < sh->to_exec->nb_cmd - 1)
	{	
		fd_pipe = pipe(sh->pipes + id_pipe * 2);
		if (fd_pipe == -1)
			free_exit_sh(sh, 1);
		tmp = sh->pipes[id_pipe * 2];
		sh->pipes[id_pipe * 2] = sh->pipes[id_pipe * 2 + 1];
		sh->pipes[id_pipe * 2 + 1] = tmp;
		id_pipe++;
	}
}

void	assign_pipe(t_minishell *sh)
{	
	int		id_cmd;
	t_cmd	*cmd;

	id_cmd = 0;
	while (id_cmd < sh->to_exec->nb_cmd && sh->to_exec->all_cmd)
	{	
		if (sh->to_exec->all_cmd[id_cmd])
		{
			cmd = sh->to_exec->all_cmd[id_cmd];
			if (0 < id_cmd && cmd->input_fd == 0)
				cmd->input_fd = sh->pipes[id_cmd * 2 - 1];
			if (id_cmd < sh->to_exec->nb_cmd - 1 && cmd->output_fd == 1)
				cmd->output_fd = sh->pipes[id_cmd * 2];
		}
		id_cmd++;
	}
}
