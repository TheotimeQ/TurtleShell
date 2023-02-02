/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:43:22 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 09:54:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	env_init_var(t_minishell *sh)
{	
	char	current_pwd[PATH_MAX];
	t_var	*var;

	if (getcwd(current_pwd, PATH_MAX) == NULL)
		return ;
	env_add(&sh->env_var, "PWD", current_pwd);
	var = env_get(sh->env_var, "OLDPWD");
	if (var)
		env_add(&sh->env_var, "OLDPWD", NULL);
	env_add(&sh->env_var, "_", "/usr/bin/env");
}

void	env_init(t_minishell *sh, t_var **var, char **envp)
{	
	int			i;
	t_var		*new_var;
	char		**var_split;	

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
	{	
		var_split = ft_split(envp[i], '=');
		new_var = malloc(sizeof(t_var));
		if (new_var == NULL || var_split == NULL)
		{
			ft_free_tab(var_split);
			free_exit_sh(sh, 1);
		}
		new_var->name = ft_strdup(var_split[0]);
		new_var->value = NULL;
		new_var->next = NULL;
		if (ft_count_tab(var_split) >= 2)
			new_var->value = ft_strdup(envp[i] + ft_strlen(var_split[0]) + 1);
		var_add_back(var, new_var);
		ft_free_tab(var_split);
		i++;
	}
}

void	env_print(t_var *var, t_cmd *cmd)
{
	if (var == NULL)
		return ;
	if (var->name && var->value)
		ft_printf(cmd->output_fd, "%s=%s\n", var->name, var->value);
	while (var->next != NULL)
	{	
		var = var->next;
		if (var->name && var->value)
			ft_printf(cmd->output_fd, "%s=%s\n", var->name, var->value);
	}
	return ;
}
