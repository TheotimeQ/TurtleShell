/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_docs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:51:18 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 10:01:26 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	prompt_for_doc(t_sh *sh, char *end, int fd_in_pipe)
{
	char	*line;
	int		needswap;

	line = readline("> ");
	needswap = needswapenv(end);
	while (1)
	{
		if (ft_strlen(line) == ft_strlen(end))
		{
			if (ft_strncmp(line, end, ft_strlen(end)) == 0)
				return ;
		}
		if (fd_in_pipe > 0)
		{
			if (needswap)
				swap_env_doc(sh, &line);
			write(fd_in_pipe, line, ft_strlen(line));
			write(fd_in_pipe, "\n", 1);
		}
		line = readline("> ");
	}
}

static int	forking_h_docs(t_minishell *sh, t_list *lst, int fd_pipe[])
{
	int					pid;
	int					status;
	struct sigaction	action;

	pid = fork();
	g_cmd_running = 2;
	if (pid < 0)
		free_exit_sh(sh, 1);
	if (pid == 0)
	{
		catch_signal_hdoc(&action);
		prompt_for_doc(sh, (char *)lst->content, fd_pipe[1]);
		close(fd_pipe[1]);
		exit (0);
	}
	waitpid(pid, &status, 0);
	close(fd_pipe[1]);
	if (WEXITSTATUS(status) == 10)
	{
		g_cmd_running = 200;
		return (1);
	}
	g_cmd_running = 0;
	return (0);
}

static int	craftiness(t_minishell *sh, int stop, int fd_pipe[], t_list *lst)
{
	if (stop == 0)
		stop = forking_h_docs(sh, lst, fd_pipe);
	else
		close(fd_pipe[1]);
	if (stop)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		if (pipe(fd_pipe) == 1)
			free_exit_sh(sh, 1);
		close(fd_pipe[1]);
		sh->cmd->input_fd = fd_pipe[0];
	}
	return (stop);
}

static void	loop_on_docs(t_minishell *sh, t_cmd *cmd)
{
	t_list	*lst;
	int		nb_docs;
	int		i_doc;
	int		fd_pipe[2];
	int		stop;

	i_doc = 0;
	lst = cmd->hdoc;
	nb_docs = ft_lstsize(lst);
	stop = 0;
	while (lst != NULL)
	{
		if (cmd->hdocwon && i_doc == nb_docs - 1)
		{
			if (pipe(fd_pipe) == -1)
				free_exit_sh(sh, 1);
			cmd->input_fd = fd_pipe[0];
		}
		else
			fd_pipe[0] = -1;
		stop = craftiness(sh, stop, fd_pipe, lst);
		lst = (lst)->next;
		i_doc++;
	}
	return ;
}

void	here_docs(t_minishell *sh)
{
	int		i;

	if (!sh->to_exec)
		return ;
	if (!sh->to_exec->all_cmd)
		return ;
	i = 0;
	while (i < sh->to_exec->nb_cmd)
	{
		if (sh->to_exec->all_cmd[i])
		{
			sh->cmd = sh->to_exec->all_cmd[i];
			loop_on_docs(sh, sh->to_exec->all_cmd[i]);
		}
		i++;
	}
}
