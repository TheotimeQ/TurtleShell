/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:35:45 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 09:46:59 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	built_in(t_minishell *sh, t_cmd *cmd)
{	
	if (!cmd->av || !cmd->av[0])
	{
		cmd->ret = 0;
		return (1);
	}
	if (ft_strcmp("cd", cmd->av[0]) == 0)
		exec_cd(sh, cmd, cmd->av);
	else if (ft_strcmp("echo", cmd->av[0]) == 0)
		exec_echo(cmd, cmd->av);
	else if (ft_strcmp("env", cmd->av[0]) == 0)
		exec_env(sh, cmd, cmd->av);
	else if (ft_strcmp("exit", cmd->av[0]) == 0)
		exec_exit(sh, cmd, cmd->av);
	else if (ft_strcmp("export", cmd->av[0]) == 0)
		exec_export(sh, cmd, cmd->av);
	else if (ft_strcmp("pwd", cmd->av[0]) == 0)
		exec_pwd(cmd);
	else if (ft_strcmp("unset", cmd->av[0]) == 0)
		exec_unset(sh, cmd);
	else
		return (0);
	return (1);
}

static void	rebind_errno(t_cmd *cmd)
{
	if (errno == 13)
	{
		ft_printf(STDERR_FILENO, "🐢: %s: %s\n", cmd->av[0], (strerror(errno)));
		exit(126);
	}
	if (errno == 14)
	{
		ft_printf(STDERR_FILENO, "🐢: %s: command not found\n", cmd->av[0]);
		exit(127);
	}
	ft_printf(STDERR_FILENO, "🐢: %s: %s\n", cmd->av[0], (strerror(errno)));
}

static void	one_cmd(t_minishell *sh, t_cmd *cmd)
{
	char	*cmd_path;
	char	**env;

	dup2(cmd->input_fd, STDIN_FILENO);
	dup2(cmd->output_fd, STDOUT_FILENO);
	close_pipes(sh);
	cmd_path = get_cmd_path(sh->path, cmd->av[0]);
	env = env_to_str(sh->env_var);
	if (cmd_path == NULL)
	{	
		if (cmd->av[0][0] == '.' || cmd->av[0][0] == '/')
		{
			if (access(cmd->av[0], 0))
			{
				ft_printf(2, "🐢: %s: No such file or directory\n", cmd->av[0]);
				cmd->ret = 127;
				exit(127);
			}
			cmd_path = cmd->av[0];
		}
	}
	cmd->ret = execve(cmd_path, cmd->av, env);
	ft_free_tab(env);
	rebind_errno(cmd);
	exit(errno);
}

static void	exec_fork(t_minishell *sh)
{
	int		id_cmd;
	int		pid;

	id_cmd = 0;
	while (id_cmd < sh->to_exec->nb_cmd && sh->to_exec->all_cmd)
	{	
		if (sh->to_exec->all_cmd[id_cmd])
		{
			pid = fork();
			if (pid < 0)
				free_exit_sh(sh, 1);
			if (pid == 0)
			{
				if (built_in(sh, sh->to_exec->all_cmd[id_cmd]))
					exit(sh->to_exec->all_cmd[id_cmd]->ret);
				else
					one_cmd(sh, sh->to_exec->all_cmd[id_cmd]);
			}
			else
				sh->to_exec->all_cmd[id_cmd]->pid = pid;
		}
		id_cmd++;
	}
}

void	exec_cmds(t_minishell *sh)
{
	if (sh->to_exec->nb_cmd == 1 && sh->to_exec->all_cmd
		&& sh->to_exec->all_cmd[0] && built_in(sh, sh->to_exec->all_cmd[0]))
	{	
		sh->forked = 0;
		sh->last_ret = sh->to_exec->all_cmd[0]->ret;
		if (sh->to_exec->all_cmd[0]->input_fd > 1)
			close(sh->to_exec->all_cmd[0]->input_fd);
		if (sh->to_exec->all_cmd[0]->output_fd > 1)
			close(sh->to_exec->all_cmd[0]->output_fd);
		return ;
	}
	exec_fork(sh);
}
