/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:51:57 by tquere            #+#    #+#             */
/*   Updated: 2023/01/13 19:43:59 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	go_to_path(t_minishell *sh, char *path, char **args)
{
	int		ret;
	char	current_pwd[PATH_MAX];

	if (ft_strlen(path) == 0)
		return (ERROR);
	if (path == NULL)
		return (0);
	if (getcwd(current_pwd, PATH_MAX) == NULL)
		return (ERROR);
	ret = chdir(path);
	if (ret < 0)
	{	
		ret *= -1;
		ft_printf(STDERR_FILENO, "🐢: cd: %s: %s\n", args[1], (strerror(errno)));
		return (ret);
	}
	else
	{
		env_add(&sh->env_var, "OLDPWD", current_pwd);
		if (getcwd(current_pwd, PATH_MAX) == NULL)
			return (ERROR);
		env_add(&sh->env_var, "PWD", current_pwd);
	}
	return (ret);
}

static int	go_to_home(t_minishell *sh, char **args)
{
	int		ret;
	t_var	*var;
	char	*path;

	var = env_get(sh->env_var, "HOME");
	if (var == NULL || var->value == NULL)
	{
		ft_printf(STDERR_FILENO, "🐢: cd: HOME not set\n");
		return (ERROR);
	}
	if (args[1])
	{
		path = ft_strjoin(var->value, args[1] + 1);
		ret = go_to_path(sh, path, args);
		free(path);
		return (ret);
	}
	path = var->value;
	ret = go_to_path(sh, path, args);
	return (ret);
}

static int	go_to_old_pwd(t_minishell *sh, t_cmd *cmd, char **args)
{
	t_var	*var;
	int		ret;
	char	current_pwd[PATH_MAX];

	var = env_get(sh->env_var, "OLDPWD");
	if (var == NULL || var->value == NULL )
	{
		ft_printf(STDERR_FILENO, "🐢: cd: OLDPWD not set\n");
		return (ERROR);
	}
	ret = go_to_path(sh, var->value, args);
	if (getcwd(current_pwd, PATH_MAX) == NULL)
		return (ret);
	ft_printf(cmd->output_fd, "%s\n", current_pwd);
	return (ret);
}

void	exec_cd(t_minishell *sh, t_cmd *cmd, char **args)
{	
	int		ret;

	if (cmd->ac > 2)
	{
		ft_printf(STDERR_FILENO, "🐢: cd: too many arguments\n");
		cmd->ret = 1;
		return ;
	}
	if (args[1] == NULL || ft_strncmp(args[1], "~", 1) == 0)
		ret = go_to_home(sh, args);
	else if (ft_strcmp(args[1], "-") == 0)
		ret = go_to_old_pwd(sh, cmd, args);
	else
		ret = go_to_path(sh, args[1], args);
	cmd->ret = ret;
	return ;
}
