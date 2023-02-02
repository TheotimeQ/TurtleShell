/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:51:55 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 10:14:20 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	check_args(t_minishell *sh, char **args)
{
	int		i;

	i = 1;
	while (i < ft_count_tab(args))
	{	
		if (i >= 2)
		{
			ft_printf(STDERR_FILENO, "exit\n");
			ft_printf(STDERR_FILENO, "🐢: exit: too many arguments\n");
			return (1);
		}
		if (!ft_isnum(args[i]))
		{
			ft_printf(STDERR_FILENO, "🐢: exit: %s", args[i]);
			ft_printf(STDERR_FILENO, ": numeric argument required\n");
			free_exit_sh(sh, 255);
		}
		i++;
	}
	return (0);
}

void	exec_exit(t_minishell *sh, t_cmd *cmd, char **args)
{
	if (ft_count_tab(args) == 1)
	{
		ft_printf(cmd->output_fd, "exit\n");
		free_exit_sh(sh, sh->last_ret);
	}
	if (ft_count_tab(args) == 2)
	{	
		if (ft_isnum(args[1]) && ft_strlen(args[1]) < 19)
		{
			ft_printf(cmd->output_fd, "exit\n");
			sh->last_ret = ft_atoi(args[1]);
			free_exit_sh(sh, ft_atoi(args[1]));
		}
		ft_printf(STDERR_FILENO, "🐢: exit: %s", args[1]);
		ft_printf(STDERR_FILENO, ": numeric argument required\n");
		free_exit_sh(sh, 255);
	}
	if (ft_count_tab(args) > 2)
	{
		cmd->ret = check_args(sh, args);
	}
}
