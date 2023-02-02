/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:52:01 by tquere            #+#    #+#             */
/*   Updated: 2023/01/13 16:38:31 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	exec_env(t_minishell *sh, t_cmd *cmd, char **args)
{
	if (ft_count_tab(args) > 2)
	{
		ft_printf(STDERR_FILENO, "🐢: env: too many arguments\n");
		cmd->ret = 1;
		return ;
	}
	env_print(sh->env_var, cmd);
	cmd->ret = 0;
}
