/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:23:02 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 09:02:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	update_path(t_minishell *sh)
{	
	t_var	*var;

	if (!sh->env_var)
		return ;
	var = env_get(sh->env_var, "PATH");
	if (var && var->value)
	{	
		ft_free_tab(sh->path);
		sh->path = ft_split(var->value, ':');
		if (sh->path == NULL)
			free_exit_sh(sh, 1);
	}
	else
		sh->path = NULL;
}

void	get_path(t_minishell *sh, char **envp)
{	
	if (!envp)
		return ;
	if (!*envp)
		return ;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	sh->path = ft_split(*envp + 5, ':');
	if (sh->path == NULL)
		free_exit_sh(sh, 1);
}

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*command;

	if (paths == NULL)
		return (NULL);
	while (*paths)
	{
		command = ft_strjoin(*paths, "/");
		command = ft_strjoin(command, cmd);
		if (!access(command, 0))
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
